#include"Stage.h"
#include"DxLib.h"
#include"InputControl.h"


/*****************

���}�N����`

*******************/


#define HEIGHT                (12)//�u���b�N�z�u�T�C�Y�i�����j
#define WIDTH                 (12)//�u���b�N�z�u�T�C�Y�i���j
#define BLOCKSIZE            (48)//�u���b�N�T�C�Y
#define BLOCKSIZE_IMAGE_MAX  (10)//�u���b�N�摜��

#define ITEM_MAX             (8)//�A�C�e���ő�

#define SELECT_CURSOR        �i0�j
#define NEXT_CURSOR            (1)
#define TMP_CURSOR             (2)


/***********************

*�^��`

*************************/


typedef struct

{

	int flg;
	int x, y;
	int width, height;
	int image;
	int backup;


}T_Object;


typedef struct


{

	int  x;
	int  y;


}T_CURSOR;


enum

{

	E_NONE,
	E_ONCE,
	E_SECOND

};


/************************

*�ϐ��錾

**********************/

T_Object Block[HEIGHT][WIDTH];

T_CURSOR Select[3];

int ClickStatus;

int Stage_Mission;

int Stage_score;

int ClearFlag;




int BlockImage[BLOCK_IMAGE_MAX];            //�u���b�N�摜

int StageImage;//�w�i�p�摜

int ClickSE;                               //�N���b�NSE

int FadeOutSE;                             //�t�F�[�h�A�E�gSE

int MoveBlockSE;//�u���b�N�ړ�SE




/****************************

*�v���g�^�C�v�錾

******************************/

int comdo_check(int x, int y);

void comdo_check_h(int y, int x, int* cnt, int* col);

void comdo_check_w(int y, int x, int* cnt, int* col);

void save_block(void);

void restore_block(void);

/*********************************

*�X�e�[�W����@�\�F����������
*�����F�Ȃ�
* �߂�l�F�G���[���

********************************/

int StageInitialize(void)

{

	int ret = 0;

	int i;

	//�摜�ǂݍ���

	LoadDivGraph("images/block.png", BLOCK_IMAGM_MAX, BLOCK_MAX, 1,
		BLOCKSIZE, BlockImage);

	StageImage = LoadGraph("images/atage.png");




	//�����ǂݍ���

	ClickSE = LoadSoundMem("sounds/click_se.mp3");
	FadeOutSE = LoadSoundMem("sunde/fadeout_se.mp3");
	MoveBlockSE = LoadSoundMem("sunde/fadeout_se.mp3");



	//�u���b�N�쐬����

	CreateBlock();



	ClickStatus = E_NONE;

	Stage_State = 0;

	Stage_Score = 0;

	ClearFlag = FALSE;


	for (i = 0; i < 3; i++)

	{
		Select[i].x = 0;
		Select[i].y = 0;

	}


	//�G���[�`�F�b�N

	for (i = 0; i, BLOCK_IMAGE_IMAGE_MAX; i++)

	{
		if (BlockImage[i] == -1)

		{
			ret = -1;

			break;

		}


	}


	if (StageImage == -1)

	{
		ret = -1;

	}


	if (ClickSE == -1)

	{
		ret = -1;
	}

	if (FadeOutSE == -1)

	{
		ret = -1;

	}

	if (MoveBlockSE == -1)

	{
		ret = -1;
	}

	return ret;
}
	 /*********************************
	 
	 *�X�e�[�W����@�\;�X�e�[�W�̕`��
	 * �����F�Ȃ�
	 * �߂�l�F�Ȃ�
	 
	 ***********************************/

	 void StageDraw(void) {


		 DrawGraph(0, 0, StageImage, FALSE);

		 //�A�C�e���̎擾����`��

		 for (int i = 0; i < ITEM_MAX; i++)

		 {
			 DrawRotaGraph(520, 245 + i * 30, 0.5f, 0, BlockImage[i + 1], TRUE, 0);

			 DrawFormatString(580, 235, +i * 30, 0xffffff,"%3d",Item[i]);

		 }


		 //�u���b�N��`��

		 for (int i = 0; i < HEIGHT; i++)

		 {
			 for(int j=0;j<WIDTH;j++)

			 {

				 if(Block[i][j].flg=TRUE&&Block[i][j].image!=NULL)

				 {

					 DrawGraph(Block[i][j].x, Block[i][j].y,


						 [BlockImage[i][j].image],TRUE);
				 }

				 
			 }

		 }


	 }

	 //�I���u���b�N��`�悷��

	 DrawGraph(Select[SELECT_CURSOR].x* BLOCKSIZE, Select[SELECT_CURSOR].y*
		 BLOCKSIZE, BlockImage[9], TRUE);

	 if (ClickStatus!=E_NONE)

	 {

		 DrawGraph(Select[NEXT_CURSOR].x* BLOCKSIZE,
			 select[NEXT_CUROR].y* BLOCKSIZE, BlockImage[9], TEUE);


	 }


	 //�~�b�V������`��

	 SetFontSize(20);

	 DrawFormatString(590, 211, GetColor(255, 255, 255), "%3d", Stage_Mission);


	 //�A�C�e���̎擾����`��

	 for (int i = 0; i < ITEM_MAX; i++)

	 {

		 DrawRotaGraph(540, 245 + i * 30, 0.5f, 0, BlockImage[i + 1], TRUE, 0);

		 DrawFormatString(580, 235 + i * 30, GetColor(255,255,255),"%3d"
		 Item[i]);


	 }

}


