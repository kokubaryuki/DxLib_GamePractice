#include<stdio.h>


int main(void)

{


	int i, j;

	i = 0;

	j = 0;



	int b[3][4];

	for (i = 0; i < 3; i++) {

		for (j = 0; j < 4; j++) {

			b[i][j] = 0;

			printf("b[%d][%d]=%d\n",i, j, b[i][j]);

		}


	}



}