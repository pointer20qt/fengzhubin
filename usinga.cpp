#include <iostream>
using I = int;//I ´úÌæint
using namespace std;

class skull2{
public:
	void pulsa(I a, I b)
	{
		int c = 0;
		c = a + b;
		cout << c << endl;
	}
};



class skull{
private:
	friend void skull2::pulsa(I a, I b);
};


int main()
{
	skull2 ptr;
	ptr.pulsa(1,2);
	
	

	return 0;
}