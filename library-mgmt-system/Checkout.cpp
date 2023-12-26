#include "Checkout.hpp"

void Checkout::checkoutBook(Book* book, Patron* patron) {
    if(book->getAvailability()) {
        patron->checkoutBook(book);
        time_t dueTime = time(0) + DAY_SECONDS * 7;
        this->bookPatronMapping[book] = make_pair(patron, dueTime);
    } else {
        cout<<"Checkout | Book not available\n";
    }
}

void Checkout::returnBook(Book* book) {
    if(bookPatronMapping.count(book) == 1) {
        Patron* patron = bookPatronMapping[book].first;
        patron->returnBook(book);
        bookPatronMapping.erase(book);
    } else {
        cout<<"CHECKOUT | NOT CHECKED OUT\n";
    }
}

void Checkout::displayCheckouts() {
    // for(auto it : bookPatronMapping) {
        // cout<<"Book:"<<it.first->getName()<<", Patron:"<<it.second.first->getName()<<"\n";
    // }
    cout<<"Showing Books\n";
}

time_t Checkout::getDueDate(Book *book) {
    if(bookPatronMapping.count(book) == 1)
        return bookPatronMapping[book].second/DAY_SECONDS;
    else
        return -1;
}

double Checkout::calculateFine(Book *book) {
    time_t dueDate = bookPatronMapping[book].second;
    time_t currentTime = time(0);
    double secondsLate = difftime(currentTime,dueDate);
    if(secondsLate < 0) {
        return 0.0;
    } else {
        int daysLate = secondsLate/DAY_SECONDS;
        double fine = daysLate * 0.5;
        return min(fine, (double)MAX_FINE);
    }
}

        
