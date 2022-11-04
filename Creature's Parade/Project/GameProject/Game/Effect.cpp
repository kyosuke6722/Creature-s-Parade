#include "Effect.h"

Effect::Effect(const char* name, CVector2D pos):Base(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);
}

void Effect::Update(){
}

void Effect::Draw(){
}
