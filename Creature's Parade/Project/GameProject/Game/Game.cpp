#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Obstacle.h"
#include"Trap.h"
#include"Platform.h"
#include"Switch.h"
#include"Background.h"
#include"Map.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Background());
	Base::Add(new Map());

	Base::Add(new Player(CVector2D(3 * 72, 13 * 72), true));
	Base::Add(new Creature("Cat_pink", CVector2D(6 * 72, 13 * 72), true));
	Base::Add(new Creature("Skull_red", CVector2D(8 * 72, 13 * 72), true));
	Base::Add(new Creature("Slime_green", CVector2D(10 * 72, 13 * 72), true));
	Base::Add(new Creature("Witch_pauple", CVector2D(12 * 72, 13 * 72), true));
	//座標、弾のタイプ、向き
	/*
	Base::Add(new Trap(CVector2D(13 * 72 - 36, 9 * 72), 1, 0));
	Base::Add(new Trap(CVector2D(12 * 72 - 36, 10 * 72), 1, 1));
	Base::Add(new Trap(CVector2D(13 * 72 - 36, 11 * 72), 1, 2));
	Base::Add(new Trap(CVector2D(14 * 72 - 36, 10 * 72), 1, 3));
	*/
	//Base::Add(new Obstacle(CVector2D(8 * 72, 13 * 72), 15));
	Base::Add(new Switch(CVector2D(14*72,11*72)));
	Base::Add(new Platform(CVector2D(15*72,12*72)));
}

Game::~Game(){
}

void Game::Update(){
}
