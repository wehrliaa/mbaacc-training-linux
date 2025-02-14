// actionhandler.h: Input handling-related code

class Action_Handler {
public:
	Game_State_Manager game_state_obj;
	Save_State_Manager save_state_obj;
	bool f1_pressed_last_frame;
	bool f2_pressed_last_frame;
	bool is_pressed_key;
	bool is_save_flag;

	Action_Handler(
		Game_State_Manager game_state_obj,
		Save_State_Manager save_state_obj
	) {
		this->game_state_obj = game_state_obj;
		this->save_state_obj = save_state_obj;
		this->f1_pressed_last_frame = false;
		this->f2_pressed_last_frame = false;
		this->is_pressed_key = false;
		this->is_save_flag = false;
	}

	void
	action_handle() {
		// VAI TOMAR NO CU C++
		if (this->game_state_obj.game_mode_check() == 20) {
			printf("its 20\n");
			this->is_save_flag = false;
			return;
		}

		int fn1_button = this->game_state_obj.aFN1Key.read_memory(false);
		int fn2_button = this->game_state_obj.aFN2Key.read_memory(false);
		//int dmy_st = this->game_state_obj.aDummyState.read_memory(false);

		int is_f1_pressed = (fn1_button >= 1);

		// TODO: one day i'll fix dmy_st not being set to anything but i can't
		// be bothered
		//if ((fn2_button >= 1) && ((dmy_st == 5) || (dmy_st == -1))) { 
		if (fn2_button >= 1) {
			this->game_state_obj.game_reset();
			this->is_pressed_key = true;
		}

		if (is_f1_pressed && (!this->f1_pressed_last_frame)) {
			action_f1();
			this->is_save_flag = true;
			this->is_pressed_key = true;
		}

		this->f1_pressed_last_frame = is_f1_pressed;

		if (
			(this->game_state_obj.timer_check() == 1) &&
			(this->is_save_flag == true)
		) {
			this->action_f2();
		}
		
		if ((!is_f1_pressed) && this->is_pressed_key) {
			this->is_pressed_key = false;
			this->game_state_obj.play();
		}
	}

	void
	action_f1() {
		this->save_state_obj.save();
		this->game_state_obj.pause();
	}

	void
	action_f2() {
		this->save_state_obj.load();
		this->game_state_obj.comb_after_timer_reset();
	}
};
