#include <catch2/catch_all.hpp>
#include "SharedPtr.h"

using namespace Catch;

class value {
    public:
    value(int _number, int _number2):
        number(_number),
        number2(_number2)
    {}
    int number;
    int number2;
};
TEST_CASE("test gets pointer out of shared pointer"){
    int* num = (new int(2));
    SharedPtr<int> a = SharedPtr(num);
    CHECK(a.get() == num);

}

TEST_CASE("test get correct number of uses"){
    int* num = (new int(2));
    int* num2 = (new int(3));

    SharedPtr<int> a = SharedPtr(num);
    SharedPtr<int> b = a;
    CHECK(a.use_count() == 2);

    a = b;
    CHECK(a.use_count() == 2);
    a = SharedPtr(num2);
    CHECK(a.use_count() == 1);
    b = a;
    CHECK(b.use_count() == 2);
}

TEST_CASE("test dereferencing"){

    

    value* num = (new value(1,2));

    SharedPtr<value> a = SharedPtr(num);
    
    CHECK(a->number == num->number);
    CHECK((*a).number == (*num).number);
}

TEST_CASE("test reset"){
    
    int* num = (new int(2));

    SharedPtr<int> a = SharedPtr(num);
    SharedPtr<int> b = a;
    a.reset(new int(1));
    
    CHECK(*a == 1);
    CHECK(a.use_count() == 1);

}


TEST_CASE("test swap"){
    
    int* num = (new int(1));

    int* num2 = (new int(2));


    SharedPtr<int> a = SharedPtr(num);
    SharedPtr<int> b = a;


    SharedPtr<int> c = SharedPtr(num2);

    CHECK((*a == 1 && *b == 1 && *c == 2 && a.use_count() == 2 && c.use_count() == 1));
    a.swap(c);
    CHECK((*a == 2 && a.use_count() == 1));
    CHECK((*b == 1 && b.use_count() == 2));
    CHECK((*c == 1 && c.use_count() == 2));
}