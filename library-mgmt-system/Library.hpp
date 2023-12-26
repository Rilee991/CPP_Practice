#pragma once
// #ifndef Library_hpp
// #define Library_hpp
#include <vector>
#include "Book.hpp"
using namespace std;

class Library {
    vector<Book*> books;
    
    public:
        void addBook(Book* book);
        void removeBook(string isbn);
        Book* searchBookByIsbn(string isbn);
        void displayBooks();
};

// #endif