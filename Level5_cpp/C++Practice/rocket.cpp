#include <iostream>

using namespace std;

class Rocket {
	int nenryo;
	int sokudo;
public:
	Rocket(int x);//コンストラクタ
	void kasoku();
};

//コンストラクタの定義
Rocket::Rocket(int x):nenryo(x),sokudo(0){}

//加速を表すメンバ関数の定義
void Rocket::kasoku()
{
	if(nenryo >= 2){
		sokudo += 2;
		nenryo -= 2;
		cout << "現在の燃料は" << nenryo << "です。" << endl;
		cout << "現在の速度は" << sokudo << "です。" << endl;
	}else{
		cout << "燃料切れです。加速できません。" << endl;
	}
}

int	main()
{
	int x;
	cout << "ロケットを生成します。燃料を入力してください。" << endl;
	cin >> x;

	Rocket ohtori(x);
	cout << "ロケットが生成されました。" << endl;

	while(1){
		cout << "1---加速、2---終了:";
		int a;
		cin >> a;
		if(a == 1){
			ohtori.kasoku();
		}else{
			break;
		}
	}
	cout << "ロケットを消去します。" << endl;
}