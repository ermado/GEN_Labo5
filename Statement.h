#include <string>
#include <sstream>
#include "Customer.h"

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
    }

    /**
     * Calcule la facture du client
     * @return
     */
    std::string toString() {
        std::ostringstream result;
        auto iter = this->customer.getRentals().begin();
        auto iter_end = this->customer.getRentals().end();
        result << "Rental Record for " << this->customer.getName() << "\n";

        for ( ; iter != iter_end; ++iter ) {
            double thisAmount = 0;
            Rental each = *iter;

            // determine amounts for each line
            switch ( each.getMovie().getPriceCode() ) {
                case Movie::REGULAR:
                    thisAmount += 2;
                    if ( each.getDaysRented() > 2 )
                        thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
                    break;
                case Movie::NEW_RELEASE:
                    thisAmount += each.getDaysRented() * 3;
                    break;
                case Movie::CHILDRENS:
                    thisAmount += 1.5;
                    if ( each.getDaysRented() > 3 )
                        thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
                    break;
            }

            // add frequent renter points
            this->frequentRenterPoints++;
            // add bonus for a two day new release rental
            if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
                 && each.getDaysRented() > 1 ) this->frequentRenterPoints++;

            // show figures for this rental
            result << "\t" << each.getMovie().getTitle() << "\t"
                   << thisAmount << "\n";
            this->totalAmount += thisAmount;
        }
        // add footer lines
        result << "Amount owed is " << this->totalAmount << "\n";
        result << "You earned " << this->frequentRenterPoints
               << " frequent renter points";

        return result.str();
    }
};

#endif //GEN_LABO5_STATEMENT_H
