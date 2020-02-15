#include <iostream>
#include <Initializer_List>
#include <vector>
#include <assert.h>

using namespace std;
template <class T1,class T2> void s_wap(T1& a,T2& b){
	T1 tmp;
	tmp = a;
	a = b;
	b = tmp;
}
template <class T3, class T4> bool compare(T3 a, T4 b)
{
	return a > b;
}
int main()
{
	int a = 30;
	int b = 20;
	double a1 = 98.1256;
	double a2 = 1233.12;

	s_wap(a, b);//隐式推导
	s_wap<double>(a1, a2);//显式推导
	
	cout << a << " " << b << endl;
	cout << a1 << " " << a2 << endl;
	cout << compare(a, a1);
	return 0;
}