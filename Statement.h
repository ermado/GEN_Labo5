#include <string>
#include <sstream>
#include "Customer.h"
#include "Movie.h"

#ifndef GEN_LABO5_STATEMENT_H
#define GEN_LABO5_STATEMENT_H

class Statement {

private:
    double totalAmount;
    int frequentRenterPoints;
    Customer customer;

public:

    Statement(Customer* customer) {
        this->customer = *customer;
        this->frequentRenterPoints = 0;
        this->totalAmount = 0;
    }

    std::string toString();
    std::string processRentals();

};

#endif //GEN_LABO5_STATEMENT_H
