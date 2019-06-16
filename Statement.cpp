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
    for (auto &rental :  this->customer.getRentals()) {
        double amountForThisRental = 0;

        amountForThisRental = rental.getMovie().getAmount(rental.getDaysRented());
        this->frequentRenterPoints += rental.getMovie().getRenterPoints();

        // show figures for this rental
        result << rental.toString(amountForThisRental);

        this->totalAmount += amountForThisRental;
    }
    return result.str();
}
