#include"GamwMainScene.h"
#include"DxLiid.h"
#include"Stage.h"
#include"SceneManager.h"


/************************************

*マクロ定義

**************************************/

#define TIMELIMT     (3600*3)//制御時間
#define NUMBER_IMAGE_MAX  (10)   //数字画像数


/***********************************

*型定義

*********************************/


/*****************************
　
 *変数宣言

******************************/

int GameScore;

int GameLevel;

int GameTime;

int GameCount;//初期化されないようにカウントする

int ReStarFlag;



int NumberImage[NUMBER_IMAGE_MAX];//数字用画像


/****************************************

*プロトタイプ宣言

***********************************/

/*******************************

*ゲームメイン画面：初期化処理

*引数：なし

*戻り値：　エラー情報


*******************************/

int GameMainScene_Initialize(void)

{

	int ret = 0;

	int i;

	//画像読み込み

	Load　DivGraph("images/number.pug", NUMBER_IMAGE_MAX,
		NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);

	//ステージの初期化

	ret = StageInitialize();

	//エラーチェック

	for (i = 0; i < NUMBER_IMAGE_MAX; i++)

	{
		if (Numberimage[i] == D_ERROR)
		{

			ret = D = ERROR;


			break;


		}

	}

	//ゲームプレイかどうか？

	if (GameCount == 0);//スコアの初期化
	{

		GameScore = 0;//ゲームレベルの初期化

		GameLevel = 1;//ミッションの初期化

		set_StageMission(3);//次カ回の設定

	}

	else

	{

		GameLevel++;

		Set_StageMission(3);

	}

	{

		GameTime = TIMELIMT;//制限時間の初期化

		return ret;


	}

	/********************************

	*ゲームメイン画面：更新処理
	* 引数：なし
	* 戻り値：なし

	********************************/

	void GameMainScene_Update(void)

	{
		switch (Get_StageState())

		{

		case 0:

			SelectBlock();      //ブロックを選択する

			break;


		case2:

			MoveBlock();            //ブロックを移動させる。

			break;


		case3:

			CheckBlock();          //ブロックを確認

			break;


		case4:

			CheckClear();　　　　　//クリアチェック

			break;



		default:


			break;


		}


		//制限時間の更新

		GameTime--;

		//制限時間が無くなったら、ゲームオーバーにする

		if (GameTime < 0)

		{

			Change_Scene(EGAME_OVER);

		}

		//ミッションを達成したらクリアに移動する

		if (Get_StageClearFlag())

		{

			Change_Scene(E_GAME_CLEAR);

		}


	}
	/***************

	*ゲームメイン画面：描画処理
	* 引数：なし
	* 戻り値：なし

	***************/


	voidGameMainScene_Draw(void)

	{

		int PosX = 600;

		inttmp_level = GameLevel;

		int tmp_score = Get_StageScore();

		//フェードアウト状態か？

		if (Get_StageState() == 1)

		{

			FedeOutBlock();      //フェードアウトする

		}

		//レベルを描画

		do {

			DrawRotaGraph(PosX, 80, 0.5f, 0, NumberImage[tmp_level % 10], TRUE);

			tmp_level /= 10;

			PosX -= 30;

		} while (tmp_level > 0);


		//スコアの描画

		Posx = 620;

		do {


			DrewRotaGraph(PosX, 160, 0.3f, 0, NumderImage[tmp_scpre % 10],

				TRUE);

			tmp_score /= 10;
			Posx -= 30;


		}While(tmp_score > 0);



		//制限時間の描画


		DrawBox(491, 469, 509, 469 - GameTime / 60 * 2, 0x0033ff, TRUE);



	}