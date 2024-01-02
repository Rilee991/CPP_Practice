#include<iostream>
#include "OrderConsumer.hpp"
using namespace std;

OrderConsumer::OrderConsumer(int id) {
    this->id = id;
}

void OrderConsumer::processData() {
    cout<<"Data processed for consumer:"<<id<<"\n";
}

int OrderConsumer::getId() {
    return id;
}