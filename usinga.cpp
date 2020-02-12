#include <iostream>
using I = int;//I 代替int
using namespace std;

class skull2{
public:
	skull2(const skull2& ptr) :m_ptr(new int(*ptr.m_ptr))
	{
		cout << "深拷贝" << endl;
	}
	skull2(skull2 &&ptr) :m_ptr(ptr.m_ptr)
	{
		ptr.m_ptr = nullptr;
		cout << "移动构造" << endl;
	}
private:
	int* m_ptr;
};





int main()
{
	
	
	

	return 0;
}