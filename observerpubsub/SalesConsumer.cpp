#include "SalesConsumer.hpp"

int SalesConsumer::getId() {
    return id;
}

void SalesConsumer::update() {
    cout<<"Updating Sales consumer id:"<<id<<"\n";
}

SalesConsumer::SalesConsumer(int id) {
    this->id = id;
}