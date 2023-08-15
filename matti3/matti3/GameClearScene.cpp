#include"GameClearScene.h"
#include"DxLib.h"
#include"SceneManager.h"


/***************************************

*�}�N����`

***************************************/

/***************************************

*�^��`

****************************************/


/***********************************

*�^��`

**********************************/

int GameClearImage;

int GameClearSE;

int GameClearFlag;


/*******************************

*�v���g�^�C�v�錾

******************************/

/****************************

*�Q�[���N���A��ʁF����������
* �����F�Ȃ�
* �߂�l�F�G���[���

******************************/

int GameClearScene_Initialize(void)
{
	int ret = 0;

	//�摜�ǂݍ���

	GameClearImage = LoadGraph("images/gamwclear.png");

	//�����̓ǂݍ���

	GameClearSE = LoadSoundMem("sound/gameclear_se.mp3");

	GameClearFlag = 0;

	//�G���[�`�F�b�N

	if (GameClearImage == -1)
	{
		ret = -1;
	}

	if (GameClearSE == -1)
	{
		ret = -1;
	}

	return ret;

}


/*******************************

*�Q�[���N���A��ʁF�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

********************************/


void GameClearScene_Update(void)
{
	//�Q�[���N���A���ʉ��Đ��`�F�b�N

	if (CheckSoundMem(GameClearSE) == 0)
	{
		if (GameClearFlag == TRUE)
		{
			Change_Scene(E_GAMEMAIN);
		}
		eles

		{
			PlaySoundMem(GameClearSE,DX_PLAYTYPE_BACK);
		GameClearFlag = TRUE;

		}
	}


}

/********************************

*�Q�[���N���A��ʁF�`�揈��
* �����F�Ȃ�
* �߂�l�F�Ȃ�

*******************************/

void GameClearScene_Draw(void)
{

	DrawGraph(0, 0, GameClearImage, FALSE);

}







