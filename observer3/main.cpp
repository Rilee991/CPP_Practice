#include<iostream>
#include "OrderConsumer.hpp"
#include "Topic.hpp"
using namespace std;

int main() {
    Consumer* c1 = new OrderConsumer(1);
    Consumer* c2 = new OrderConsumer(2);
    Consumer* c3 = new OrderConsumer(3);

    Topic* topic = new Topic();
    topic->displayConsumers();

    topic->subscribe(c1);
    topic->subscribe(c2);
    topic->subscribe(c3);
    topic->displayConsumers();

    topic->notifyAll();

    topic->unsubscribe(c2);
    topic->notifyAll();
    topic->displayConsumers();
}