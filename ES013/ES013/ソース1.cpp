#include<stdio.h>

int search(int* a, int n, int key) {

	int i;
	a[n] = key;
	i = 0;

	while (key != a[i]) {
		i++;
	}
	if (i == n) {
		printf("エラー");
		i = -1;
	}
	return i;
}

int main(void)
{
	int key;
	int a[7] = { 1003,1012,1053,1031,1021,1075,0 };

	int alen = sizeof(a) / sizeof(int);

	printf("車両番号を入力してください（4桁の半角文字）");
	scanf_s("%d", &key);

	printf("入力データの添え字は%d", search(a, alen - 1, key));

}
