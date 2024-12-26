#include <iostream>
#include <string>

using namespace std;

class Neko
{
private:
	string name;
public:
	Neko(string s){
		name = s;
	}
	void naku(){
		cout << "にゃあ。俺様は"<< name << "だ。" << endl;
	}
};

int main()
{
	Neko dora("ボス");//doraによって、コンストラクタが実行され、doraがオブジェクトを表すようになる。
	cout << "あなたの名付けた猫がメモリ上に生成されました。" << endl;
	cout << "猫が鳴きます。" << endl;
	dora.naku();
}