#include "SDLL.h"
Butt::Butt(int h1, int w1, int x1, int y1, int h2, int w2, int x2, int y2, const char* filename) {
	SDL_Texture* t = TextureManager::Load_Texture(filename);
	butt_texture = t;
	butts_rect.h = h1;
	butts_rect.w = w1;
	butts_rect.x = x1;
	butts_rect.y = y1;
	buttd_rect.h = h2;
	buttd_rect.w = w2;
	buttd_rect.x = x2;
	buttd_rect.y = y2;
	if (t == NULL) { //bao loi tao phim
		string x = "Createbutton";
		getSDLerror(cout, x, true);
	}
}
void Butt::update(Mouse &mouse, int x, int y) {
	if (SDL_HasIntersection(&buttd_rect, &mouse.point)) {
		is_Selected = true;
		butts_rect.x = x;
	}
	else {
		is_Selected = false;
		butts_rect.x = y;
	}
}
void Butt::saved_update(Mouse& mouse) {
	if (SDL_HasIntersection(&buttd_rect, &mouse.point)) {
		is_Selected = true;
	}
	else {
		is_Selected = false;
	}
}
void Butt::draw() {
	SDL_RenderCopy(Game::renderer, butt_texture, &butts_rect, &buttd_rect);
}