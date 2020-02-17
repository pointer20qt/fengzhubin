#include <iostream>
#include <Initializer_List>
#include <vector>
#include <assert.h>
#include <memory>
using namespace std;


template<class T>
class ref{
	int r_count;//�������
	T* object = nullptr;
public:
	ref(T* target) :object(target){
		++r_count;   //���캯��,ָ���һ
	}
	inline void increase()
	{
		r_count++;
	}
	inline void decrease()
	{
		r_count--;
		if (r_count == 0){//��������Ϊ0ʱ��֤���Ѿ�û��ָ��ָ��������󣬴�ʱ��������������������
			delete object;
			delete this;
		}
	}
	T* get(){//��öԶ���
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
	shared() = default;//�޲ι���
	shared(T* newp){
			reff = new ref<T>(newp);//����ָ�빹��	
	}
	shared(const shared& other)//��������
	{
		reff = other.reff;
		if (reff){
			reff->increase();
		}
	}
	shared(shared&& other)//�ƶ�����
	{
		swap(reff, other.reff);
	}
	shared& operator=(const shared& other){//���ز������ڿ��������е�
		if (reff){
			reff->decrease();
		}
		reff = other.reff;
		if (reff){
			reff->increase();
		}
		return *this;
	}
	shared& operator=(shared&& other){//���ز��������ƶ������е�
		if (reff){
			reff->decrease();
		}
		reff = other.reff;
		other.reff = nullptr;
		return *this;
	}
	void swap(shared& other){ //����
		swap(reff, other.reff);
	}
	~shared(){//����
		if (reff)
		{
			reff->decrease();
		}
	}
	void reset(T* target = nullptr){//reset ����
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
	int use_count(){//�鿴��������
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool unique(){
		if (ref){
			return ref->getCount() == 1;//�ж��Ƿ�Ψһ
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