#include <iostream>
#include "SharedPtr.h"


// template<typename P>
// SharedPtr<P>::SharedPtr(P* pointer_):


// template<typename P>
// SharedPtr<P>::SharedPtr(SharedPtr<P>& pointer_):  


// template<typename P>
// SharedPtr<P>::~SharedPtr(){
//         remove();
//     }


// bool operator!=(SharedPtr other){
//     return !(count == other.count && stored_pointer == other.stored_pointer);
// }
// template<typename P>
// SharedPtr<P>& SharedPtr<P>::operator=(SharedPtr& other){

//     if (this != &other){
//         remove();
//         count = other.count;
//         stored_pointer = other.stored_pointer;
//         (*count) ++;
        
//     }

//     return *this;
// }

// template<typename P>
// P&  SharedPtr<P>::operator*(){
//     return *stored_pointer;
// }

// template<typename P>
// P&  SharedPtr<P>::operator->(){
//     return *stored_pointer;
// }

// template<typename P>
// void  SharedPtr<P>::reset(P* ptr){
//     remove();
//     count = new int(1);
//     stored_pointer = ptr;
// }

// template<typename P>
// void  SharedPtr<P>::swap(SharedPtr& ptr){
//     std::swap(ptr.count, count);
//     std::swap(ptr.stored_pointer, stored_pointer);
// }

// template<typename P>
// P*  SharedPtr<P>::get(){
//     return stored_pointer;
// }

// template<typename P>
// int  SharedPtr<P>::use_count(){
//     return *count;
// }


// template<typename P>
// void  SharedPtr<P>::remove(){

//     (*count) --;
//     if ((*count) == 0){
//         delete count;

//         if (stored_pointer){

//             delete stored_pointer; 
//         }
//     }
// }


// int main(){

//     int* num = (new int(2));
//     SharedPtr<int> a = SharedPtr(num);
//     SharedPtr<int> b = a;

//     // b = a;
//     std::cout << "number should be 2: "<< b.use_count() << "\n";

//     SharedPtr<int> c = b;

    
//     std::cout << "number should be 3: "<<b.use_count() << "\n";
//     std::cout << "number should be 3: "<<a.use_count() << "\n";
//     int* num2 = (new int(3));

//     SharedPtr<int> d = SharedPtr(num2);
//     a = d;
//     std::cout << "number should be 2: "<< d.use_count() << "\n";
//     std::cout << "number should be 2: "<< a.use_count() << "\n";


//     std::cout << "done\n";

// }