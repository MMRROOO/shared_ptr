#include <catch2/catch_all.hpp>
#include "SharedPtr.h"

TEST_CASE("testing correct number of pointers"){
    int* num = (new int(2));
    sharedPtr<int> a = sharedPtr(num);
    CHECK(a.get == num);
}