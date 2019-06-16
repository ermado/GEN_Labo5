#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockRental.h"
#include "MockCustomer.h"
#include "Statement.h"

using ::testing::Return;

/**
 * Les 3 types de films differents doivent avoir le bon nombre
 * de points client
 */
TEST(MovieTypesTest, CorrectNumberOfRentedPoints) {

    RegularMovie rMov("Inception");
    NewReleaseMovie nrMov("It 2");
    ChildrenMovie chMov("The Lion King");

    ASSERT_EQ(rMov.getRenterPoints(), 1);
    ASSERT_EQ(nrMov.getRenterPoints(), 2);
    ASSERT_EQ(chMov.getRenterPoints(), 1);
}

/**
 * On teste le correct fonctionnement de la fonction de calcul pour les RegularMovies
 */
TEST(RegularMovieTest, RegularTypeShouldGetCorrectTaxation) {

    RegularMovie rMov("Inception");
    // if rented for less than 2 days
    ASSERT_EQ(rMov.getAmount(1), 2);
    // if rented for more than 2 days
    ASSERT_EQ(rMov.getAmount(4), 5);

}

/**
 * On teste le fonctionnement de la fonction de calcul pour les RegularMovies dans le cas
 * d'une valeur limite en parametre afin d'eviter des situations de crash
 */
TEST(RegularMovieTestLimits, RegularMovieShouldNotCrashWithStrangeParameters) {

    RegularMovie rMov("Inception");
    // test avec 0
    ASSERT_EQ(rMov.getAmount(0), 2);
    // test avec negatif
    ASSERT_EQ(rMov.getAmount(-3), 2);

}

/**
 * On teste le correct fonctionnement de la fonction de calcul pour les NewReleaseMovie
 */
TEST(NewReleaseMovieTest, NewReleaseTypeShouldGetCorrectTaxation) {

    NewReleaseMovie rMov("Cats");

    ASSERT_EQ(rMov.getAmount(2), 6);
    ASSERT_EQ(rMov.getAmount(4), 12);

}

/**
 * On teste le fonctionnement de la fonction de calcul pour les NewReleaseMovies dans le cas
 * d'une valeur limite en parametre afin d'eviter des situations de crash
 */
TEST(NewReleaseMovieTestLimits, NewReleaseMovieShouldNotCrashWithStrangeParameters) {

    NewReleaseMovie rMov("M. Beans Holidays");
    // test avec 0
    ASSERT_EQ(rMov.getAmount(0), 0);
    // test avec negatif
    ASSERT_EQ(rMov.getAmount(-3), -9);

}

/**
* On teste le correct fonctionnement de la fonction de calcul pour les ChildrensMovies
*/
TEST(ChildrensMovieTest, ChildrensTypeShouldGetCorrectTaxation) {

    ChildrenMovie rMov("Murder On The Orient Express");
    // if rented for less than 2 days
    ASSERT_EQ(rMov.getAmount(1), 1.5);
    // if rented for more than 2 days
    ASSERT_EQ(rMov.getAmount(4), 3);
}

/**
 * On teste le fonctionnement de la fonction de calcul pour les ChildrensMovies dans le cas
 * d'une valeur limite en parametre afin d'eviter des situations de crash
 */
TEST(ChildrensMovieTestLimits, ChildrenMovieShouldNotCrashWithStrangeParameters) {

    ChildrenMovie rMov("M. Beans Holidays");
    // test avec 0
    ASSERT_EQ(rMov.getAmount(0), 1.5);
    // test avec negatif
    ASSERT_EQ(rMov.getAmount(-3), 1.5);

}