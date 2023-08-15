#include"DxLib.h"

int Sum(int para1, int para2)
{
	return para1 + para2;
}

int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_HINSTANCE hprevInstance, _In_
	LPSTR ipCmdLine, _In_int nShowCmd)

{

	intnum = Sum(2, 3);

	changeWindowMode(TRUE);

	if (DxLib_Init() == -1)

		return-1;
	{

		DreFormatString(20, 40, GetColor(255, 255, 255), "%d", sum);

		DreFormatString(20, 40, GetColor(255, 255, 255), "%d", sum(10,30));

		WaitKey();

		DxLib_End();

		return0;

	}


