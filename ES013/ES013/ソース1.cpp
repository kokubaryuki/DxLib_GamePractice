#include<stdio.h>

int search(int* a, int n, int key) {

	int i;
	a[n] = key;
	i = 0;

	while (key != a[i]) {
		i++;
	}
	if (i == n) {
		printf("�G���[");
		i = -1;
	}
	return i;
}

int main(void)
{
	int key;
	int a[7] = { 1003,1012,1053,1031,1021,1075,0 };

	int alen = sizeof(a) / sizeof(int);

	printf("�ԗ��ԍ�����͂��Ă��������i4���̔��p�����j");
	scanf_s("%d", &key);

	printf("���̓f�[�^�̓Y������%d", search(a, alen - 1, key));

}
