#include <iostream>
using I = int;//I ����int
using namespace std;

class skull2{
public:
	skull2(const skull2& ptr) :m_ptr(new int(*ptr.m_ptr))
	{
		cout << "���" << endl;
	}
	skull2(skull2 &&ptr) :m_ptr(ptr.m_ptr)
	{
		ptr.m_ptr = nullptr;
		cout << "�ƶ�����" << endl;
	}
private:
	int* m_ptr;
};





int main()
{
	
	
	

	return 0;
}