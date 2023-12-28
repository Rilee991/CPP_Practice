#include<iostream>
#include<thread>
#include "DbConnection.hpp"
using namespace std;

void createInstanceDb() {
    DbConnection* dbConnection = DbConnection::getDbConnection();
    dbConnection->connectToDb();
}

int main() {
    thread t1(createInstanceDb), t2(createInstanceDb), t3(createInstanceDb);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}