#include "SDLL.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


void getSDLerror(ostream& os, string& msg, bool fatal) { //bao loi
	os << msg << " Error: " << SDL_GetError() << endl;
	if (fatal) {
		SDL_Quit();
		exit(1);
	}
}
Mouse* mouse;
Butt* start_button;
Butt* option_button;
Butt* exit_button;
Butt* ok_button;
Butt* play_again_button;
Butt* turn_off_button;
Butt* sound_effect_setting_button;
Butt* background_music_setting_button;
Butt* back_button;
Butt* pause_button;
Butt* high_score_button;
Butt* return_button;
Butt* all_in_button;
Butt* easy;
Butt* normal;
Butt* hard;
Butt* plant_topic;
Butt* color_topic;
Butt* weather_topic;
Butt* normal_mode;
Butt* timer_mode;
Gameobject* background_pic;
Gameobject* congratulation;
Gameobject* wasted;
Gameobject* title;
Gameobject* text_box_empty;
Gameobject* model;
Gameobject* model_0[6];
Gameobject* high_score;
Gameobject* setting;
Gameobject* lois;
Gameobject* brian;
Gameobject* stewie;
Gameobject* stewie_2;
Hangman* new_game;
Music* background_music;
Music* button_sound_effect;
Music* lose_sound_effect;
Music* win_sound_effect;
SDL_Renderer* Game::renderer = NULL;
Text* welcome;
Text* text_box;
Text* Ask_name;
Text* warning;
Text* timer;
Text* Game_mode;
Text* guessed_list;
Text* Topic;
Text* difficulty;
Timer* mTimer;
Text* leader_board[6];
Text* hint;
Text* all_in_text;
bool state_0 = true;
bool state_0_5 = false;
bool state_1 = false;
bool state_1_5 = false;
bool state_1_6 = false;
bool state_1_7 = false;
bool state_2 = false;
bool state_2_0 = false;
bool state_2_5 = false;
bool state_3 = false;
bool state_3_5 = false;
void Game::initSDL() { //khoi tao cua so
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { //bao loi khoi tao
		string x = "SDL_Init";

		getSDLerror(cout, x, true);
	}
	
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		string x = "Mixer_init";
		cout << x << ": " << Mix_GetError();
	}
	if (TTF_Init() == -1) {
		string x = "TTF_init";
		cout << x << ": " << TTF_GetError();
		SDL_Quit();
		exit(1);
	}
	string y = "Hangman";
	window = SDL_CreateWindow(y.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //tao cua so voi ten hangman
	if (window == NULL) { //bao loi tao cua so
		string x = "CreateWindow";

		getSDLerror(cout, x, true);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //tao render
	if (renderer == NULL) { //bao loi tao render
		string x = "CreateRenderer";

		getSDLerror(cout, x, true);
	}

	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255); //cai dat mau 	
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// khoi tao object background
	background_pic = new Gameobject("hangman_background.png", 720, 1280, 0, 0);
	// khoi tao object tieu de
	title = new Gameobject("HangmanTitle.png", 120, 440, 1280 / 2 - 220, 230);

	// khoi tao object setting
	setting = new Gameobject("button_4.png", 600, 480, 1280 / 2 - 240, 720 / 2 - 300);

	// khoi tao object textbox
	text_box_empty = new Gameobject("textbox.png", 50, 600, 1280 / 2 - 300, 320);

	// khoi tao object chuc mung
	congratulation = new Gameobject("peter.png", 519, 314, 1280 / 2 - 314 / 2, 720 / 2 - 260);

	// khoi tao object chia buon
	wasted = new Gameobject("wasted.png", 350, 700, 1280 / 2 - 350, 720 / 2 - 350 / 2 - 100);

	//khoi tao object model
	model = new Gameobject("hinh0.png", 200, 300, 1280 / 4 - 200, 0);

	//khoi tao object highscore
	high_score = new Gameobject("leaderboard.png", 720, 720 / 1.44, 1280 / 2 - 720 / 2.88, 0);

	//khoi tao object lois
	lois = new Gameobject("lois.png", 500, 500 * 1.53, 1280 / 2 + 100, 780 / 2 - 231);

	//khoi tao object brian
	brian = new Gameobject("brian.png", 400 * 1.1, 400, 150, 780 / 2 - 100);

	//khoi tao object stewie
	stewie = new Gameobject("stewie.png", 350, 350 * 1.37, 475, 780 / 2 +50);

	//khoi tao object stewie 2.0;
	stewie_2 = new Gameobject("stewie_2.png", 350, 350 * 1.37, 475, 780 / 2 + 50);

	//khoi tao 6 object model con lai
	model_0[0] = new Gameobject("hinh1.png", 100, 100, 1280 / 4 - 300 + 128, 720 / 2 - 160);
	model_0[1] = new Gameobject("hinh2.png", 100, 200, 1280 / 4 - 300 + 128, 720 / 2 - 160);
	model_0[2] = new Gameobject("hinh3.png", 200, 200, 1280 / 4 - 300 + 128, 720 / 2 - 160);
	model_0[3] = new Gameobject("hinh4.png", 200, 200, 1280 / 4 - 300 + 128, 720 / 2 - 160);
	model_0[4] = new Gameobject("hinh5.png", 300, 200, 1280 / 4 - 300 + 128, 720 / 2 - 160);
	model_0[5] = new Gameobject("hinh6.png", 300, 200, 1280 / 4 - 300 + 128, 720 / 2 - 160);

	// khoi tao phim start
	start_button = new Butt(40, 110, 0, 240, 60, 220, 1280 / 2 - 110, 400, "button.jpg");

	//khoi tao phim option
	option_button = new Butt(40, 110, 0, 350, 60, 220, 1280 / 2 - 110, 460, "button.jpg");

	//khoi tao phim ok
	ok_button = new Butt(250, 750, 90, 100, 60, 200, 743, 315, "button_1.png");

	// khoi tao phim exit
	exit_button = new Butt(40, 110, 0, 425, 60, 220, 1280 / 2 - 110, 520, "button.jpg");

	// khoi tao phim dieu chinh nhac nen
	background_music_setting_button = new Butt(190, 600, 806, 0, 50, 150, 620, 255, "yes_no_button.png");

	// khoi tao phim pause
	pause_button = new Butt(415, 415, 0, 0, 75, 75, 1190, 10, "pause_button.png");

	//khoi tao phim xem diem cao
	high_score_button = new Butt(100, 120, 30, 150, 100, 120, 1280 / 2 + 90, 575, "button_2.png");

	// khoi tao phim dieu chinh hieu ung am thanh
	sound_effect_setting_button = new Butt(190, 600, 806, 0, 50, 150, 620, 375, "yes_no_button.png");

	// khoi tao phim tro lai khi xem leaderboard
	return_button = new Butt(190, 600, 806, 0, 50, 150, 1280 / 2 - 75, 675, "yes_no_button.png");

	// khoi tao phim tro lai
	back_button = new Butt(170, 384, 0, 0, 142, 320, 1280 / 2 - 152, 448, "back_button.png");

	// khoi tao phim choi lai
	play_again_button = new Butt(100, 120, 30, 150, 100, 120, 1280 / 2 - 150, 575, "button_2.png");

	// khoi tao phim tat game sau khi choi xong
	turn_off_button = new Butt(100, 120, 30, 50, 100, 120, 1280 / 2 - 30, 585, "button_2.png");

	// khoi tao phim all_in
	all_in_button = new Butt(100, 120, 30, 175, 125, 125 * 1.3, 475 + 225, 780 / 2 + 160, "yes_no_button.png");

	//khoi tao phim easy
	easy = new Butt(1030, 1030, 0, 0, 300, 300, 100, 300, "diff.png");

	//khoi tao phim normal
	normal = new Butt(1030, 1030, 1280, 0, 300, 300, 500, 300, "diff.png");

	//khoi tao phim hard
	hard = new Butt(1030, 1030, 2530, 0, 300, 300, 900, 300, "diff.png");

	//khoi tao phim chu de 
	plant_topic = new Butt(1030, 1030, 0, 0, 300, 300, 100, 300, "topic.png");

	//khoi tao phim chu de
	weather_topic = new Butt(1030, 1030, 1280, 0, 300, 300, 500, 300, "topic.png");

	//khoi tao chu de
	color_topic = new Butt(1030, 1030, 2530, 0, 300, 300, 900, 300, "topic.png");

	//khoi tao phim chon che do choi
	normal_mode = new Butt(1032, 1032, 0, 0, 300, 300, 1280 / 2 - 350, 300, "game_mode.png");

	//khoi tao phim chon che do choi
	timer_mode = new Butt(1032, 1032, 1247, 0, 300, 300, 1280 / 2 + 50, 300, "game_mode.png");

	// khoi tao text
	text_box = new Text("zh-cn.ttf",30);
	SDL_StartTextInput();

	//khoi tao text welcome
	SDL_Color WHITE_COLOR = { 255, 255, 255 , 255 };
	welcome = new Text("zh-cn.ttf", 50, "Welcome to hangman!", WHITE_COLOR);

	//khoi tao text canh bao
	SDL_Color RED_COLOR = { 255, 0, 0 , 255 };
	warning = new Text("zh-cn.ttf", 15, "Your name can't be longer than 20 characters", RED_COLOR);

	//khoi tao text do kho
	SDL_Color BLUE_COLOR = { 119,225,255,255 };
	difficulty = new Text("zh-cn.ttf", 30, "select difficulty", WHITE_COLOR);

	//khoi tao text danh sach nhung ki tu da doan
	guessed_list = new Text("zh-cn.ttf", 20);

	//khoi tao text chon che do choi
	Game_mode = new Text("zh-cn.ttf", 30, "choose your topic", WHITE_COLOR);

	//khoi tao text chon do kho
	Topic = new Text("zh-cn.ttf", 30, "choose your topic", WHITE_COLOR);

	//khoi tao text hoi ten
	
	Ask_name = new Text("zh-cn.ttf", 20, "What's your name?", BLUE_COLOR);

	//khoi tao text all in
	all_in_text = new Text("zh-cn.ttf", 30);
	
	//khoi tao text hien thi goi y
	hint = new Text("zh-cn.ttf", 20);

	//khoi tao text leaderboard
	for (int i = 0; i < 6; i++) {
		leader_board[i] = new Text("zh-cn.ttf", 30);
	}

	//khoi tao text hien thi thoi gian
	timer = new Text("zh-cn.ttf", 30);

	//khoi tao chuot
	mouse = new Mouse();
	if (mouse == NULL) { //bao loi tao chuot
		string x = "CreateMouse";
		getSDLerror(cout, x, true);
	}

	//khoi tao nhac nen
	background_music = new Music("background music.mp3", 0);

	//khoi tao hieu ung  click button
	button_sound_effect = new Music("click music.mp3", 1);

	//khoi tao am thanh chien thang
	win_sound_effect = new Music("clap.wav", 1);

	//khoi tao am thanh thua cuoc
	lose_sound_effect = new Music("wasted.mp3", 1);
	//khoi tao game
	new_game = new Hangman();
	if (new_game == NULL) { //bao loi tao game moi
		string x = "Create new game";
		getSDLerror(cout, x, true);
	}
	//khoi tao bo dem thoi gian
	mTimer = Timer::Instance();

	//
	isrunning = true;
}
void Game::handle_event() {//xu ly event
	SDL_Event event;
	SDL_PollEvent(&event);
	static const unsigned char* keys = SDL_GetKeyboardState(NULL);
		
		switch (event.type) {
		case SDL_QUIT: //dong cua so
			isrunning = false;
			break;
		case SDL_KEYDOWN:
			if (state_1) {
				if (text_box->still_input) {
					if (event.key.keysym.sym == SDLK_BACKSPACE && text_box->name.size()) {
						text_box->name.pop_back();
					}
				}
			}
			if (state_2_0) {
				if (event.key.keysym.sym == SDLK_BACKSPACE && new_game->indicator > 0) {
					if (new_game->chosedWord[new_game->indicator - 1] == '_') {
						new_game->indicator--;
					}
					all_in_text->name[new_game->indicator-1] = '-';
					if(new_game->indicator >0)
					new_game->indicator--;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			if (state_0) {
				if (start_button->is_Selected) {
					cout << "clicked" << endl;
					button_sound_effect->play(0);
					state_1 = true;
					state_0 = false;
					start_button->is_Selected = false;
				}
				if (option_button->is_Selected) {
					cout << "option clicked" << endl;
					button_sound_effect->play(0);
					state_0_5 = true;
					state_0 = false;
					option_button->is_Selected = false;
				}
				if (exit_button->is_Selected) {
					button_sound_effect->play(0);
					isrunning = false;
				}
			}
			if (state_0_5 || state_2_5) {
				if (background_music_setting_button->is_Selected) {
					button_sound_effect->play(0);
					cout << "music clicked" << endl;
					background_music->update();
					if (background_music->pause) {
						background_music_setting_button->butts_rect.x = 0;
					}
					else {
						background_music_setting_button->butts_rect.x = 806;
					}
					background_music_setting_button->is_Selected = false;
				}
				if (sound_effect_setting_button->is_Selected) {
					button_sound_effect->play(0);
					cout << "sound clicked" << endl;
					button_sound_effect->update();
					if (button_sound_effect->pause) {
						sound_effect_setting_button->butts_rect.x = 0;
					}
					else {
						sound_effect_setting_button->butts_rect.x = 806;
					}
					sound_effect_setting_button->is_Selected = false;
				}
				if (back_button->is_Selected ) {
					button_sound_effect->play(0);
					if (state_0_5) {
						state_0_5 = false;
						state_0 = true;
					}
					if (state_2_5) {
						state_2 = true;
						state_2_5 = false;
						mTimer->pause = false;
						mTimer->Beta_Time += mTimer->Alpha_Time;
					}
					back_button->is_Selected = false;
				}
			}
			if (state_1) {
				if (ok_button->is_Selected) {
					button_sound_effect->play(0);
					cout << "ok clicked" << endl;
					state_1_6 = true;
					state_1 = false;
					ok_button->is_Selected = false;
				}
			}
		}
		if (state_1_5) {
			if (easy->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = false;
				state_1_7 = true;
				new_game->diff = 1;
				new_game->khoitaotu();
				new_game->answer_render->name = new_game->answer;
				all_in_text->name = new_game->answer;
				easy->is_Selected = false;
			}
			if (normal->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = false;
				state_1_7 = true;
				new_game->diff = 2;
				new_game->khoitaotu();
				new_game->answer_render->name = new_game->answer;
				all_in_text->name = new_game->answer;
				normal->is_Selected = false;
			}
			if (hard->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = false;
				state_1_7 = true;
				new_game->diff = 3;
				new_game->khoitaotu();
				new_game->answer_render->name = new_game->answer;
				all_in_text->name = new_game->answer;
				hard->is_Selected = false;
			}
		}
		if (state_1_6) {
			if (plant_topic->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = true;
				state_1_6 = false;
				new_game->nhaptudien("animal and plant.txt");
				plant_topic->is_Selected = false;
			}
			if (weather_topic->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = true;
				state_1_6 = false;
				new_game->nhaptudien("weather.txt");
				weather_topic->is_Selected = false;
			}
			if (color_topic->is_Selected) {
				button_sound_effect->play(0);
				state_1_5 = true;
				state_1_6 = false;
				new_game->nhaptudien("color and shape.txt");
				color_topic->is_Selected = false;
			}
		}
		if (state_1_7) {
			if (normal_mode->is_Selected) {
				button_sound_effect->play(0);
				new_game->mode = 0;
				state_1_7 = false;
				state_2 = true;
				mTimer->reset();
				normal_mode->is_Selected = false;
			}
			if (timer_mode->is_Selected) {
				button_sound_effect->play(0);
				new_game->mode = 1;
				state_1_7 = false;
				state_2 = true;
				mTimer->reset();
				timer_mode->is_Selected = false;
			}
		}
		if (state_2) {
			if (pause_button->is_Selected) {
				button_sound_effect->play(0);
				state_2 = false;
				state_2_5 = true;
				mTimer->pause = true;
				mTimer->update();
				pause_button->is_Selected = false;
			}
			if (all_in_button->is_Selected) {
				cout << "clicked" << endl;
				button_sound_effect->play(0);
				state_2_0 = true;
				state_2 = false;
				all_in_button->is_Selected = false;
			}
		}
		if (state_3) {
			if (play_again_button->is_Selected) {
				button_sound_effect->play(0);
				state_2 = true;
				state_3 = false;
				play_again_button->is_Selected = false;
				new_game->just_started = true;
			}
			if (turn_off_button->is_Selected) {
				button_sound_effect->play(0);
				isrunning = false;
			}
			if (high_score_button->is_Selected) {
				button_sound_effect->play(0);
				state_3 = false;
				state_3_5 = true;
				new_game->sort_high_score();
				for (int i = 0; i < 6; i++) {
					leader_board[i]->name = new_game->player_name_list[i] + " " + to_string(new_game->time_played_list[i]);
				}
				high_score_button->is_Selected = false;
			}
		}
		if (state_3_5) {
			if (return_button->is_Selected) {
				button_sound_effect->play(0);
				state_3_5 = false;
				state_0 = true;
				return_button->is_Selected = false;
				new_game->just_started = true;
				text_box->name.clear();
			}
		}
		break;
		case SDL_TEXTINPUT:
			if (state_1) {
				if (text_box->still_input) {
					if (text_box->name.size() <= 20)
						text_box->name += event.text.text;
				}
			}
			if (state_2) {
				char x = event.text.text[0];
				if (guessed_list->find(x)) {
					guessed_list->name += event.text.text;
					guessed_list->name += ' ';
					new_game->update(x);
					new_game->answer_render->name = new_game->answer;
					if (new_game->fully_answered) {
						if (new_game->badGuessCount == 7) {
							lose_sound_effect->play(0);
						}
						else {
							win_sound_effect->play(0);
						}
					state_2 = false;
					state_3 = true;
						if (new_game->badGuessCount != 7) {
							new_game->player_name = text_box->name;
							new_game->time_wasted = mTimer->Delta_Time();
							new_game->set_high_score();
						}
					}
				}
			}
			if (state_2_0) {
				char x = event.text.text[0];
				all_in_text->name[new_game->indicator] = x;
				new_game->indicator++;
				if (new_game->chosedWord[new_game->indicator] == '_') {
					new_game->indicator++;
				}
				//cout << "indicator " << new_game->indicator << endl;
				if (new_game->indicator == new_game->answer.size()) {
					if (all_in_text->name == new_game->chosedWord) {
						new_game->player_name = text_box->name;
						new_game->time_wasted = mTimer->Delta_Time();
						new_game->set_high_score();
						win_sound_effect->play(0);
					}
					else {
						new_game->badGuessCount = 7;
						lose_sound_effect->play(0);
					}
					state_2_0 = false;
					state_3 = true;
				}
			}
			break;
		default:
		break;
	}
};
void Game::update() { //cap nhat vi tri
	dem++;
	if (!state_3 && new_game->badGuessCount != 7) {
		background_pic->update();
	}
	if (state_0) {
		title->update();
		start_button->update(*mouse, 240,0);
		option_button->update(*mouse, 240,0);
		exit_button->update(*mouse, 240,0);
	}
	if (state_0_5) {
		setting->update();
		sound_effect_setting_button->saved_update(*mouse);
		background_music_setting_button->saved_update(*mouse);
		back_button->saved_update(*mouse);
	}
	if (state_1) {
		text_box_empty->update();
		ok_button->update(*mouse, 800,0);
	}
	if (state_1_5) {
		easy->saved_update(*mouse);
		normal->saved_update(*mouse);
		hard->saved_update(*mouse);
	}
	if (state_1_6) {
		color_topic->saved_update(*mouse);
		plant_topic->saved_update(*mouse);
		weather_topic->saved_update(*mouse);
	}
	if (state_1_7) {
		normal_mode->saved_update(*mouse);
		timer_mode->saved_update(*mouse);
	}
	if (state_2) {
		if (new_game->just_started) {
			new_game->reset();
			all_in_text->name = new_game->answer;
			guessed_list->name.clear();
			mTimer->reset();
		}
		mTimer->update();
		if (new_game->mode == 0) {
			timer->name = to_string(mTimer->Delta_Time() + 1);
		}
		else if (new_game->mode == 1) {
			timer->name = to_string(15 - (mTimer->Delta_Time() + 1));
			if (mTimer->Delta_Time() + 1 == 15) {
				//lose_sound_effect->play(0);
				new_game->badGuessCount = 7;
				state_2 = false;
				state_3 = true;
			}
		}
		lois->update();
		brian->update();
		model->update();
		pause_button->update(*mouse, 516, 0);
		if (new_game->badGuessCount >= 5) {
			stewie->update();
			new_game->hint();
			hint->name = new_game->Hin;
		}
		else {
			all_in_button->saved_update(*mouse);
			stewie_2->update();
		}
		switch (new_game->badGuessCount) {
		case 1:
			model_0[0]->update();
			break;
		case 2:
			model_0[1]->update();
			break;
		case 3:
			model_0[2]->update();
			break;
		case 4:
			model_0[3]->update();
			break;
		case 5:
			model_0[4]->update();
			break;
		case 6:
			model_0[5]->update();
			break;
		}
	}
	if (state_2_5) {
		mTimer->pausing();
		setting->update();
		sound_effect_setting_button->saved_update(*mouse);
		background_music_setting_button->saved_update(*mouse);
		back_button->saved_update(*mouse);
	}
	if (state_2_0) {
		mTimer->update();
		if (new_game->mode == 0) {
			timer->name = to_string(mTimer->Delta_Time() + 1);
		}
		else if (new_game->mode == 1) {
			timer->name = to_string(15-(mTimer->Delta_Time() + 1));
			if (mTimer->Delta_Time() + 1 == 15) {
				//lose_sound_effect->play(0);
				new_game->badGuessCount = 7;
				state_2 = false;
				state_3 = true;
			}
		}
	}
	if (state_3) {
		if (new_game->badGuessCount == 7) {
			wasted->update();
			model_0[5]->change(300, 200, 1280 / 2 - 100, 780 / 2 -100);
			play_again_button->update(*mouse, 122,0);
			turn_off_button->update(*mouse, 122, 0);
		}
		else {
			congratulation->update();
			play_again_button->update(*mouse, 122,0);
			turn_off_button->update(*mouse, 122, 0);
			high_score_button->update(*mouse, 122, 0);
		}
	}
	if (state_3_5) {
		high_score->update();
		return_button->saved_update(*mouse);
	}
	mouse->update();
};
void Game::render() {
	if (state_3 && new_game->badGuessCount == 7) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //doi mau
	}else
	SDL_SetRenderDrawColor(renderer, dem%255, (dem+10)%255, (dem+100)%255, 255); //doi mau
	SDL_RenderClear(renderer); //clear render
	background_music->play(-1);//choi nhac
	if (!state_3 && new_game->badGuessCount != 7) {
		background_pic->Render();
	}
	if (state_0) {
		title->Render();
		start_button->draw();
		option_button->draw();
		exit_button->draw();
	}
	if (state_0_5) {
		setting->Render();
		background_music_setting_button->draw();
		sound_effect_setting_button->draw();
		back_button->draw();
		//high_score->Render();
	}
	if (state_1) {
		welcome->display(1280 / 2 - welcome->des.w / 2, 200);
		Ask_name->display(1280 / 2 - Ask_name->des.w / 2, 200 + welcome->des.h + 30);
		text_box_empty->Render();
		if (text_box->name.size() > 20) {
			warning->display(1280 / 2 - warning->des.w / 2, 200 + welcome->des.h + 30 + 90);
		}
		text_box->draw("zh-cn.ttf", 30, 1280 / 2 ,325,75);
		ok_button->draw();
	}
	if (state_1_5) {
		difficulty->display(1280 / 2 - 130, 720 / 2 - 150);
		easy->draw();
		normal->draw();
		hard->draw();
	}
	if (state_1_6) {
		Topic->display(1280 / 2 - 140, 720 / 2 - 150);
		plant_topic->draw();
		color_topic->draw();
		weather_topic->draw();
	}
	if (state_1_7) {
		Game_mode->display(1280 / 2 - 140, 720 / 2 - 150);
		normal_mode->draw();
		timer_mode->draw();
	}
	if (state_2) {
		lois->Render();
		if (!guessed_list->found) {
			brian->Render();
		}
		new_game->draw("zh-cn.ttf", 30, 1280 / 2, 180, -250);
		guessed_list->draw("zh-cn.ttf", 20, 1280 / 2, 210, -490);
		model->Render();
		pause_button->draw();
		timer->draw("zh-cn.ttf", 30, 1280 / 2, 650, -520);
		if (new_game->badGuessCount >= 5 && hint->name.size()) {
			stewie->Render();
			hint->draw("zh-cn.ttf", 30, 1280 / 2, 525, 50);
		}
		else {
			stewie_2->Render();
			//all_in_button->draw();
		}
		switch (new_game->badGuessCount) {
		case 1:
			model_0[0]->Render();
			break;
		case 2:
			model_0[1]->Render();
			break;
		case 3:
			model_0[2]->Render();
			break;
		case 4:
			model_0[3]->Render();
			break;
		case 5:
			model_0[4]->Render();
			break;
		case 6:
			model_0[5]->Render();
			break;
		}
	}
	if (state_2_0) {
		all_in_text->draw("zh-cn.ttf", 30, 1280 / 2, 720 / 2, 0);
		timer->draw("zh-cn.ttf", 30, 1280 / 2, 650, -520);
	}
	if (state_2_5) {
		setting->Render();
		background_music_setting_button->draw();
		sound_effect_setting_button->draw();
		back_button->draw();
	}
	if (state_3) {
		if (new_game->badGuessCount == 7) {
			wasted->Render();
			model_0[5]->Render();
			play_again_button->draw();
			turn_off_button->draw();
		}
		else {
			congratulation->Render();
			play_again_button->draw();
			turn_off_button->draw();
			high_score_button->draw();
		}
	}
	if (state_3_5) {
		high_score->Render();
		leader_board[0]->draw("zh-cn.ttf", 30, 1280 / 2, 160, 0);
		leader_board[1]->draw("zh-cn.ttf", 30, 1280 / 2, 160 + 75, 0);
		leader_board[2]->draw("zh-cn.ttf", 30, 1280 / 2, 160 + 75 * 2, 0);
		leader_board[3]->draw("zh-cn.ttf", 30, 1280 / 2, 160 + 75 * 3, 0);
		leader_board[4]->draw("zh-cn.ttf", 30, 1280 / 2, 160 + 75 * 4, 0);
		leader_board[5]->draw("zh-cn.ttf", 30, 1280 / 2, 160 + 75 * 5, 0);
		//return_button->draw();
	}
	mouse->draw();
	SDL_RenderPresent(renderer); // hien thi render
	
};
void Game::clean() {// dong game
	cout << "Game cleaned" << endl;
	mTimer->release();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
};


