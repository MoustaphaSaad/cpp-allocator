#include <iostream>
#include <memory>
#include <chrono>
#include "LinearAllocator.hpp"
#include "StackAllocator.hpp"
#include "FallbackAllocator.hpp"

using namespace std;

struct dummy{
    double x,y,z;
};

MNAlloc::LinearAllocator<50*1024*1024> linear_alloc;
MNAlloc::StackAllocator<1*1024*1024> stack_alloc;
MNAlloc::FallbackAllocator<MNAlloc::StackAllocator<1*1024*1024>,MNAlloc::LinearAllocator<50*1024*1024>> fallback_alloc;


void malloc_test00(){
    dummy *ptr = (dummy*)malloc(sizeof(dummy));
    ptr->x = 0.0;
    ptr->y = 1.0;
    ptr->z = 2.0;
    free(ptr);
}

void malloc_test01(){
	std::chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i=0;i<5000000;i++){
        dummy *ptr = (dummy*)malloc(sizeof(dummy));
    }
	std::chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double> d = end-start;
	cout<<"malloc_test01 took around ~= "<<d.count()<<endl;
}

void linearAllocator_test00(){

}

void linearAllocator_test01(){
	std::chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i=0;i<5000000;i++){
        MNAlloc::Block ptr = linear_alloc.allocate(sizeof(dummy));
    }
	std::chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double> d = end-start;
	cout<<"linearAllocator_test01 took around ~= "<<d.count()<<endl;
}

void stackAllocator_test00(){

}

void stackAllocator_test01(){
	std::chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i=0;i<5000000;i++){
        MNAlloc::Block ptr = linear_alloc.allocate(sizeof(dummy));
    }
	std::chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double> d = end-start;
	cout<<"stackAllocator_test01 took around ~= "<<d.count()<<endl;
}

void fallbackAllocator_test00(){

}

void fallbackAllocator_test01(){
	std::chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    for(int i=0;i<5000000;i++){
        MNAlloc::Block ptr = fallback_alloc.allocate(sizeof(dummy));
    }
	std::chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double> d = end-start;
	cout<<"fallbackAllocator_test01 took around ~= "<<d.count()<<endl;
}

int main(){
    cout<<"Hello, World!"<<endl;
	malloc_test01();
	linearAllocator_test01();
	stackAllocator_test01();
    return 0;
}
