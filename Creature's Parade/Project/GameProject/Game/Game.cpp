#include"Game.h"
#include"Player.h"
#include"Creature.h"
#include"Obstacle.h"
#include"Trap.h"
#include"Platform.h"
#include"Switch.h"
#include"Map.h"
#include"Goal.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Map());

	Base::Add(new Player(CVector2D(6 * 72, 13 * 72), true));
	Base::Add(new Creature("Cat_pink", CVector2D(12 * 72, 13 * 72), false));
	//座標、HP、サイズ(マップチップ換算)
	Base::Add(new Obstacle(CVector2D(22 * 72, 14 * 72), 10, 6));
	//座標、弾のタイプ、向き
	Base::Add(new Trap(CVector2D(36 * 72, 14 * 72), 0, 0));
	Base::Add(new Trap(CVector2D(37 * 72, 14 * 72), 0, 0));

	Base::Add(new Creature("Skull_red", CVector2D(48 * 72, 13 * 72), false));
	Base::Add(new Creature("Slime_green", CVector2D(50 * 72, 13 * 72), false));
	Base::Add(new Creature("Witch_pauple", CVector2D(52 * 72, 13 * 72), false));

	Base::Add(new Obstacle(CVector2D(62 * 72, 14 * 72), 20, 12));
	Base::Add(new Goal(CVector2D(73 * 72, 4 * 72)));
	/*
	Base::Add(new Switch(CVector2D(20*72,11*72)));
	Base::Add(new Platform(CVector2D(15*72,12*72)));
	*/
}

Game::~Game(){
}

void Game::Update(){
}
