#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> arr;
	arr.push_back(1);
	try{
		arr.at(2);

	}
	catch (out_of_range &errora)
	{
		cout << "����Խ��" << endl;
	}
	return 0;
}
