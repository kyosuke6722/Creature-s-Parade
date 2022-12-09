#include "Platform.h"
#include"Switch.h"

Platform::Platform():Base(eType_Field){
}

void Platform::Update(){
	if (Switch* s = dynamic_cast<Switch*>(Base::FindObject(eType_Obstacle))) {
		if (s->move_flag) {

		}
	}
}

void Platform::Collision() {
}

void Platform::Draw(){
}