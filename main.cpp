#include <iostream>

#include "Customer.h"
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockRental.h"
#include "MockCustomer.h"
#include "Statement.h"

int main(int argc, char **argv) {

    ::testing::InitGoogleTest();
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();

}

