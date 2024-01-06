#include "OrderConsumer.hpp"

int OrderConsumer::getId() {
    return id;
}

void OrderConsumer::update() {
    cout<<"Updating order consumer id:"<<id<<"\n";
}

OrderConsumer::OrderConsumer(int id) {
    this->id = id;
}
