#include <iostream>


template<typename P>
class sharedPtr{

    public:
    explicit sharedPtr(P* pointer_ = nullptr):
       stored_pointer(pointer_),
       count(new int(1))
    {}

    sharedPtr(const sharedPtr& pointer_):  
    stored_pointer(pointer_.stored_pointer),
    count(pointer_.count)
    {
        (*count)++;
    }
    

    // bool operator!=(sharedPtr other){
    //     return !(count == other.count && stored_pointer == other.stored_pointer);
    // }

    sharedPtr& operator=(sharedPtr& other){
        if (this != &other){
            count = other.count;
            stored_pointer = other.stored_pointer;
            (*count) ++;
            
        }
        return *this;
    }



    P* get(){
        return stored_pointer;
    }

    int get_copies_number(){
        return *count;
    }


    private:

    sharedPtr& copy(sharedPtr& shared_ptr){
        
    }


    int* count;
    P* stored_pointer;
};

int main(){

    int num = 2;
    sharedPtr<int> a = sharedPtr(&num);
    sharedPtr<int> b = sharedPtr(&num);

    b = a;
    std::cout << b.get_copies_number() << "\n";

    sharedPtr<int> c = b;

    
    std::cout << b.get_copies_number() << "\n";
    std::cout << a.get_copies_number() << "\n";

}