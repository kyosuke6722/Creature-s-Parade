//ゲーム係機能のインクルード
#include <GLLibrary.h>
#include"Game/AnimData.h"
#include"Title/Title.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080




//--------------------------------------------
//グローバル変数領域
//--------------------------------------------




void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();



}
void Init(void)
{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp,'W');
	CInput::SetButton(0, CInput::eDown,'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));
	ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png" , player_anim_data, 32, 32));
	//クリーチャー達
	ADD_RESOURCE("Cat_pink", CImage::CreateImage("Image/Cat_pink.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Cat_yellow", CImage::CreateImage("Image/Cat_yellow.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Skull_blue", CImage::CreateImage("Image/Skull_blue.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Skull_red", CImage::CreateImage("Image/Skull_red.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Slime_blue", CImage::CreateImage("Image/Slime_blue.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Slime_green", CImage::CreateImage("Image/Slime_green.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Slime_red", CImage::CreateImage("Image/Slime_red.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Slime_silver", CImage::CreateImage("Image/Slime_silver.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Witch_blue", CImage::CreateImage("Image/Witch_blue.png", creature_anim_data, 32, 32));
	ADD_RESOURCE("Witch_pauple", CImage::CreateImage("Image/Witch_pauple.png", creature_anim_data, 32, 32));
	//マップ,ギミック
	ADD_RESOURCE("Rock", CImage::CreateImage("Image/Rock.png"));
	ADD_RESOURCE("Background", CImage::CreateImage("Image/Background.png"));
	ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
	ADD_RESOURCE("Arrow", CImage::CreateImage("Image/Arrow.png"));
	ADD_RESOURCE("Fire", CImage::CreateImage("Image/Fire.png", effect_fire_anim_data, 24, 32));
	ADD_RESOURCE("LaunchPad", CImage::CreateImage("Image/LaunchPad.png",launchpad_anim_data,12,10));
	ADD_RESOURCE("Platform", CImage::CreateImage("Image/Platform.png"));
	ADD_RESOURCE("Switch", CImage::CreateImage("Image/Switch.png"));
	ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal_test.png"));
	//UI
	ADD_RESOURCE("Life", CImage::CreateImage("Image/Life.png",heart_anim_data,32,32));
	ADD_RESOURCE("Gauge", CImage::CreateImage("Image/Gauge_test.png"));

	//SE
	SOUND("Voice_Player_damage1")->Load("SOUND/SE/Voice_Player_damage1.wav",1);
	SOUND("Voice_Player_damage2")->Load("SOUND/SE/Voice_Player_damage2.wav",1);
	SOUND("Voice_Player_down1")->Load("SOUND/SE/Voice_Player_down1.wav",1);
	SOUND("Voice_Player_down2")->Load("SOUND/SE/Voice_Player_down2.wav",1);
	SOUND("SE_Throw")->Load("SOUND/SE/SE_Throw.wav",10);
	SOUND("SE_Arrow")->Load("SOUND/SE/SE_Arrow.wav",10);
	SOUND("SE_Fire")->Load("SOUND/SE/SE_Fire.wav",10);
	SOUND("SE_Obstacle_broken")->Load("SOUND/SE/SE_Obstacle_broken.wav",2);
	SOUND("SE_Obstacle_damage")->Load("SOUND/SE/SE_Obstacle_damage.wav",5);
	

	Base::Add(new Title());

}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
