#include"GameOverScene.h"
#include"DxLid.h"
#include"SceneManager.h"



/*********************

*変数宣言

*********************/

int GameOverImage;
int GameOverSE;
int GameOverFlag;


/*************************

*プロトタイプ宣言

************************/

/***********************

*ゲームオーバー画面；初期化処理

*引数；なし

* 戻り値；エラー情報


***********************/

int GameOverScene_Initalize(void)

{

	int ret = 0;

	//画像読み込み

	GameOverImage = LoadGraph("images/gameover.png");

	//音源読み込み

	GameOverSE = LoadSoundMem("sounuds/gameover_semp3");


	GameOverFlag = FALSE;


	//エラーチェック

	if (GameOverImage == -1)

	{
		ret=-1;
	}

	if (GameOverSE = -1)

	{
		ret = -1;
	}

	return ret;


}

/***********************************
*ゲームオーバーの画面：更新処理

*引数：なし

*戻り値：なし

**********************************/

void GameOverScene_Update(void)

{
	//ゲームオーバー画像表示

	DrawGraph(0, 0, GameOverImage,FALSE);

}









