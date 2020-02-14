#include <iostream>
#include <Initializer_List>
#include <vector>
#include <assert.h>
using namespace std;
static_assert(sizeof(int) != 32, "不成立");//在程序执行前执行，判断int占位
class vec{
	int* cao;
public:
	vec(initializer_list<int> aar){
		cao = new int[aar.size()];
		aar.begin();
		aar.end();
		for (auto i = aar.begin(); i != aar.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
		for (auto i = 0; i < aar.size(); i++)
		{
			cao[i] = *(aar.begin() + i);
		}
	}
	int& operator[](unsigned int index){//int& 返回的值才可修改
		assert(index >= 0);
		printf("%d", index);
		return cao[index];
	}



};


int main()
{
	vec v({0,2,14,5,1,1,5,415,1});
	cout << v[2] << endl;
	v[2] = 5;
	cout << v[2] << endl;
	return 0;
}