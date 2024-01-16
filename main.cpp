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

    ~sharedPtr(){
        remove();
    }
    

    // bool operator!=(sharedPtr other){
    //     return !(count == other.count && stored_pointer == other.stored_pointer);
    // }

    sharedPtr& operator=(sharedPtr& other){

        if (this != &other){
            remove();
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


    void remove(){

        (*count) --;
        if ((*count) == 0){
            delete count;

            if (stored_pointer){

                delete stored_pointer; 
            }
        }
    }

    private:


    int* count;
    P* stored_pointer;


};

int main(){

    int* num = (new int(2));
    sharedPtr<int> a = sharedPtr(num);
    sharedPtr<int> b = a;

    // b = a;
    std::cout << "number should be 2: "<< b.get_copies_number() << "\n";

    sharedPtr<int> c = b;

    
    std::cout << "number should be 3: "<<b.get_copies_number() << "\n";
    std::cout << "number should be 3: "<<a.get_copies_number() << "\n";
    int* num2 = (new int(3));

    sharedPtr<int> d = sharedPtr(num2);
    a = d;
    std::cout << "number should be 2: "<< b.get_copies_number() << "\n";
    std::cout << "number should be 2: "<< a.get_copies_number() << "\n";


    std::cout << "done\n";

}