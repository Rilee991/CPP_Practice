#include<iostream>
#include "DbConnection.hpp"
using namespace std;

int DbConnection::ctr = 0;
DbConnection* DbConnection::dbInstance = NULL;
mutex DbConnection::mtx;

DbConnection::DbConnection() {
    cout<<"Db Instance created:"<<++ctr<<"\n";
}

DbConnection::DbConnection(DbConnection &dbConn) {
    cout<<"Db Instance created using copy constructor:"<<++ctr<<"\n";
}

void DbConnection::connectToDb() {
    cout<<"Db Connected\n";
}

DbConnection* DbConnection::getDbConnection() {
    cout<<"Thread entered\n";
    if(!dbInstance) {
        mtx.lock();
        cout<<"Thread locked\n";
        if(!dbInstance) {
            dbInstance = new DbConnection();
        }
        cout<<"Thread unlocking\n";
        mtx.unlock();
    }
    cout<<"Thread exited\n";

    return dbInstance;
}
