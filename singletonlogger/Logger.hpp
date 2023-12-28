#include <iostream>
#include <mutex>
using namespace std;

class Logger {
    static int ctr;
    static Logger* instance;
    static mutex mtx;
    Logger();
    public:
        void logMsg(string msg);
        static Logger* getLogger();
};
