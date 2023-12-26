#include <iostream>
#include "Library.hpp"
#include "Book.hpp"
#include "Patron.hpp"
#include "Checkout.hpp"

using namespace std;

int main () {
    Library library;
    Book *book1 = new Book("Verity", "1", "Coolen Hoover");
    Book *book2 = new Book("Rudest Book Ever", "2", "Shwetabh Gangwar");
    Book *book3 = new Book("The Silent Widow", "3", "Sidney Sheldon");

    Patron *patron1 = new Patron("Rohit", "1");
    Patron *patron2 = new Patron("Mohit", "2");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    Checkout checkout;
    checkout.checkoutBook(book1, patron1);
    checkout.checkoutBook(book2, patron2);
    checkout.checkoutBook(book2, patron1);

    time_t dueTime = checkout.getDueDate(book1);
    double fine = checkout.calculateFine(book1);
    cout<<"Due Time:"<<dueTime<<", fine:"<<fine;

    return 0;
}