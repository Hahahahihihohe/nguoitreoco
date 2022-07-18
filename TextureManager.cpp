#include "SDLL.h"
SDL_Texture* TextureManager::Load_Texture(const char* filename) {
	SDL_Surface* tmp_surface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	return tex;
}
void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
	SDL_DestroyTexture(text);
}
