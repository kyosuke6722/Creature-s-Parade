#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Map.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(3*72,20*72),true));
	Base::Add(new Creature(CVector2D(5*72, 20*72), false));
	Base::Add(new Creature(CVector2D(6 * 72, 20 * 72), false));
}

Game::~Game(){
}

void Game::Update(){
}
