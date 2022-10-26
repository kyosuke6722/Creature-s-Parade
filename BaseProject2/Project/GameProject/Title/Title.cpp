#include "Title.h"
#include"../Game/Game.h"

Title::Title():Base(eType_Scene) {
}

Title::~Title(){
	Base::Add(new Game());
}

void Title::Update(){
	SetKill();
}

void Title::Draw(){
}
