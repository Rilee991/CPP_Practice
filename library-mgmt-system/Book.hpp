#pragma once
// #ifndef Book_hpp
// #define Book_hpp
#include <iostream>
using namespace std;

class Book {
    string title;
    string isbn; // primary key
    string author;
    bool availability;

    public:
        Book(string t, string i, string a);
        void checkout();
        void returnBook();
        string getTitle();
        string getAuthor();
        bool getAvailability();
        string getISBN();
};

// #endif