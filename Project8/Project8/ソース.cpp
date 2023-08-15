#include"DxLid.h"


//構造体の宣言

struct Transform
{

	float x;
	float y;
	float z;

}Transform;


//メイン関数

int WINNAPI WinMain(_In_HINSTANCE hInstance, _In_opt_HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_int nShowCmd)

{

	Transform location = { 0.0f,0.0f,0.0f };
	Transform* p;


	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return-1;
	}

	p = &location;

	p->x = 10.0f;

	p->y = 20.0f;

	p->z = 30.0f



		DrawFormatStering(20, 20, GetColor(255, 255, 255), "X座標%f:", location.x);
	DrawFormatStering(20, 40, GetColor(255, 255, 255), "X座標%f:", location.x);
	DrawFormatStering(20, 60, GetColor(255, 255, 255), "X座標%f:", location.x);


	Waitkey();

	DxLid_End();

	return0
}
