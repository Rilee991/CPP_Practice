#pragma once
// #ifndef partron_hpp
// #define patron_hpp
#include <iostream>
#include <vector>
#include "Book.hpp"
using namespace std;

class Patron {
    vector<Book*> checkedoutBooks;
    string name;
    string id;

    public:
        Patron(string n, string i);
        void returnBook(Book* book);
        void checkoutBook(Book* book);
        string getName();
        string getId();
};

// #endif