#pragma once
// #ifndef checkout_hpp
// #define checkout_hpp
#include <map>
#include <iostream>
#include "Book.hpp"
#include "Patron.hpp"

class Checkout {
    map<Book*,pair<Patron*,time_t> > bookPatronMapping;
    const int DAY_SECONDS = 60*60*24;
    const int MAX_FINE = 10;

    public:
        void checkoutBook(Book* book, Patron* patron);
        void returnBook(Book* book);
        void displayCheckouts();
        time_t getDueDate(Book *book);
        double calculateFine(Book *book);
};

// #endif