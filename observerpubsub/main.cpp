#include "Publisher.hpp"
#include "OrderConsumer.hpp"
#include "SalesConsumer.hpp"
#include "PaymentsConsumer.hpp"

int main() {
    Publisher *publisher = new Publisher();

    Consumer* o1 = new OrderConsumer(1);
    Consumer* o2 = new OrderConsumer(2);
    Consumer* o3 = new OrderConsumer(3);

    Consumer* s1 = new SalesConsumer(1);
    Consumer* s2 = new SalesConsumer(2);
    Consumer* s3 = new SalesConsumer(3);

    Consumer* p1 = new PaymentsConsumer(1);
    Consumer* p2 = new PaymentsConsumer(2);
    Consumer* p3 = new PaymentsConsumer(3);

    publisher->addConsumers(o1);
    publisher->addConsumers(o2);
    publisher->addConsumers(o3);

    publisher->addConsumers(s1);
    publisher->addConsumers(s2);
    publisher->addConsumers(s3);

    publisher->addConsumers(p1);
    publisher->addConsumers(p2);
    publisher->addConsumers(p3);

    publisher->updateConsumers();

    publisher->removeConsumers(o1);
    publisher->removeConsumers(s2);
    publisher->removeConsumers(p3);

    publisher->updateConsumers();
}