/***************************************

*�X�e�[�W����@�\�F�u���b�N��������
* �����F�Ȃ�
* �߂�l�F�Ȃ�

***************************************/

void CreateBlock(void)

{

	int Check = 0;

	int i, j;

	do

	{
		Check = 0;
		for (i = 0; i < HEIGHT; i++)
		{
			for (j = 0; j < WIDTH; j++)
			{
				if (j == o || j == WIDTH - 1||==HEIGHT - 1||==0)
				{

					Block[i][j].flg = FALSE;
					Block[i][j]image = NULL;

				}
				else
				{
					Block[i][j].flg = TRUE;
					Block[i][j].x = (j - 1) * BLOCKSIZE;
					Block[i][j].y = (i - 1) * BLOCKSIZE;
					Block[i][j].width = BLCKSIZE;
					Block[i][j].height = BLOCKSIZE;
					Block[i][j].image = GetRand(7) + 1;//1�`8�̗���
				}
			}
		}

		/*for (i = 1; i < HEIGHT - 1; i++)
		{
			for (j = 1; j < WIDTH - 1; j++)
			{
				if (Block[i][j].image == NULL)
				{
					Block[i][j].image = GetRand(7) + 1;
				}
			}
		}*/

		//�u���b�N�A���`�F�b�N
		for (i = 1; i < HEIGHT - 1; j++)
		{
			for (j = 1; j < WIDTH - 1; j++)
			{
				Check += combo_check(i, j);
			}
		}
	} while (Check != 0);

	for (i = 0; i < ITEM_MAX; i++)
	{
		Item[i] = 0;
	}
}


/***********************************

*�X�e�[�W����@�\�F�u���b�N�I������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�

*********************************/

void SelectBlock(void)

