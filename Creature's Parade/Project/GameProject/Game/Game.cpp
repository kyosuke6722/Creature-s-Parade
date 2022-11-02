#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Obstacle.h"
#include"Map.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(3*72,20*72),true));
	for (int i = 5; i < 9; i++) {
		Base::Add(new Creature(CVector2D(i * 72, 20 * 72), false));
	}
	Base::Add(new Obstacle(CVector2D(15*72,14*72),4));
}

Game::~Game(){
}

void Game::Update(){
}
