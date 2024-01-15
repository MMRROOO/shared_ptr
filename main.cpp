
template<typename P>
class ControlBlock{

    public:
    ControlBlock(P* object_ = nullptr): 
        object(object_), 
        shared_pointers(1)
    {}

    P* get_object(){
        return object;
    }

    void operator=(P* new_obj){  
        object = new_obj;
    }

    private:
    int shared_pointers;
    P* object;
};

template<typename P>
class sharedPtr{

    public:
    sharedPtr():
        control()
    {}

    void operator=(P* new_obj){
        control = new_obj;
    }

    
    P* get(){
        return stored_pointer;
    }

    private:
    ControlBlock<P> control;
    P* stored_pointer;
};
