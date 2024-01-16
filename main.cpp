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

    P& operator*(){
        return *stored_pointer;
    }

    P& operator->(){
        return *stored_pointer;
    }

    void reset(P* ptr){
        remove()
        count = new int(1);
        stored_pointer = ptr;
    }

    void swap(sharedPtr& ptr){
        std::swap(ptr.count, count);
        std::swap(ptr.stored_pointer, stored_pointer);
    }



    P* get(){
        return stored_pointer;
    }

    int use_count(){
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
    std::cout << "number should be 2: "<< b.use_count() << "\n";

    sharedPtr<int> c = b;

    
    std::cout << "number should be 3: "<<b.use_count() << "\n";
    std::cout << "number should be 3: "<<a.use_count() << "\n";
    int* num2 = (new int(3));

    sharedPtr<int> d = sharedPtr(num2);
    a = d;
    std::cout << "number should be 2: "<< d.use_count() << "\n";
    std::cout << "number should be 2: "<< a.use_count() << "\n";


    std::cout << "done\n";

}