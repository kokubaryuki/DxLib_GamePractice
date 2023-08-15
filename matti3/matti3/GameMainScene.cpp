#include"GamwMainScene.h"
#include"DxLiid.h"
#include"Stage.h"
#include"SceneManager.h"


/************************************

*�}�N����`

**************************************/

#define TIMELIMT     (3600*3)//���䎞��
#define NUMBER_IMAGE_MAX  (10)   //�����摜��


/***********************************

*�^��`

*********************************/


/*****************************
�@
 *�ϐ��錾

******************************/

int GameScore;

int GameLevel;

int GameTime;

int GameCount;//����������Ȃ��悤�ɃJ�E���g����

int ReStarFlag;



int NumberImage[NUMBER_IMAGE_MAX];//�����p�摜


/****************************************

*�v���g�^�C�v�錾

***********************************/

/*******************************

*�Q�[�����C����ʁF����������

*�����F�Ȃ�

*�߂�l�F�@�G���[���


*******************************/

int GameMainScene_Initialize(void)

{

	int ret = 0;

	int i;

	//�摜�ǂݍ���

	Load�@DivGraph("images/number.pug", NUMBER_IMAGE_MAX,
		NUMBER_IMAGE_MAX, 1, 60, 120, NumberImage);

	//�X�e�[�W�̏�����

	ret = StageInitialize();

	//�G���[�`�F�b�N

	for (i = 0; i < NUMBER_IMAGE_MAX; i++)

	{
		if (Numberimage[i] == D_ERROR)
		{

			ret = D = ERROR;


			break;


		}

	}

	//�Q�[���v���C���ǂ����H

	if (GameCount == 0);//�X�R�A�̏�����
	{

		GameScore = 0;//�Q�[�����x���̏�����

		GameLevel = 1;//�~�b�V�����̏�����

		set_StageMission(3);//���J��̐ݒ�

	}

	else

	{

		GameLevel++;

		Set_StageMission(3);

	}

	{

		GameTime = TIMELIMT;//�������Ԃ̏�����

		return ret;


	}

	/********************************

	*�Q�[�����C����ʁF�X�V����
	* �����F�Ȃ�
	* �߂�l�F�Ȃ�

	********************************/

	void GameMainScene_Update(void)

	{
		switch (Get_StageState())

		{

		case 0:

			SelectBlock();      //�u���b�N��I������

			break;


		case2:

			MoveBlock();            //�u���b�N���ړ�������B

			break;


		case3:

			CheckBlock();          //�u���b�N���m�F

			break;


		case4:

			CheckClear();�@�@�@�@�@//�N���A�`�F�b�N

			break;



		default:


			break;


		}


		//�������Ԃ̍X�V

		GameTime--;

		//�������Ԃ������Ȃ�����A�Q�[���I�[�o�[�ɂ���

		if (GameTime < 0)

		{

			Change_Scene(EGAME_OVER);

		}

		//�~�b�V������B��������N���A�Ɉړ�����

		if (Get_StageClearFlag())

		{

			Change_Scene(E_GAME_CLEAR);

		}


	}
	/***************

	*�Q�[�����C����ʁF�`�揈��
	* �����F�Ȃ�
	* �߂�l�F�Ȃ�

	***************/


	voidGameMainScene_Draw(void)

	{

		int PosX = 600;

		inttmp_level = GameLevel;

		int tmp_score = Get_StageScore();

		//�t�F�[�h�A�E�g��Ԃ��H

		if (Get_StageState() == 1)

		{

			FedeOutBlock();      //�t�F�[�h�A�E�g����

		}

		//���x����`��

		do {

			DrawRotaGraph(PosX, 80, 0.5f, 0, NumberImage[tmp_level % 10], TRUE);

			tmp_level /= 10;

			PosX -= 30;

		} while (tmp_level > 0);


		//�X�R�A�̕`��

		Posx = 620;

		do {


			DrewRotaGraph(PosX, 160, 0.3f, 0, NumderImage[tmp_scpre % 10],

				TRUE);

			tmp_score /= 10;
			Posx -= 30;


		}While(tmp_score > 0);



		//�������Ԃ̕`��


		DrawBox(491, 469, 509, 469 - GameTime / 60 * 2, 0x0033ff, TRUE);



	}