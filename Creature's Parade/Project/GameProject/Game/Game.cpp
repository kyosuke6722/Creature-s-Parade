#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Obstacle.h"
#include"Trap.h"
#include"Map.h"
#include"UI.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(3 * 72, 14 * 72), true));
	Base::Add(new Creature("Cat_pink", CVector2D(5 * 72, 14 * 72), false));
	Base::Add(new Creature("Skull_red", CVector2D(6 * 72, 14 * 72), false));
	Base::Add(new Creature("Slime_green", CVector2D(7 * 72, 14 * 72), false));
	Base::Add(new Creature("Witch_pauple", CVector2D(8 * 72, 14 * 72), false));
	Base::Add(new Obstacle(CVector2D(15 * 72, 7 * 72), 15));
	Base::Add(new Trap(CVector2D(25 * 72, 12 * 72)));
	Base::Add(new UI());
}

Game::~Game(){
}

void Game::Update(){
}
