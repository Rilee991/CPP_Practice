#include "Patron.hpp"

Patron::Patron(string n, string i) {
    name = n;
    id = i;
}

void Patron::returnBook(Book* book) {
    for(int i=0;i<checkedoutBooks.size();i++) {
        if(checkedoutBooks[i]->getISBN() == book->getISBN()) {
            book->returnBook();
            checkedoutBooks.erase(checkedoutBooks.begin()+i);
            cout<<"Book returned by "<<name<<"\n";
            return;
        }
    }

    cout<<"You("<<name<<") didn't checked out this book\n";
}

void Patron::checkoutBook(Book* book) {
    if(book->getAvailability()) {
        book->checkout();
        checkedoutBooks.push_back(book);
        cout<<"Book checkedout to "<<name<<endl;
    } else {
        cout<<"Book not available\n";
    }
}

string Patron::getName() {
    return name;
}

string Patron::getId() {
    return id;
}
