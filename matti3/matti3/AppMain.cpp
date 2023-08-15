/**********************************************************

*プログラミング実習
*マッチ3ゲームの制御

*******************************************************/



#include"DxLob.h"
#include"FreamControl.h"
#include"InputControl.h"
#include"SceneManager.h"



/*******************************************************


*マクロ定義

*******************************************************/

#define SCREEN_HEIGHT     (480)
#define SCREEN_WIDTH      (640)
#define SCREEN_COLORBIT   (32)
#define FONT_SIZE        (20)

/**************************************************:

*型定義

*************************************************/


/***********************************************

*グローバル変数宣言

**********************************************/



/***********************************************

*プロトタイプ宣言

************************************************/


/***********************************************

*プログラム開始

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











