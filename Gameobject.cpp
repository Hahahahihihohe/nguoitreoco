#include "SDLL.h"
Gameobject::Gameobject(const char* texture,int h, int w, int x, int y) {
	
	Obj_Texture = TextureManager::Load_Texture(texture);
	xpos = x;
	ypos = y;
	object_h = h;
	object_w = w;
	if (Obj_Texture == NULL) { //bao loi object
		string x = "Load object";
		getSDLerror(cout, x, true);
	}
}
void Gameobject::update() {
	
	//source: xac dinh phan cua object muon render
	/*srcR.h = 300;
	srcR.w = 150;
	srcR.x = 0;
	srcR.y = 0;*/
	//destination: xac dinh toa do va kich thuoc cua object muon render
	
	desR.h = object_h;
	desR.w = object_w;
	desR.x = xpos;
	desR.y = ypos;
}
void Gameobject::Render() {
	SDL_RenderCopy(Game::renderer, Obj_Texture, NULL, &desR);
}
void Gameobject::change(int h, int w, int x, int y) {
	desR.h = h;
	desR.w = w;
	desR.x = x;
	desR.y = y;
}
