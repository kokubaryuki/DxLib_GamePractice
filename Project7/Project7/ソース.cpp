#include<stdio.h>

#include<string>



int main(void) {

	int key i;


	//配列未尾に番兵となるデータを入れる領域を確認する

	int carNO[7]={1003,1012,1053,1031,1021,1075,0 }
	std::string carName[6] = { "X1","A3","F5","B6","P7","R6" };



	printf("車両番号を入力してください（四桁の番号）");
	scanf_s("%d, &key");

	//配列未尾に番兵となるデータとしてこの入力データを入れておく


	carNo[6] = key;

	i = 0;

	//目的の車両番号が見つけるまで線形検索を行う
	//データがなくても最後に必ずkeyとcarNoが一致してループが終了する
	//比較する項目が一つ減るのでプログラムが高速に動作する


	while (key != carNo[i]) {

		i++

	}

	//c_str()デ,c＋＋の文字列えをprintf()で表示できるように交換する

	if (i < 6) {
		printf("車種名は")
			printf("%s　です。\n", carName[i].c_str());

	}

	else {

		prinf("データエラー");
	}




}











