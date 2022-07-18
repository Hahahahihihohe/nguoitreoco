#pragma once
#include<fstream>
#include<iostream>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<vector>
#include<SDL_mixer.h>
#include<algorithm>
using namespace std;

void getSDLerror(ostream& os, string& msg, bool fatal); // bao loi
//void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
//void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
//void waitUntilKeyPressed();
class Game { //quan ly game
private:
	bool isrunning;
	SDL_Window* window;
	int dem = 0;
public:
	static SDL_Renderer* renderer;
	Game() {
		window = NULL;
		renderer = NULL;
	}
	~Game();
	void initSDL();
	void handle_event();
	void update();
	void render();
	void clean();
	bool running() {
		return isrunning;
	};
};
class TextureManager // quan ly cac texture
{
public:
	static SDL_Texture* Load_Texture(const char* filename);
	static void Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};
class Gameobject { // quan ly cac object
private: 
	int xpos;
	int ypos;
	int object_h;
	int object_w;
	SDL_Texture* Obj_Texture;
	SDL_Rect srcR, desR;
	
public:
	Gameobject(const char* texture, int h, int w, int x , int y);
	~Gameobject();
	void update();
	void Render();
	void change(int h, int w, int x, int y);
};
class Text {
public:
	Text(const string& file, int font_size, const string& message_text, SDL_Color& color);	
	Text(const string& file, int font_size);
	void display(int x, int y) const;
	static SDL_Texture* load_font(const string& file, int font_size, const string& message_text, SDL_Color& color);
	void input_name();
	void draw(const string& file, int font_size,int x, int y,int z);
	bool still_input = true;
	string name;
	mutable SDL_Rect des;
	bool find(char x);
	bool found;
	TTF_Font* font;
private:
	SDL_Texture* texture;
	
	
	
};
class Mouse {
	SDL_Texture* mouse_tex;
	SDL_Rect mouse_rect;
	
public:
	Mouse();
	void update();
	void draw();
	SDL_Rect point;
};
class Butt {
public:
	Butt(int h1, int w1, int x1, int y1, int h2, int w2, int x2, int y2, const char* filename);
	void update(Mouse&, int x, int y);
	void draw();
	bool is_Selected = false;
	void saved_update(Mouse&);
	SDL_Texture* butt_texture;
	SDL_Rect butts_rect, buttd_rect;
	
};
class Hangman { 
public:
	vector<string> tudien; // mang nhung tu trong danh sach
	//vector<char> guessed_char_list; // mang nhung ki tu da duoc nhap 
	string chosedWord, answer; // dap an va tu can tim
	int badGuessCount = 0; // so lan doan sai
	int indicator;
	int diff;
	int time_wasted;
	int mode;
	bool just_started = true;
	bool fully_answered = false;
	bool find_hint = false;
	string player_name;
	string Hin;
	Text* answer_render;
	void nhaptudien(const char* file);
	void khoitaotu();
	Hangman();
	void update(char e);
	void draw(const string& file, int font_size,int x, int y , int z);
	void hint();
	void set_high_score();
	void sort_high_score();
	vector<int> time_played_list;
	vector<string> player_name_list;
	void reset();
	
};
class Music {
private:
	Mix_Music* music;
	Mix_Chunk* sound;
	string music_file;
	int type;
	bool music_playing = false;
public:
	bool pause = false;
	Music(string music_file, int type);
	void update();
	void play(int loop);

};
class Timer {
private:
	static Timer* sInstance;
	unsigned int mStart_Ticks;
	unsigned int mElapsed_Ticks;
	int Delata_Time;
	int temp_timer;
public:
	Timer();
	static Timer* Instance();
	static void release();
	void reset();
	int Delta_Time();
	void update();
	bool pause = false;
	void pausing();
	int Beta_Time;
	int Alpha_Time;
};