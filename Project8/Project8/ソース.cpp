#include"DxLid.h"


//�\���̂̐錾

struct Transform
{

	float x;
	float y;
	float z;

}Transform;


//���C���֐�

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



		DrawFormatStering(20, 20, GetColor(255, 255, 255), "X���W%f:", location.x);
	DrawFormatStering(20, 40, GetColor(255, 255, 255), "X���W%f:", location.x);
	DrawFormatStering(20, 60, GetColor(255, 255, 255), "X���W%f:", location.x);


	Waitkey();

	DxLid_End();

	return0
}
