#include"GameOverScene.h"
#include"DxLid.h"
#include"SceneManager.h"



/*********************

*�ϐ��錾

*********************/

int GameOverImage;
int GameOverSE;
int GameOverFlag;


/*************************

*�v���g�^�C�v�錾

************************/

/***********************

*�Q�[���I�[�o�[��ʁG����������

*�����G�Ȃ�

* �߂�l�G�G���[���


***********************/

int GameOverScene_Initalize(void)

{

	int ret = 0;

	//�摜�ǂݍ���

	GameOverImage = LoadGraph("images/gameover.png");

	//�����ǂݍ���

	GameOverSE = LoadSoundMem("sounuds/gameover_semp3");


	GameOverFlag = FALSE;


	//�G���[�`�F�b�N

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
*�Q�[���I�[�o�[�̉�ʁF�X�V����

*�����F�Ȃ�

*�߂�l�F�Ȃ�

**********************************/

void GameOverScene_Update(void)

{
	//�Q�[���I�[�o�[�摜�\��

	DrawGraph(0, 0, GameOverImage,FALSE);

}









