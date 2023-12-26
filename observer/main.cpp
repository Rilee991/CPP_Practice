#include<iostream>
#include<vector>
using namespace std;

class ISubscriber {
    public:
        virtual void notify(string msg){};
};

class User: public ISubscriber {
    private:
        int userId;
    public:
        User(int userId) {
            this->userId = userId;
        }

        void notify(string msg) {
            cout<<"User "<<this->userId<<" got msg:"<<msg<<"\n";
        }
};

class Group {
    private:
        vector<ISubscriber*> users;
    public:
        void subscribe(ISubscriber* userId) {
            users.push_back(userId);
        }

        void unsubscribe(ISubscriber* userId) {
            vector<ISubscriber*> newList;
            for(int i=0;i<users.size();i++) {
                if(users[i] != userId) newList.push_back(users[i]);
            }
            this->users = newList;
        }

        void notify(string msg) {
            for(int i=0;i<users.size();i++) {
                users[i]->notify(msg); //->notify(msg);
            }
        }
};

int main() {
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("new msg");

    group->unsubscribe(user1);

    group->notify("new msg");

    return 0;
}