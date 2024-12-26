#include <iostream>
#include <string>

using namespace std;

class Inu
{
	string name;
public:
	Inu(string);//sを省略
	void naku() const;
};

Inu::Inu(string s):name(s){}//コンストラクタの定義

void Inu::naku() const
{
	cout << "にゃあ。俺様は"<< name << "だ。" << endl;
}

int	main()
{
	string s;
	cout << "犬を生成します。名前を入力してください。" << endl;
	cin >> s;

	Inu dog(s);
	cout << "あなたの名付けた犬がメモリ上に生成されました。" << endl;
	cout << "犬が鳴きます。" << endl;
	dog.naku();
}