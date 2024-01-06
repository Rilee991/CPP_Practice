#include "Publisher.hpp"

void Publisher::addConsumers(Consumer* consumer) {
    consumers.push_back(consumer);
}

void Publisher::removeConsumers(Consumer* consumer) {
    consumers.remove(consumer);
}

void Publisher::updateConsumers() {
    for(auto consumer: consumers) {
        consumer->update();
    }
}
