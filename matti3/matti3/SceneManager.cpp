#include"SceneManager.h"

#include"TitleScene.h"

#include"GameMainScene.h"

#include"GameClearScene.h"

#include"GameOverScene.h"

/****************************

*�}�N����`

*****************************/

/*****************************

*�^��`

******************************/

/******************************

*�ϐ��錾

******************************/

GAME_MODE Game_Mode;      

GAME_MODE Next_Mode;

/*************************

*�v���g�^�C�v�錾

****************************/


/**************************

*�V�[���Ǘ��@�\:����������
* �����F�Ȃ�
* �߂�l�F�Ȃ�

********************************/


int SceneManager_Initialize(GAME_MODE mode)

{

	int Read_Error;


	//�V�[���ǂݍ���
	//�^�C�g�����

	Read_Error = TitleScene_Initialize();

	if (Read_Error == D_ERROR)

	{

		return D_ERROR;
	}

	//�Q�[�����C�����

	Read_Error = GameMainScene_Initialze();

	if (Read_Error == D_ERROR)

	{

		return D_ERROR;

	}

	//�Q�[���N���A���

	Read_Error = GameClearScene_Initialize();

	if (Read_Error == D_ERROR)

	{

		return D_ERROR;

	}

	//�Q�[���I�[�o�[���

	Read_Error = GameOverscene_Initialize();

	if (Read_Error == D_ERROR)

	{

		return D_ERROR;

	}

	Game_Mode = mode;

	Next_Mode = Game_Mode;

	return Read_Error;


}

/****************************************

*�V�[���Ǘ��@�\�F�X�V����
* �����F�Ȃ�
* �߂�l�Ȃ�

*****************************************/

void SceneManager_+(void)

{

	//�O�t���[���ƃQ�[�����[�h������Ă���V�[����؂�ւ���

	if (Game_Mode != Next_Mode)

	{

		SceneManager_Initialize(Next_Mode);

	}

	//�e��ʂ̍X�V

	switch (Game_Mode)

	{

	case E_TITLE:

		TitleScene_Update();

		break;

	case E_GAMEMAIN:

		ganemainScene_Update();

		break;

	case E_GAME_CLEAR:

		GameClearScene_Update();

		break;

	case E_GAME_OVER:

		GameOVerScene_Update();

		break;


	default:

		break;



	}



}

/******************************

*�\�[���Ǘ��@�\�F�`�揈��
* �����F�Ȃ�
* �߂�l�F�Ȃ�

********************************/

void SceneManager_Draw(void)

{

	Next_Mode = mode;

}







