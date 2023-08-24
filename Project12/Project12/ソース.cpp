#include"DxLib.h"

#define NAME_LEN (128)

typedef struct

{

	int no;

	char name[NAME_LEN];

	int unm;

}Student;


Student students[3];

void File_Read(void);

void Students_Disp(void)



 int WINAPI WinMain(_In_HINSTANCE ih, _In_opt_HINSTANSE inh, _In_LPSTR il, int ii)

{

	ChangeWindowMode(TRUE);


	if (DxLib_Init() == -1)
	{
		return-1;
	}

	File_Read();

	Students_Disp();

	WaitKey();

	DxLib_End();

	return 0;


}

void File_Read(void)

{
	FILE*fp;

	char str[256];

	fopen_s(&fp, "date/Students.csv", "r");



	if (fp == NULL)

	{
		return;
	}

	eles

	{
		for (int i = 0; i < 3; i++)

		{

			fgets(str, 256, fp);

			sscanf_f("%d,%S,%d", str, &students[i].no, sstudent[i].name, NAME_LEN,
				&students[i].num);

		}

	fclose(fp);

	}

}

void Students_Disp(void)
{

	for (int i = 0; i < 3; i++)
	{
		DrawFormatString(20(20 + (20 * i)), GetColor(255, 255, 255),
			"%d%10%d", students[i].no, students[i].name, students[i].num);


	}



}


























