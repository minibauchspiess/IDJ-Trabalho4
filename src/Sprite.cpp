
#include "include/Sprite.h"
#include "include/Game.h"
#include "include/Resources.h"
#include <iostream>

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated)
{
    texture = nullptr;
}

Sprite::Sprite(string file, GameObject& associated) : Component(associated){
    texture =nullptr;
    Open(file);
}

Sprite::~Sprite(){
}

void Sprite::Update(float dt){}

bool Sprite::Is(string type){
    return (!type.compare("sprite"));
}

void Sprite::Open(string file){

    int width, height;

    texture = Resources::GetImage(file);

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    associated.box.w = width;
    associated.box.h = height;
    SetClip(0, 0, width, height);

}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x=x;
    clipRect.y=y;
    clipRect.w=w;
    clipRect.h=h;
}

void Sprite::Render(){
    Render(associated.box.x, associated.box.y, clipRect.w, clipRect.h);
}

void Sprite::Render(int x, int y, int w, int h, int layer){
    Game& instance = Game::GetInstance();

    SDL_Rect dstrect;
    dstrect.x = x - (int)(Camera::pos.x*(layer+1)*LAYER_MOV);// + (int)Camera::pos.x*SPEED*LAYER_MOV/(layer+1);
    //cout<<layer<<endl;
    dstrect.y =y  - (int)(Camera::pos.y*(layer+1)*LAYER_MOV);// + (int)Camera::pos.y*SPEED*LAYER_MOV/(layer+1);
    dstrect.w = w;
    dstrect.h = h;

    SDL_RenderCopy(instance.GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return associated.box.w;
}

int Sprite::GetHeight(){
    return associated.box.h;
}

bool Sprite::IsOpen(){
    if (texture != nullptr){
        return true;
    }
    else{
        return false;
    }
}




