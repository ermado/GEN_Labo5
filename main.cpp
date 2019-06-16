#include <iostream>

#include "Customer.h"
#include "Customer.cpp"
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockRental.h"
#include "MockMovie.h"
#include "MockCustomer.h"
#include "Statement.h"

int main(int argc, char **argv) {

//    Customer customer("Olivier");
//    customer.addRental( Rental( Movie("Karate Kid"), 7));
//    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
//    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));
//
//    std::cout << customer.statement() << std::endl;

    ::testing::InitGoogleTest();
    //::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();

}

