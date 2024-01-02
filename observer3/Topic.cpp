#include <list>
#include <iostream>
#include "Topic.hpp"

void Topic::subscribe(Consumer* c) {
    this->consumers.push_back(c);
}
void Topic::unsubscribe(Consumer* c) {
    this->consumers.remove(c);
}
void Topic::displayConsumers() {
    cout<<"Total consumers:"<<consumers.size()<<"\n";
    for(auto it : consumers) {
        cout<<it->getId()<<", ";
    }
    cout<<"\n";
}
void Topic::notifyAll() {
    cout<<"Notifying consumers\n";
    for(auto it : consumers) {
        it->processData();
    }
}
