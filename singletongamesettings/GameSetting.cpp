#include<iostream>
#include<string>
#include<thread>
#include<mutex>

using namespace std;

class GameSetting {
    static GameSetting* instance;
    static mutex mtx;
    int brightness;
    int width;
    int height;
    GameSetting(int b, int w, int h) {
        cout<<"Constructor called\n";
        brightness = b;
        width = w;
        height = h;
    }
    
    public:
        int getBrightness() {
            return this->brightness;
        }
        void setBrightness(int brightness) {
            this->brightness = brightness;
        }
        int getWidth() {
            return this->width;
        }
        void setWidth(int width) {
            this->width = width;
        }
        int getHeight() {
            return this->height;
        }
        void setHeight(int height) {
            this->height = height;
        }
        static GameSetting* getInstance(int b, int w, int h) {
            if(!instance) {
                instance = new GameSetting(b,w,h);
            }

            return instance;
        }
        void displaySettings() {
            cout<<"Brightness:"<<brightness<<", Height:"<<height<<", Width:"<<width<<"\n";
        }
};

GameSetting* GameSetting::instance = NULL;

void someFunction() {
    GameSetting* gInstance = GameSetting::getInstance(10,2,5);
    gInstance->setBrightness(10);
    gInstance->setWidth(2);
    gInstance->setHeight(5);
    gInstance->displaySettings();
}

int main() {
    // GameSetting* instance = GameSetting::getInstance(100, 50, 44);
    // instance->displaySettings();
    // someFunction();
    // instance->displaySettings();
    thread t1(someFunction), t2(someFunction);
    t1.join();
    t2.join();
    return 0;
}