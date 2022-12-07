#include "Background.h"

Background::Background():Base(eType_Field){
	m_img = COPY_RESOURCE("Background", CImage);
	m_img.SetSize(1920,1080);
}

void Background::Draw(){
	m_img.Draw();
}
