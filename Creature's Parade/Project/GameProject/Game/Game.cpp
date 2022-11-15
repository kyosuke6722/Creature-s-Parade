#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Obstacle.h"
#include"Trap.h"
#include"Map.h"
#include"UI.h"

Game::Game():Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(3*72,20*72),true));
	for (int i = 5; i < 9; i++) {
		Base::Add(new Creature(CVector2D(i * 72, 20 * 72), false));
	}
	Base::Add(new Obstacle(CVector2D(15*72,14*72),4));
	Base::Add(new Trap(CVector2D(25 * 72, 19 * 72)));
	Base::Add(new UI());
}

Game::~Game(){
}

void Game::Update(){
}
