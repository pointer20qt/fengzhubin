#include <iostream>
#include <Initializer_List>
#include <vector>
#include <assert.h>
#include <memory>
using namespace std;


template<class T>
class ref{
	int r_count;//定义计数
	T* object = nullptr;
public:
	ref(T* target) :object(target){
		++r_count;   //构造函数,指针加一
	}
	inline void increase()
	{
		r_count++;
	}
	inline void decrease()
	{
		r_count--;
		if (r_count == 0){//当计数记为0时，证明已经没有指针指向这个对象，此时析构对象，析构计数函数
			delete object;
			delete this;
		}
	}
	T* get(){//获得对对象
		return object;
	}
	int getcount()
	{
		return r_conut;
	}
};


template<class T> class shared{
	ref<T>* reff = nullptr;
public:
	shared() = default;//无参构造
	shared(T* newp){
			reff = new ref<T>(newp);//传递指针构造	
	}
	shared(const shared& other)//拷贝构造
	{
		reff = other.reff;
		if (reff){
			reff->increase();
		}
	}
	shared(shared&& other)//移动构造
	{
		swap(reff, other.reff);
	}
	shared& operator=(const shared& other){//重载操作符在拷贝构造中的
		if (reff){
			reff->decrease();
		}
		reff = other.reff;
		if (reff){
			reff->increase();
		}
		return *this;
	}
	shared& operator=(shared&& other){//重载操作符在移动构造中的
		if (reff){
			reff->decrease();
		}
		reff = other.reff;
		other.reff = nullptr;
		return *this;
	}
	void swap(shared& other){ //交换
		swap(reff, other.reff);
	}
	~shared(){//析构
		if (reff)
		{
			reff->decrease();
		}
	}
	void reset(T* target = nullptr){//reset 功能
		if (reff){
			reff->decrease();
		}
		if (target != nullptr){
			reff = new ref<T>(target);
		}
		else{
			reff = nullptr;
		}
	}
	T& operator*(){
		if (reff){
			return *reff->get();
		}
		else{
			return *(T*)nullptr;
		}
	}
	T* operator->(){
		if (reff){
			return reff->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	T* get(){
		if (reff){
			return reff->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	int use_count(){//查看关联数量
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool unique(){
		if (ref){
			return ref->getCount() == 1;//判断是否唯一
		}
		else{
			return false;
		}
	}


};


int main()
{
	


	return 0;
}