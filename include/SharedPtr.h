#ifndef SHAREDPTR_H
#define SHAREDPTR_H

template<typename P>
class SharedPtr {
public:
    explicit SharedPtr(P* pointer_ = nullptr);
    SharedPtr(SharedPtr<P>& pointer_);
    ~SharedPtr();

    SharedPtr<P>& operator=(const SharedPtr<P>& other);

    P& operator*();
    P* operator->();

    void reset(P* ptr);
    void swap(SharedPtr<P>& ptr);

    P* get();
    int use_count();

private:
    void remove();
    int* count;
    P* stored_pointer;
};

#endif
