#include"DxLib.h"


//���C���֐�

int WINAPI WinMain(_In_HINTANCE hInstance, _In_opt_HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_int nShowCmd)
{



	//���[�J���ϐ���`

	FILE* fp;

	ChangeWindMode(TRUE);

	if (DxLib_Init() = -1)

	{

		return -1;

	}

	fopen_s(&fp,"data/ranking.txt","w")


		if (fp == NULL)
		{
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "�t�@�C�����J���܂���ł���")

			{

				eles

			}

		
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "�t�@�C�����J���܂���");
			DrawFormatSting(20, 20, GetColor(255, 255, 255), "�t�@�C������܂�");

			fclose(fp);


		}

	WaitKey();

	DxLid_End();

	return 0;

}