{
	int Tmpblock;
	int Result;

	//�J�[�\�����W�̎擾

	Select[SELECT_CURSOR].x = GetMousePositionX() / BLOCKSIZE;
	Select[SELECT_CURSOR].x = GetMousePositionY() / BLOCKSIZE;


	//�I���u���b�N�͈̔͂𐧌�

	if (Select[SELECT_CURSOR].x < 0)
	{
		Select[SELECT_CURSOR].x = 0;
	}

	if (Select[SELECT_CURSOR].x > WIDTH - 3)
	{
		Select[SELECT_CURSOR].x > WIDTH - 3;
	}

	if (Select[SELECT_CURSOR].y < 0)
	{
		Select[SELECT_CURSOR].y = 0;
	}

	if (Select[SELECT_CURSOR].y > HEIGHT - 3)
	{
		Select[SELECT_CURSOR].y = HEIGHT - 3;
	}

	//�N���b�N�Ńu�b���N��I��

	PlaySoundMem(ClicSE, DX_PLAYTYPE_BACK);

	if (ClickStatus == E_CUROS) {

		Select[NEXT_CURSOR].x = Select[SELECT_CURSOR].x;
		Select[NEXT_CURSOR].x = Select[SELECT_CURSOR].y;
		ClickStatus = E_ONCE;

	}

	else if (ClickStatus == E_ONCE &&

		((aba(Select[NEXT_CURSOR].x - Select[SELECT_CURSOR].x)

			== 1 &&

			(aba(Select[NEXT_CURSOR].y - Select[SELECT_CURSOR].y)

				== 0)) ||

			(aba(Select[NEXT_CURSOR].x - Select[SELECT_CURSOR].x)

				== 0 &&

				aba(Select[NEXT_CURSOR].y - Select[SELECT_CURSOR].y) ==

				1)))

	{
		Select[TMP_CURSOR].x = Select[SELECT_CURSOR], x;
		Select[TMP_CURSOR].x = Select[SELECT_CURSOR], y;
		ClickStatus = E_SECOND;


	}

}

//�I���u���b�N����������

if (ClickStatus == E_SECOND)

{

	TmpBlock = Block[Select[NEXT_CURSOR].y + 1][Select[NEXT_CURSOR].x +

		1].image;

	Block[Select[NEXT_CURSOR].y + 1][Select[NEXT_CURSOR].x + 1].mage =

		Block[Select[TMP_CURSOR].y + 1][Select[TMP_CURSOR].x + 1].mage;

	Block[Select[TMP_CURSOR].y + 1][Select[TMP_CURSOR].x + 1].mage =

		TmpBlock;

	//�A�����R�ȏォ���ׂ�

	Result = 0;

	Result += comdo_check(Select[NEXT_CURSOR].y + 1,
		Select[NEXT_CURSOR], x + 1);

	Result += combo_check(Select[TMP_CURSOR].y + 1
		Select[TMP_CURSOR].x + 1);


	//�A�����R�����Ȃ�I���u���b�N�����ɖ߂�

	if (Result == 0)

	{

		int  TmpBlock = [Selock[NEXT_CURSOR].y +

			1][Select[NEXT_CURSOR].x + 1].image;



		Block[Select[NEXT_CURSOR].y + 1][Select[NEXT_CURSOR].x +

			1].image = Block[Select[TMP_CURSOR].y + 1][Select[TMP_CURSOR].x + 1].image;



		Block[Select[TMP_CURSOR].y + 1][Select[TMP_CURSOR].x +
			1].image = TmpBLock;



	}

	else

	{

		//�A�����O�ȏ�Ȃ�u���b�N�������u���b�N�ړ������ֈړ�����

		Stage_State = 1;

	}

	//���ɃN���b�N�ł���悤��ClockFlag���[���ɂ���
	ClickStaus = E_NONE;


  }


}

/*******************************

*�X�e�[�W����@�\�F�u���b�N
*�����F�Ȃ�
* �߂�l�F�Ȃ�

****************************/

void FadeOutBlock(void)

{
	static int BlendMode = 255;

	int i, j;


	//�t�F�[�h�A�E�g���ʉ�

	if (CheckSoudmem(FadeOutSE) == 0)
	{

		PlaySoundMem(FadeOutSE, DX_PLAYTYPE_BACK);

	}

	//�`�惂�[�h���A���t�@�u�����h�ɂ���

	Set DrawBlendMode(DX_BLENDRAPHTYPE_ALPHA, BlendMode);

	for (i = 1; < HEIGT - 1; ++)

	{
		for (j = 1; j < WIDTH - 1; j++)
		{
			if (Block[i][j].image == 0)
			{

				DrawGraph(Block[i][j].x, Block[i][j].y,
					BlockImage[Block[i]][j].backup], TRUE);

			}
		}
	}

	//�`�惂�[�h�a�m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	BlendMode -= 5;


	if (BlendMode == 0)

	{


		BlendMode = 255;

		Stage_State = 2;

		StopSoundMem(FadeOutSE);


	}


}



