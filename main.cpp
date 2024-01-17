#include "SharedPtr.h"


// using namespace SharedPtr;

int main(){
    int* num = (new int(2));
    SharedPtr<int> a = SharedPtr(num);
    SharedPtr<int> b = a;

}

