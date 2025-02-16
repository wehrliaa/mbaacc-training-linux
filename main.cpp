// main.cpp: Main file

#include "main.h"

// This was declared in process_handling.h first.
struct Process gProc = wait_process("MBAA.exe");

int
main() {
	int prev_frame_count = 0;
	int global_frame_count = 0;

	Save_State_Manager save_state;
	Game_State_Manager game_state;
	Action_Handler action_handler = Action_Handler(game_state, save_state);

	while (1) {
		game_state.fetch_game_data();

		if (game_state.aGameMode.int_data == 20) {
			action_handler.is_save_flag = false;
		}

		// Everything below this chunk of code is synced with the game's
		// framerate.
		global_frame_count = game_state.timer_check();
		if (global_frame_count == prev_frame_count)
			continue;

		prev_frame_count = global_frame_count;

		action_handler.action_handle();
	}

	return 0;
}
