#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Map.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(100,500),true));
}

Game::~Game(){
}

void Game::Update(){
}
