#ifndef logger_hpp
#define logger_hpp

#include<string>
#include<mutex>
using namespace std;

class Logger {
    private:
        Logger();
        static mutex mtx;
        static Logger* loggerInstance;
    
    public: 
        static int ctr;
        void log(string msg);
        static Logger* createLogger();
};

#endif