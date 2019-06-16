#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockMovie.h"
#include "MockRental.h"
#include "MockCustomer.h"
#include "MockStatement.h"
#include "Statement.h"

using ::testing::Return;
using ::testing::ReturnPointee;

/**
 * Test de la fonction processRentals de Statement.h
 * Dans notre idee, on voulait tester cette classe de cette facon, mais le push_back de *rental
 * ne focntionne pas correctement. Cause le manque de temps pour trouver une solution cette
 * faille et aux autres engendrés par mocking (voire classe MockMovie) ,
 * on a ete donc obligés à commenter ce test et tester les differents elements d'una eutre facon
 */
/*TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {

    MockCustomer customer;
    auto* rental = new MockRental();
    auto* rentalList = new std::vector<MockRental>;
    auto* movie = new MockMovie();

    EXPECT_CALL(*movie, getRenterPoints()).WillRepeatedly(Return(20));
    EXPECT_CALL(*movie, getTitle()).WillRepeatedly(Return("Babar"));
    EXPECT_CALL(*movie, getAmount(10)).WillRepeatedly(Return(50));

    EXPECT_CALL(*rental, getMovie()).WillRepeatedly(ReturnPointee(movie));
    EXPECT_CALL(*rental, getDaysRented()).WillRepeatedly(Return(10));

    rentalList->push_back(*rental);
    EXPECT_CALL(customer, getRentals()).WillRepeatedly(ReturnPointee(rentalList));

    Statement statement(&customer);
    EXPECT_EQ(statement.processRentals(), "Babar\t50\n");

}*/

TEST(StatementTest, CanWriteFullStatementForCustomer) {

    auto customer = new Customer("Edoardo Carpita");

    RegularMovie movie1("Top Gun");
    Rental rental1(&movie1, 32);
    customer->addRental(rental1);

    NewReleaseMovie movie2("Titanic");
    Rental rental2(&movie2, 4);
    customer->addRental(rental2);

    ChildrenMovie movie3("Invade Poland for dummies");
    Rental rental3(&movie3, 150);
    customer->addRental(rental3);

    Statement statement(customer);

    ASSERT_EQ(statement.toString(), "Rental Record for Edoardo Carpita\n\tTop Gun	47\n\tTitanic	"
                          "12\n\tInvade Poland for dummies	222\n"
                  "Amount owed is 281\n"
                  "You earned 4 frequent renter points");

    delete customer;

}

