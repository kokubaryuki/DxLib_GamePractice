#include<stdio.h>

int main(void)
{

	int i, j, g;
	int a[5][5] = { {1,8,7,3,1},{6,5,4,8,9},{2,3,4,5,6} };
	int x[5] = { 0,0,0,0,0 };
	int y[5] = { 0,0,0,0,0 };
	g = 0;


	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			x[i] = x[i] + a[i][j];
			y[j] = y[j] + a[i][j];
		}
		g = x[i] + g;
	}
	printf("”z—ñ‚Ì‡Œv’l%d\n", g);
}