/*************************

*�X�e�[�W����@�\�F�u���b�N�ړ�����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

*****************************/


void MoveBlock(void)
{
	int i, j, k;

	//�u���b�N�ړ����ʉ�
	PlaySoundmem(MoveBlockSE, DX_PLYTYPE_BACK);

	//���ֈړ����鏈��

	for (i = 1; i < HEUGHT - 1; 1++)
	{
		for (j - 1; j < WIDTH - 1; j++)
		{
			if (Block[i][j].image == 0)
			{
				for (k = i; k > 0; k--)
				{
					Block[k][j].image = Block[k - 1][j].image;
					Block[k - 1][j].image = 0;
				}

			}
		}
	}








	//��̃u���b�N�𐶐����鏈��

	for (i = 1; i < HEIGHT - 1; i++)
	{
		for (j = 1; j < WIDTH - 1; j++)
		{
			if (Block[i][j].image == 0)
			{
				Blockk[i][j].image = GetRand(7) + 1;
			}
		}
	}

	//�A���`�F�b�N�ֈړ�����
	Stage_State = 3;

}


/***************************************

*�X�e�[�W����@�\�F�A���`�F�b�N����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

******************************************/


void CheckBlock(void)
{
	int Result = 0;

	int i, j;

	//�u���b�N�A���`�F�b�N
	for (i = 1; i < HEIGHT - 1; i++)
	{
		for (j = 1; j < WIDTH - 1; j++)
		{
			Result += combo_check(i, j);

		}
	}

	//�A�����Ȃ��Ȃ�΃u���b�N�I����
	//�b�����łȂ���΃u���b�N�ړ��ֈڍs���ĘA���`�F�b�N���p������

	if (Result == 0)
	{
		//�N���A�`�F�b�N�����ֈڍs����A

		Stage_State = 4;
	}

	else 
	{
	//�A�����O�ȏ�Ȃ�u���b�N�������u���b�N�ړ������ֈڍs����

		Stage_State - 1;
	
	}



}


/**************************

*�X�e�[�W����@�\�F�N���A�����`�F�b�N����
* �����F�Ȃ�
* �߂�l�F�Ȃ�
* ���l�F�N���A�����t���O��0�Ƃ��A�e�X�N�[���̍폜��
* �@�@�@�@���x�������������Ȃ�������`�F�b�N�����𒆒f���ăQ�[���𑱍s����

**************************/


void CheckClear(void)

{
	int i;

	for (i = 0; i < ITEM_MAX; i++)
	{
		if (Item[i] >= Stage_Mission)
		{
			ClearFlag = TRUE;

			break;
		}
	}
	if (ClearFlag != TRUE)
	{
		Stage_State= 0;
	}

}


/****************************

*�X�e�[�W����@�\�F�X�e�[�W�X�e�[�^�X���擾����
* �����F�Ȃ�
* �߂�l�F�X�e�[�W�̃X�e�[�^�X���

**************************/


int Get_StageState(void)

{
	return Stage_State;

}


/******************************

*�X�e�[�W����@�\�F�~�b�V������񏈗�
* �����F�Ȃ�
* �߂�l�F�~�b�V�������N���A���Ă��邩

********************************/


int Get_StageClearFlag(void)
{

	return ClearFlag;

}


/*****************************

*�X�e�[�W����@�\�F�~�b�V�������擾����
* �����F�Ȃ�
* �߂�l�F�~�V�������N���A���Ă��邩

******************************/


