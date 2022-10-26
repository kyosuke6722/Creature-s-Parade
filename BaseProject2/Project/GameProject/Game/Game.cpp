#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Map.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Player());
}

Game::~Game(){
}

void Game::Update(){
}
