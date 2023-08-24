#include"DxLib.h"


//メイン関数

int WINAPI WinMain(_In_HINTANCE hInstance, _In_opt_HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_int nShowCmd)
{



	//ローカル変数定義

	FILE* fp;

	ChangeWindMode(TRUE);

	if (DxLib_Init() = -1)

	{

		return -1;

	}

	fopen_s(&fp,"data/ranking.txt","w")


		if (fp == NULL)
		{
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "ファイルが開けませんでした")

			{

				eles

			}

		
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "ファイルが開けました");
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "ファイルを閉じます");

			fclose(fp);


		}

	WaitKey();

	DxLid_End();

	return 0;

}

