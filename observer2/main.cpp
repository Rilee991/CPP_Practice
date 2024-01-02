#include <iostream>
#include <list>
using namespace std;

class Subscriber {
    protected:
        int id;
    public:
        virtual void consume(string msg) = 0;
        virtual int getId() = 0;
};

class Consumer: public Subscriber {
    public:
        Consumer(int id) {
            this->id = id;
        }
        
        int getId() {
            return id;
        }

        void consume(string msg) {
            cout<<"Message recieved by consumer:"<<id<<". Msg:"<<msg<<endl;
        }
};

class Topic {
    list<Subscriber*> consumers;

    public:
        void subscribe(Subscriber *c) {
            consumers.push_back(c);
        }

        void unsubscribe(Subscriber *c) {
            for(int i=0;i<consumers.size();i++) {
                // if(consumers[i]->getId() == c->getId()) {
                //     consumers.erase(consumers.begin()+i);
                // }
                consumers.remove(c);
            }
        }

        void publish(string msg) {
            for(auto consumer : consumers) {
                consumer->consume(msg);
            }
        }
};

int main() {
    Topic *topic = new Topic();

    Consumer *c1 = new Consumer(1);
    Consumer *c2 = new Consumer(2);
    Consumer *c3 = new Consumer(3);

    topic->subscribe(c1);
    topic->subscribe(c2);
    topic->subscribe(c3);

    topic->publish("Message 1 published by topic");
    topic->unsubscribe(c2);
    topic->publish("Message 2 published by topic");

    return 0;
}