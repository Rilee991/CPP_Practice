#include "PaymentsConsumer.hpp"

int PaymentsConsumer::getId() {
    return id;
}

void PaymentsConsumer::update() {
    cout<<"Updating payments consumer id:"<<id<<"\n";
}

PaymentsConsumer::PaymentsConsumer(int id) {
    this->id = id;
}