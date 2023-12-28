#ifndef DB_HPP
#define DB_HPP
#include<iostream>
#include<mutex>
using namespace std;

class DbConnection {
    static int ctr;
    static DbConnection* dbInstance;
    static mutex mtx;
    DbConnection();
    public:
    DbConnection(DbConnection &dbConn);
        void connectToDb();
        static DbConnection* getDbConnection();
};

#endif