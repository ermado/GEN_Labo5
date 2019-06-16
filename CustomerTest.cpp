#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockRental.h"
#include "MockMovie.h"
#include "MockCustomer.h"
#include "Statement.h"

using ::testing::Return;

/**
 * Test de la fonction statement de Customer (sans Mocking)
 */
TEST(StatementTest, CanWriteFullStatementForCustomer) {

    Customer customer("Edoardo Carpita");

    RegularMovie movie1("Top Gun");
    Rental rental1(&movie1, 32);
    customer.addRental(rental1);

    NewReleaseMovie movie2("Titanic");
    Rental rental2(&movie2, 4);
    customer.addRental(rental2);

    ChildrenMovie movie3("Invade Poland for dummies");
    Rental rental3(&movie3, 150);
    customer.addRental(rental3);

    std::string st = customer.statement();

    ASSERT_EQ(st, "Rental Record for Edoardo Carpita\n\tTop Gun	47\n\tTitanic	12\n\tInvade Poland for dummies	222\n"
            "Amount owed is 281\n"
            "You earned 4 frequent renter points");
}