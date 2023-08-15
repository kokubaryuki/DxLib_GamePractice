#include"DxLib.h"


int WINAPI WinMain(_In_HINSTACE hInstance, _In_opt_HINSTANCE hprevInstance,
	_In_LPSTR lpCmdLine, _in_int nShowCmd)
{

	int = table[3][3] = {

		{10,20,30},
		{40,50,60},
		{70,80,90},


	};


	int i = 0;

	int* p;


		ChangeWindowMode(TRUE);



	if (DxLib_Init() == -1)

	{
		retun - 1;
	}

	p = (int*)table;


	for(i=0;i<(3*3);i++)
	{

		DrawFormatString(20, 20, GetColor(255, 255, 255), "%d", *p);

		p++


	}

	WaitKry();


	DxLib_End();


	retun 0;


}
	