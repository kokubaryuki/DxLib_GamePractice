#include"DxLib.h"

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

	Transform location;

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return-1;
	}


	location.x = 10.0f;
	location.y = 20.0f;
	location.z = 30.0;

	DrawFormatStering(20, 20,GetColor(255, 255, 255), "X座標%f:", location.x);
	DrawFormatStering(20, 40,GetColor(255, 255, 255), "X座標%f:", location.x);
	DrawFormatStering(20, 60,GetColor(255, 255, 255), "X座標%f:", location.x);


	Waitkey();

	DxLid_End();

	return0;

}
