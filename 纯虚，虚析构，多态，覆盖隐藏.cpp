#include <iostream>

using namespace std;

class gan{
public:
	virtual void gana() = 0;//������,ֻ�ܱ��̳в���ֱ�ӱ�����
};

class cao :public gan{
public:
	void gana(){
		cout << "�����Ǵ�����̳й�����" << endl;
	}
};

class skull{
public:
	skull()
	{
		cout << "������" << endl;
	}
	virtual void func(int a)
	{
		cout << "fuck��1 " << endl;
	}
	virtual void func(double b)
	{
		cout << "fuck��2" << endl;
	}
	virtual ~skull(){
		cout << "��������" << endl;
	}
};
class skull2 :public skull{
	int a;
public:
	skull2()
	{
		cout << "skull2������" << endl;
	}


};

class fw{

public:
	void fangjia(int i){
		cout << "�ż���" << endl;
	}
	virtual void fangjia2(){
		cout << "�ż���2" << endl;
	}
};

class caonima :public fw {
public:
	void fangjia(int i){
		cout << "������Ƽ�" << endl;
	}
	virtual void fangjia2(){
		cout << "�ż������2" << endl;
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