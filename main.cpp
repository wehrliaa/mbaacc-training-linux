// main.cpp: Main file

#include "main.h"

// This was declared in process_handling.h first.
struct Process gProc = wait_process("MBAA.exe");

// Copied from
// https://blat-blatnik.github.io/computerBear/making-accurate-sleep-function/
void
high_precision_sleep(double seconds) {
    using namespace std;
    using namespace std::chrono;

    static double estimate = 5e-3;
    static double mean = 5e-3;
    static double m2 = 0;
    static int64_t count = 1;

    while (seconds > estimate) {
        auto start = high_resolution_clock::now();
        this_thread::sleep_for(milliseconds(1));
        auto end = high_resolution_clock::now();

        double observed = (end - start).count() / 1e9;
        seconds -= observed;

        ++count;
        double delta = observed - mean;
        mean += delta / count;
        m2   += delta * (observed - mean);
        double stddev = sqrt(m2 / (count - 1));
        estimate = mean + stddev;
    }

    // spin lock
    auto start = high_resolution_clock::now();
    while ((high_resolution_clock::now() - start).count() / 1e9 < seconds);
}

int
main() {
	int prev_frame_count = 0;
	int global_frame_count = 0;
	int FRAME_DURATION = 0.016;

	Save_State_Manager save_state;
	Game_State_Manager game_state;
	Action_Handler action_handler = Action_Handler(game_state, save_state);

	while (1) {
		// Sync with game's internal frame counter
		while (global_frame_count == prev_frame_count) {
			global_frame_count = game_state.timer_check();
		}

		prev_frame_count = global_frame_count;

		game_state.fetch_game_data();
		action_handler.action_handle();
	}

	return 0;
}
