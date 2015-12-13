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

//write here something
//look @ facebook
/** Somrthing xD
comments area

first thing let's include memory header since we'll use memory allocations
**you include it**
What do you mean by memeory header ? :'D I never used this lib before :'D
okay next Nice

i meant this

first thing to know is allocations in cpp happens using "new" operators and deletion happens
using "delete" operators
but at the end of the day new & delete is based on "malloc" and "free"
so here we'll talk about malloc & free instead

here's malloc syntax, we'll use it to allocate one dummy object and then free it

- so as you can see malloc returns a void* of the same size as dummy then we cast it
the strange thing is that however malloc cares about the size free doesn't care about it
in the free call we only provided the pointer to be freed and never pass the size
so how does free manage this thing ?
- malloc cares about the first position so I guess that free takes the first memory allocation and mark this place as deleted ,
 so no other pointer can exceed
- so what you saying is malloc/free operate as a stack-like allocator?
-Kinda
- well, no. what really happens is that malloc inserts the size near the space allocated some what before it
 then when free is called it's simply looks the size and free it somewhat like that, this is not good practice but dunno
 anyway we are gonna make ourself a custom allocator that is better then malloc/free one
 let's start by defining an interface for the allocator and the first actual allocator
 can you still see the IAllocator.hpp file ?
 - I have no tile but untiiled.cpp

 - ok then it has an IAllocator class in it

 - the problem about malloc and free is that malloc and free doesn't have a way to incorporate
  size other than that .. i mean malloc just returns "void*" no idea what the size of this pointer is
  so the signatures of our functions should change it should have someway of returning the size of the pointer
  with the pointer itself something like this new class called "Block.hpp"
  so you change our signatures to use the new class which called "Block"

  FUNCTION SIGNATURES not to put a member object

 - Ok, let's start with the simplist allocator ever the null allocator, how do you think this allocator works?
 -Block has size should be ziro , and what was the other thing wait , and the pointer should be null.

 -Good, now you implement it i will make the file for you
  now that we have a null allocator which can allocate an infinite amount of nulls :D
  we need to implement another allocator which is a real one this time :D


  I think we are mainapulating this :'D  we only used a void * too and a size
  but we did not use the malloc function okay we did our own :'D


  somewhat yes but this will enable us to make more sophisticated allocators

  Hai, let's see! \m/ Where are yoooooooooooooooooooou
  leaving me here alone eh2 eh2 eh2

  thinking about the new allocator
  our new allocator will be "The Fallback Allocator"
  which means it's an allocator which has two allocators one is primary the other is Fallback
  and it starts allocating with the primary and when it fails it uses the Fallback
  mmmmm
  let's start

  back here ... let's make an approprite allocator this time let's call it malloc wrapper it simple passes the allocation
  to malloc
  ok?

  ok you will write it
 */

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
