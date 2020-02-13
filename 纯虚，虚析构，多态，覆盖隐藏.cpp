#include <iostream>

using namespace std;

class gan{
public:
	virtual void gana() = 0;//纯虚类,只能被继承不能直接被调用
};

class cao :public gan{
public:
	void gana(){
		cout << "这里是纯虚类继承过来的" << endl;
	}
};

class skull{
public:
	skull()
	{
		cout << "构造了" << endl;
	}
	virtual void func(int a)
	{
		cout << "fuck虚1 " << endl;
	}
	virtual void func(double b)
	{
		cout << "fuck虚2" << endl;
	}
	virtual ~skull(){
		cout << "虚析构了" << endl;
	}
};
class skull2 :public skull{
	int a;
public:
	skull2()
	{
		cout << "skull2构造了" << endl;
	}


};

class fw{

public:
	void fangjia(int i){
		cout << "放假了" << endl;
	}
	virtual void fangjia2(){
		cout << "放假了2" << endl;
	}
};

class caonima :public fw {
public:
	void fangjia(int i){
		cout << "放你妈逼假" << endl;
	}
	virtual void fangjia2(){
		cout << "放假你妈比2" << endl;
	}

};


int main()
{
	//skull2 ptr;
	//cao pt;
	//pt.gana();
	fw f;
	caonima c;
	fw *a = &c;
	caonima *b = &c;

	a->fangjia(1);
	b->fangjia2();

	
	

	return 0;
}