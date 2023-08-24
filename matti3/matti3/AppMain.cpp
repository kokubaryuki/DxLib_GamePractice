/**********************************************************

*�v���O���~���O���K

*�}�b�`3�Q�[���̐���

*******************************************************/



#include"DxLib.h"
#include"FreamControl.h"
#include"InputControl.h"
#include"SceneManager.h"



/*******************************************************

*�}�N����`

*******************************************************/

#define SCREEN_HEIGHT     (480)//�X�N���[���T�C�Y�i�����j
#define SCREEN_WIDTH      (640)//�X�N���[���T�C�Y�i���j
#define SCREEN_COLORBIT   (32)//�X�N���[���J���[�s�b�g
#define FONT_SIZE        (20)//�����T�C�Y

/**************************************************:

*�^��`

*************************************************/


/***********************************************

*�O���[�o���ϐ��錾

**********************************************/



/***********************************************

*�v���g�^�C�v�錾

************************************************/


/***********************************************

*�v���O�����J�n

**********************************************/

int WINAPI WinMain(_In_ HINSTANCE hINstance,_In_opt_ HINSTANCE hPrevInstance,
_In_ LPSTR lpCmdLine,_In_ int nShowCmd)

{
	

	SetMainWindowText("Match 3 Puzzle");


	
	ChangeWindowMode(TRUE);


    
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);



	if (DxLib_Init() == D_ERROR)

	{

		return D_ERROR;
	}

	FreamControl_Initialize();

	Input_Initialize();


	if (SceneManager_Initialize(E_TITLE) == D_ERROR)

	{

		return D_ERROR;

	}



	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(FONT_SIZE);


	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)

	{

		Input_Update();


		SceneManager_Update();

		ClearDrawScreen();

		SceneManager_Draw();

		FreamControl_Update();

		ScreenFlip();


	}


	DxLib_End();


	return 0;



}











