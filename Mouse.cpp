#include"SDLL.h"
Mouse::Mouse() {
	mouse_tex = TextureManager::Load_Texture("Tien bip.png");
	mouse_rect.w = 25;
	mouse_rect.h = 25;
	point.w = 1;
	point.h = 1;
	SDL_ShowCursor(false);
}
void Mouse::update() {
	SDL_GetMouseState(&mouse_rect.x, &mouse_rect.y);
	point.x = mouse_rect.x;
	point.y = mouse_rect.y;
	//cout << point.x << " " << point.y << endl;
}
void Mouse::draw() {
	SDL_RenderCopy(Game::renderer, mouse_tex, NULL, &mouse_rect);
}