int Get_StageScore(void)

{

	return Stage_Score;

}

/*******************************

*�X�e�[�W����@�\�F�~�b�V�������擾����
* �����F���̃~�b�V�����ɕK�v�Ȑ��l
* �߂�l�F�Ȃ�

*********************************/


void Set_StageMission(int mission)
{

	Stage_Mission += mission;

}

/**************************************

*�X�e�[�W�����@�\�F�A�у`�F�b�N����
* ����1�F�u���b�NY�}�X
* ����2�F�u���b�NX�}�X
* �߂�l:�A���L���i�O:�����@�@�P:�L��j

*************************************/

int combo_check(int y, int x)
{
	int ret = FALSE

		//�c�����̃`�F�b�N

		int CountH = 0;

	int ColorH = 0;

	save_block();

	combo_check_h(y, x & CountH, &ColorH);

	if (CountH < 3)
	{
		restore_block();     //�O�����Ȃ�߂�
	}


	//�������̃`�F�b�N

	int CountW = 0;

	int ColorW = 0;

	save_block();

	combo_check_w(y, x, &CountW, &ColorW);

	if (CountW < 3)

	{

		restore_block();

	}

	//�R�ȏ�ŕ���ł��邩�H

	if ((CountH >= 3 || CountW >= 3))
	{
		if (CountH >= 3)

		{

			Item[ColorH - 1] += CountH;
			Stage_Score += CountH * 10;

		}

		if (CountW >= 3)

		{

			Item[ColorH - 1] += CountH;
			Stage_Score += CountH * 10;

		}

		ret = TRUE;

	}

	return ret;
	
}

/*********************

*�X�e�[�W����@�\�F�A���`�F�b�N�����i�c�����j
* ����:�Ȃ�
* �߂�l�F�A���L���i0�G�����@�@�@�P�F�L��@�@

*********************/

void combo_check_h(int y, int x, int* cnt, int* col)
{

	int Color = 0;

	//�Ώۃu���b�N���O�g�̏ꍇ��return�Ŕ�����

	if (Block[y][x].image == 0)
	{
		return;
	}

	*col = Block[y][x].image;

	Color = Block[y][x].image;

	Block[y][x].image = 0;

	(*cnt)++;



	if (Block[y + 1][x].image == Color)

	{
		combo_check_h(y + 1, x, cnt, col);

	}

	if (Block[y - 1][x].image == Color)

	{
		combo_check_h(y - 1, x, cnt, col);

	}

}


/*****************************************

*�X�e�[�W����@�\�F�A���`�F�b�N�����i�������j
* ����:�Ȃ�
* �߂�l�F�A���L���@�i�O:�Ȃ��@�@�P�L��j

**************************************/

void combo_check_w(int y, int x, int* cnt, int* col)

{

	int Color = 0;

	//�Ώۃu���b�N���O�g�̏ꍇreturn�ŏ����𔲂���

	if (Block[y][x].image == 0)

	{
		return;
	}

	*col = Block[y][x].image;
	Color = Block[y][x].image;
	Block[y][x].image = 0;
	(*cot)++;

	if (Block[y][x + 1].image == Color)

	{
		combo_check_w(y, x + 1,cnt, col);
	}

	if (Block[y][x - 1].image == Color)
	{
		combo_check_w(y, x - 1, cnt, col);
	}



}

/********************************

*�X�e�[�W����@�\�F�u���b�N���̕ۑ�����
* �����F�Ȃ�
* �߂�l�F�Ȃ�

******************************/


void save_block(void)

{

	int i, j;

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			Block[i][j].backup = Block[i][j].image;
		}
	}

}



/**************************************

*�X�e�[�W����@�\�F�u���b�N����߂��@�\
* �����F�Ȃ�
* �߂�l�F�Ȃ�

***************************************/


void restore_block(void)

{
	int i, j;

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			Block[i][j].image = Block[i][j].backup;
		}
	}



}
















