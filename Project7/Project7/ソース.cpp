#include<stdio.h>

#include<string>



int main(void) {

	int key i;


	//�z�񖢔��ɔԕ��ƂȂ�f�[�^������̈���m�F����

	int carNO[7]={1003,1012,1053,1031,1021,1075,0 }
	std::string carName[6] = { "X1","A3","F5","B6","P7","R6" };



	printf("�ԗ��ԍ�����͂��Ă��������i�l���̔ԍ��j");
	scanf_s("%d, &key");

	//�z�񖢔��ɔԕ��ƂȂ�f�[�^�Ƃ��Ă��̓��̓f�[�^�����Ă���


	carNo[6] = key;

	i = 0;

	//�ړI�̎ԗ��ԍ���������܂Ő��`�������s��
	//�f�[�^���Ȃ��Ă��Ō�ɕK��key��carNo����v���ă��[�v���I������
	//��r���鍀�ڂ������̂Ńv���O�����������ɓ��삷��


	while (key != carNo[i]) {

		i++

	}

	//c_str()�f,c�{�{�̕����񂦂�printf()�ŕ\���ł���悤�Ɍ�������

	if (i < 6) {
		printf("�Ԏ햼��")
			printf("%s�@�ł��B\n", carName[i].c_str());

	}

	else {

		prinf("�f�[�^�G���[");
	}




}











