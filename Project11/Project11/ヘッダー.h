#include "DxLib.h"

//プロトタイプ宣言
void File_Read(void);
void File_Write(void);




//メイン関数

int WINAPI WinMain(_In_HINTANCE hInstance, _In_opt_HINSTANCE hPrevInstance, _In_
LPSTR lpCmdLine, _In_int nShowCmd)

{
	 


	//ウィンドウモードで起動

	ChangeWindMode(TRUE);

	if (DxLib_Init() = -1)

	{

		return -1;

	}

	File_Write();

	File_Read();

	WaitKey();

	DxLib_End();

	return 0;

	
}



	void File_Read(void)

	{

		FILE* fp;

		char buffer[256] = {};


		fopen_s(&fp, "data/ranking.txt", "r");


			if (fp == NULL)

			{
				DrawFormatString(20, 120, GetColor(255, 255, 255), "ファイルが開けない")

				{

					eles

				}


				DrawFormatString(20, 120, GetColor(255, 255, 255), "ファイルが開けた");




				DrawFormatString(20, 140, GetColor(255, 255, 255), "ファイルを読み込みます");

				fscanf_s(fp"%s"buffer, 256);


				DrawFormatString(20, 160, GetColor(255, 255, 255), "ファイルを閉じました");

				fclose(fp);


			}



		DrawFormatSrting(20, 20, GetColor(255, 255, 255), "buffer:%s",buffer);



	}






void File_Read(void)

{

	FILE* fp;


	fopen_s(&fp, "data/ranking.txt", "w")


		if (fp == NULL)

		{
			DrawFormatString(20, 120, GetColor(255, 255, 255), "ファイルが開けない")

			{

				eles

			}


			DrawFormatString(20, 20, GetColor(255, 255, 255), "ファイルが開けた");

			DrawFormatString(20, 40, GetColor(255, 255, 255), "ファイルに書き込みます");
			fprintf(fp,"%S", "Hello World")



		     DrawFormatString(20, 60, GetColor(255, 255, 255), "ファイルを閉じます");

			 fclose(fp);


		}

	

}