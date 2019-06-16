#include "Statement.h"

std::string Statement::toString() {
    this->frequentRenterPoints = 0;
    std::ostringstream result;
    result << "Rental Record for " << this->customer.getName() << "\n";

    result << this->processRentals();

    // add footer lines
    result << "Amount owed is " << this->totalAmount << "\n";
    result << "You earned " << this->frequentRenterPoints
    << " frequent renter points";

return result.str();
}

/* Parcourt la liste des rentals et les insere dans la facture */
std::string Statement::processRentals() {

    std::ostringstream result;
    auto iter = this->customer.getRentals().begin();
    auto iter_end = this->customer.getRentals().end();

    for ( ; iter != iter_end; ++iter ) {
        double amountForThisRental = 0;

        Rental each = *iter;

        amountForThisRental = each.getMovie().getAmount(each.getDaysRented());
        this->frequentRenterPoints += each.getMovie().getRenterPoints();

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << amountForThisRental << "\n";
        this->totalAmount += amountForThisRental;
    }
    return result.str();
}

int Statement::getFrequentRenterPoints() const {
    return this->frequentRenterPoints;
}