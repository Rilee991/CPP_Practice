#include "Library.hpp"

void Library::addBook(Book* book) {
    this->books.push_back(book);
    cout<<"Book added\n";
}

void Library::removeBook(string isbn) {
    for(int i=0;i<this->books.size();i++) {
        if(books[i]->getISBN() == isbn) {
            this->books.erase(books.begin()+i);
            cout<<"Book removed successfully\n";
            return;
        }
    }

    cout<<"Book not present in library\n";
}

Book* Library::searchBookByIsbn(string isbn) {
    for(int i=0;i<this->books.size();i++) {
        if(this->books[i]->getISBN() == isbn) {
            cout<<"Book found\n";
            return books[i];
        }
    }

    cout<<"404. Book not found\n";
    return NULL;
}

void Library::displayBooks() {
    for(int i=0;i<this->books.size();i++) {
        cout<<"Title:"<<books[i]->getTitle()<<"\n";
    }
}
