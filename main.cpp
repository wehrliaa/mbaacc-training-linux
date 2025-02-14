// main.cpp: Main file

#include "main.h"

// This was declared in process.h first.
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
	float FRAME_DURATION = 0.016;

	Save_State_Manager save_state;
	Game_State_Manager game_state;
	Action_Handler action_handler = Action_Handler(game_state, save_state);

	while (1) {
		// Espera até o jogo realmente começar
		while (global_frame_count == prev_frame_count) {
			global_frame_count = game_state.timer_check();
		}

		prev_frame_count = global_frame_count;

		if (global_frame_count <= 1) {
			; // coisa do frame display
		}

		high_precision_sleep(0.003);

		game_state.fetch_game_data();

		// 1. pegar estado do player 1
		// 2. pegar estado do player 2
		// 3. display game state com game_state, estado do p1 e p2, e frame
		// indicator

		action_handler.action_handle();

		high_precision_sleep(FRAME_DURATION);
	}

	return 0;
}
