
#include <algorithm>
#include "SharedPtr.h"

template<typename P>
SharedPtr<P>::SharedPtr(P* pointer_):
    stored_pointer(pointer_),
    count(new int(1))
{}

template<typename P>
SharedPtr<P>::SharedPtr(SharedPtr<P>& pointer_):
    stored_pointer(pointer_.stored_pointer),
    count(pointer_.count)
{   
    if (this != &pointer_) {
        (*this->count)++;
    }
}

template<typename P>
SharedPtr<P>::~SharedPtr(){
    remove();
}

template<typename P>
SharedPtr<P>& SharedPtr<P>::operator=(const SharedPtr<P>& other){
    if (this != &other){
        remove();
        count = other.count;
        stored_pointer = other.stored_pointer;
        (*count)++;
    }
    return *this;
}

template<typename P>
P& SharedPtr<P>::operator*(){
    return *stored_pointer;
}

template<typename P>
P* SharedPtr<P>::operator->(){
    return stored_pointer;
}

template<typename P>
void SharedPtr<P>::reset(P* ptr){
    remove();
    count = new int(1);
    stored_pointer = ptr;
}

template<typename P>
void SharedPtr<P>::swap(SharedPtr<P>& ptr){
    std::swap(ptr.count, count);
    std::swap(ptr.stored_pointer, stored_pointer);
}

template<typename P>
P* SharedPtr<P>::get(){
    return stored_pointer;
}

template<typename P>
int SharedPtr<P>::use_count(){
    return *count;
}

template<typename P>
void SharedPtr<P>::remove(){
    (*count)--;
    if ((*count) == 0){
        delete count;
        if (stored_pointer){
            delete stored_pointer; 
        }
    }
}