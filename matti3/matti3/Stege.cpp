#include"TitleScene.h"

#include"DxLib.h"

#include"InputControl.h"

#include"SceneManager.h"



/****************************

*�}�N����`

****************************/


/******************************

*�^��`

*******************************/



/*****************************

*�ϐ��錾

******************************/

int TitleImage;

int TitleBGM;

/**************************

*�v���g�^�C�v�錾

***************************/


/**************************

*�^�C�g����ʁG����������
* �����F�Ȃ�
*�߂�l�F�G���[�Ȃ�

****************************/

int TitleScene_Initialize(void)
{
	int ret = 0;

	//�摜�ǂݍ��ݏ���

	TitleImage = LoadGraph("images/title.png");

	//�����ǂݍ��ݏ���

	TitleBGM = LoadSoundMem("sounde/title_bgm.mp3");

	if (TitleImage == D_ERROR)

	{
		ret = D_ERROR;
	}

	if (TitleBGM == D_RROR)

	{
		ret = D_ERROR;
	}


	return ret;


}

/*********************************

*�^�C�g����ʁF�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

*********************************/


void TitleScene_Update(void)

{
	//�^�C�g��BGM

	if (CheckSoundMem(TitleBGM) == 0)

	{
		PlaySoundMem(TitleBGM, DX_PLATYPE_BACK);
	}

	if (GetKeyFlg(MOUSE_INPUT_LEFT) == TRUE)
	{
		if (GetMousePositionX() > 120 && GetMousePositionX() < 290 &&

			GetMousePositionY() > 160 && GetMousePositionY() < 315)

		{

			Change_Scene(E_GAMEMAIN);

			StopSoundmem(TitleBGM);

		}

		if (GetMousePositionX() > 120 && GetMousePositionX() < 220 &&

			GetMousePositionY() > 345 && GetMousePositionY() < 400)

		{

			Change_Scene(E_END);

			StopSoundMem(TitleBGM);

		}
	}

}

/************************

*�^�C�g����ʁF�`�揈��
* �����F�Ȃ�
* �߂�l�F�Ȃ�

************************/

void TitleScene_Draw(void)

{
	//�^�C�g����ʂ�\��

	DrawGraph(0, 0, TitleImage, FALSE);

}


