/**********************************************************

*�v���O���~���O���K
*�}�b�`3�Q�[���̐���

*******************************************************/



#include"DxLob.h"
#include"FreamControl.h"
#include"InputControl.h"
#include"SceneManager.h"



/*******************************************************


*�}�N����`

*******************************************************/

#define SCREEN_HEIGHT     (480)
#define SCREEN_WIDTH      (640)
#define SCREEN_COLORBIT   (32)
#define FONT_SIZE        (20)

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


int WINAPI WinMain(_In_HINSTANCE nINstance, _In_opt_HINSTANCE hPrevInstance,
	_In_LPSTR lpCmdLine, _In_int nShowCmd)

{

	SetMainWindewText("Match3Puzzle");

	ChangeWindewMode(TRUE);

	setGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);



	if (DxLLid_Init() == D_ERROR)

	{

		returnD_ERROR;
	}

	FreamControl_Initialize();

	Input_Initialize();


	if (SceneManager_Intialize(E_TITLE) == D_ERROR)

	{

		returnD_ERROR;

	}



	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(FONT_SIZE);


	while (PeocessMessage() != D_ERROR && Input_Escape() == FALSE)

	{

		Input_Update();


		SceneManger_Update();

		ClearDrawScreen();

		FreamControl_Update();

		ScreenFlip();


	}


	DxLid_End();


	return 0;



}











