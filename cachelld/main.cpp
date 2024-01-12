#include <iostream>
#include <map>
using namespace std;

struct Node {
    string key;
    string data;
    Node* next;
    Node* prev;

    Node(string key, string data) {
        this->data = data;
        this->key = key;
        next = prev = NULL;
    }
};

class EvictionPolicy {
    public:
        virtual string get(Node* node) = 0;
        virtual Node* put(string key, string value, Node* node, int& currCap, int maxCap, map<string,Node*> &cache) = 0;
};

class LRU: public EvictionPolicy {
    Node *head;
    Node *last;

    void moveToFront(Node* node) {
        if(!node)   return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        head->prev = node;
        head = node;
    }

    void removeLast() {
        if(!last)   return;
        if(head == last) {
            free(head);
            free(last);
            head = last = NULL;
            return;
        }

        last->prev->next = NULL;
        Node *newLast = last->prev;
        free(last);
        last = newLast;
    }

    void addToFront(Node* node) {
        if(!node)   return;

        if(!head) {
            head = last = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    public:
        LRU() {
            head = NULL;
            last = NULL;
        }

        string get(Node* node) {
            if(!node)   return NULL;
            if(head == node)    return node->data;
            moveToFront(node);
            return node->data;
        }

        Node* put(string key, string value, Node* node, int& currCap, int maxCap, map<string,Node*> &cache) {
            if(node) {
                node->data = value;
                moveToFront(node);
            } else {
                if(currCap == maxCap) {
                    cache.erase(last->key);
                    removeLast();
                }
                if(currCap < maxCap) currCap++;

                node = new Node(key, value);
                addToFront(node);
            }

            return node;
        }
};

class LFU: public EvictionPolicy {
    
};

class Cache {
    int maxCap;
    int currCap;
    map<string,Node*> cache;
    EvictionPolicy* evictionPolicy;
    public:
        Cache(int cap) {
            maxCap = cap;
            currCap = 0;
            evictionPolicy = new LRU();
            print("Cache initialised");
        }
        string get(string key) {
            print("Cache GET START");
            if(cache.find(key) == cache.end())   return "-1";

            string val = evictionPolicy->get(cache[key]);
            print("Cache GET END");
            return val;
        }
        void put(string key, string value) {
            print("Cache PUT START");
            cache[key] = evictionPolicy->put(key, value, cache[key], currCap, maxCap, cache);
            print("Cache PUT END");
        }

        void print(string msg = "") {
            cout<<msg<<"\n";
            for(auto it: cache) {
                cout<<it.first<<"->"<<it.second->data<<"\n";
            }
        }
};

int main() {
    Cache *cache = new Cache(3);
    
    cout<<cache->get("1")<<"\n";//-1
    cout<<cache->get("2")<<"\n";//-1
    cache->put("1", "Rohit");//1-Rohit
    cache->put("2", "Mohit");//2-Mohit, 1-Rohit
    cache->put("3", "Sohit");//3-Sohit, 2-Mohit, 1-Rohit
    cout<<cache->get("2")<<"\n";//Mohit
    cout<<cache->get("3")<<"\n";//Sohit
    cache->put("4", "Lohit");//4-Lohit, 3-Sohit, 2-Mohit
    cout<<cache->get("1")<<"\n";//-1
}