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
		cout << "º¯ÊýÔ½½ç" << endl;
	}
	return 0;
}
