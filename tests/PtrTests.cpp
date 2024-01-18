#include <catch2/catch_all.hpp>
#include "SharedPtr.h"

using namespace Catch;


TEST_CASE("test gets pointer out of shared pointer"){
    int* num = (new int(2));
    sharedPtr<int> a = sharedPtr(num);
    CHECK(a.get() == num);

}

TEST_CASE("test get correct number of uses"){
    int* num = (new int(2));
    int* num2 = (new int(3));

    sharedPtr<int> a = sharedPtr(num);
    sharedPtr<int> b = a;
    CHECK(a.use_count() == 2);

    sharedPtr<int> a = b;
    CHECK(a.use_count() == 2);
    sharedPtr<int> a = sharedPtr(num2);
    CHECK(a.use_count() == 1);
    CHECK(b.use_count() == 1);
}

TEST_CASE("test dereferencing"){
    class animal{
        public:
        animal():
            sound("bark"){}
        
        string sound;
    }
    

    animal* dog = (new animal);

    sharedPtr<animal> a = sharedPtr(dog);
    
    CHECK(a->sound == dog->sound);
    CHECK(*a.sound == *dog.sound);
}

TEST_CASE("test reset"){
    
    int* num = (new int(1));

    sharedPtr<int> a = sharedPtr(num);
    a.reset(new int(1));
    
    CHECK(*a == 2);
}