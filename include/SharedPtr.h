#ifndef SHAREDPTR_H
#define SHAREDPTR_H



template<typename P>
class SharedPtr{

    public:
    explicit SharedPtr(P* pointer_ = nullptr);

    SharedPtr(const SharedPtr& pointer_);

    ~SharedPtr();
    

    // bool operator!=(sharedPtr other){
    //     return !(count == other.count && stored_pointer == other.stored_pointer);
    // }

    SharedPtr& operator=(SharedPtr& other);

    P& operator*();

    P& operator->();

    void reset(P* ptr);

    void swap(SharedPtr& ptr);


    P* get();

    int use_count();


    private:


    void remove();

    int* count;
    P* stored_pointer;


};

#endif