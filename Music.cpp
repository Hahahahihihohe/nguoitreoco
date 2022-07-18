#include"SDLL.h"
Music::Music(string music_file, int type) {
	this->music_file = music_file;
	this->type = type;
	if (type == 0) {
		this->music = Mix_LoadMUS(music_file.c_str());
		if (!music) {
			cout << "Music: " << Mix_GetError() << endl;
		}
	}
	if (type == 1) {
		this->sound = Mix_LoadWAV(music_file.c_str());
		if (!sound) {
			cout << "Music: " << Mix_GetError() << endl;
		}
	}
}
void Music::update() {
	if (!pause) {
		pause = true;
		if (pause == true && type == 0) {
			Mix_PauseMusic();
		}
	}
	else if (pause) {
		pause = false;
		if (!pause && type == 0) {
			Mix_ResumeMusic();
		}
	}
	
}
void Music::play(int loop) {
	if (music_playing == false) {
		if (type == 0) {
			Mix_PlayMusic(music, loop);
		}
		music_playing = true;
	}
	if (type == 1) {
		if(!pause)
		Mix_PlayChannel(1, sound, loop);
	}
}