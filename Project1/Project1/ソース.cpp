#include<stdio.h>

int main(void)
{

	int i,j;

	//C����ł̓񎟌��z��̐錾�Ə�������i�s�Ɨ�j

	int ma[9][9];

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			int[i][j] = (i + 1) * (j + 1);
			printf("%3d", ma[i][j]);

		}
		printf("n\");
	}
	

}