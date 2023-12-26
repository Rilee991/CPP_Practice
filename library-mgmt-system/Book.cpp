#include "Book.hpp"

Book::Book(string t, string i, string a) {
    this->author = a;
    this->title = t;
    this->isbn = i;
    this->availability = true;
}

void Book::checkout() {
    if(this->availability) {
        this->availability = false;
        cout<<"Book checkedout successfully\n";
    } else {
        cout<<"Book is unavailable. Please select another\n";
    }
}

void Book::returnBook() {
    this->availability = true;
    cout<<"Book has been returned successfully\n";
}

string Book::getTitle() {
    return this->title;
}

string Book::getAuthor() {
    return this->author;
}

bool Book::getAvailability() {
    return this->availability;
}

string Book::getISBN() {
    return this->isbn;
}
