#include <iostream>
#include <Initializer_List>
#include <vector>
#include <assert.h>
#include <memory>
using namespace std;
class tool{
public:
	tool()
	{
		cout << "tool������" << endl;
	}
	~tool()
	{
		cout << "tool������" << endl;
	}
};
void run(){
	
	tool* p = new tool();//��������ָ�벻�������ͷ����ռ�
	auto_ptr<tool> ptr(p);
	auto_ptr<tool> ptr2(ptr);
	auto_ptr<tool> ptr3;
	ptr3 = ptr2;//ptr1��ptr2����Ϊ�գ��Ѿ���ֵ����ptr3

}
template<class T>
class L_autoPtr :public tool{
	T* obj = nullptr;
public:
	L_autoPtr(T* ptr) :obj(ptr){};
	L_autoPtr() = default;
	~L_autoPtr(){
		delete obj;
	}
	L_autoPtr(L_autoPtr<T>& ptr){
		obj = ptr.obj;
		ptr.obj=nullptr;
	}
	L_autoPtr& operator=(L_autoPtr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = nullptr;

	}
	T* release(){
		auto tmpa = obj;
		obj = nullptr;
		return tmpa;
	}
	T& operator*(){
		return *obj;
	}
	T* operator->(){
		return obj;
	}
	T* ger(){
		return obj;
	}
};

int main()
{
	run();


	return 0;
}