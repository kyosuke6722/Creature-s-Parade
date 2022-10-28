#include "Map.h"

Map::Map():Base(eType_Field) {
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(1920, 1080);
}

void Map::Draw(){
	m_img.Draw();
}
