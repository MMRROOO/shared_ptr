#ifndef SHAREDPTR_H
#define SHAREDPTR_H



template<typename P>
class SharedPtr{

    public:
    explicit SharedPtr(P* pointer_ = nullptr):    
        stored_pointer(pointer_),
        count(new int(1))
    {}

    SharedPtr(SharedPtr<P>& pointer_):
        stored_pointer(pointer_.stored_pointer),
        count(pointer_.count)
    {   
        (*count)++;
    }

    ~SharedPtr(){
        remove();
    }
    

    // bool operator!=(sharedPtr other){
    //     return !(count == other.count && stored_pointer == other.stored_pointer);
    // }

    SharedPtr<P>& operator=(SharedPtr<P>& other){

        if (this != &other){
            remove();
            count = other.count;
            stored_pointer = other.stored_pointer;
            (*count) ++;   
        }

        return *this;
    }


    P& operator*(){
        return *stored_pointer;
    }

    P& operator->(){
        return *stored_pointer;
    }


    void reset(P* ptr){
        remove();
        count = new int(1);
        stored_pointer = ptr;
    }

    // void swap(SharedPtr<P>& ptr){
    //     std::swap(ptr.count, count);
    //     std::swap(ptr.stored_pointer, stored_pointer);
    // }

    P* get(){
        return stored_pointer;
    }


    int use_count(){
        return *count;
    }

    private:


    void remove(){
        (*count) --;
        if ((*count) == 0){
            delete count;

            if (stored_pointer){

                delete stored_pointer; 
            }
        }
    }

    int* count;
    P* stored_pointer;


};

#endif