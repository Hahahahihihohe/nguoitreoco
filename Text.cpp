#include"SDLL.h"
Text::Text(const string& file, int font_size) {
	found = true;
	font = TTF_OpenFont(file.c_str(), font_size);
};
Text::Text(const string& file, int font_size, const string& message_text, SDL_Color& color) {
	this->texture = load_font(file, font_size, message_text,color);
	SDL_QueryTexture(this->texture, NULL, NULL, &des.w, &des.h);
}
void Text::display(int x, int y) const{
	des.x = x;
	des.y = y;
	SDL_RenderCopy(Game::renderer, texture, NULL, &des);
}
SDL_Texture* Text::load_font(const string& file, int font_size, const string& message_text, SDL_Color& color) {
	TTF_Font* font = TTF_OpenFont(file.c_str(), font_size);
	if (font == NULL) {
		cerr << "Tai font that bai\n";
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (text_surface == NULL) {
		cerr << "tao font that bai\n";
	}
	auto text_texture = SDL_CreateTextureFromSurface(Game::renderer, text_surface);
	if (text_texture == NULL) {
		cerr << "tao font that bai\n";
	}
	SDL_FreeSurface(text_surface);
	return text_texture;
}

void Text::input_name() {

	static const unsigned char* keys = SDL_GetKeyboardState(NULL);
	SDL_Event e;
	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderClear(Game::renderer);

	while (SDL_PollEvent(&e) != 0) {
		 if (e.type == SDL_QUIT) {
			still_input = false;
		 }
		 if (e.type == SDL_KEYDOWN) {
			 if (e.key.keysym.sym == SDLK_BACKSPACE && name.size()) {
				 name.pop_back();
			 }
			 if (e.key.keysym.sym == SDLK_RETURN && name.size()) {
				 still_input = false;
			 }
		 }
		 if (e.type == SDL_TEXTINPUT) {
			name += e.text.text;
		 }
			
	}
}
void Text::draw(const string& file, int font_size, int x, int y, int z){
		SDL_RenderCopy(Game::renderer, texture, NULL, NULL);

		SDL_Color foreground = { 0, 0, 0 };

		if (name.size()) {
			SDL_Surface* text_surf = TTF_RenderText_Solid(font, name.c_str(), foreground);
			SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, text_surf);
			SDL_QueryTexture(this->texture, NULL, NULL, &des.w, &des.h);
			des.x = x - (text_surf->w / 2.0f)-z;
			des.y = y;
			des.w = text_surf->w;
			des.h = text_surf->h;
			SDL_RenderCopy(Game::renderer, text, NULL, &des);

			SDL_DestroyTexture(text);
			SDL_FreeSurface(text_surf);
		}
	
}
bool Text::find(char x) {
	if (name.find(x) == string::npos) {
		found = true;
		return true;
	}
	else {
		found = false;
		return false;
	}
}
