
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class FooBarAusgabe{
    int zaehler_;
    std::mutex mtx_;
    std::condition_variable cond_;

    public:
        FooBarAusgabe(){ zaehler_ = 0;};
        ~FooBarAusgabe(){};

        void runFoo(){
            for(int i = 0; i < 10; i++){
                foo();
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
        }

        void runBar(){
            for(int i = 0; i < 10; i++){
                bar();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

        void foo(){
            std::unique_lock<std::mutex> lock(mtx_);
            if(zaehler_ % 2 != 0)
                cond_.wait(lock);
            std::cout << "foo";
            zaehler_++;
            cond_.notify_one();
        }
        void bar(){
            std::unique_lock<std::mutex> lock(mtx_);
            if(zaehler_ % 2 == 0)
                cond_.wait(lock);
            std::cout << "bar " << std::endl;
            zaehler_++;
            cond_.notify_one();
        }
};

int main()
{
    // Aendern Sie hier nichts!!!
    FooBarAusgabe foo_bar_ausgabe;

    std::thread t1(&FooBarAusgabe::runBar, &foo_bar_ausgabe);
    std::thread t2(&FooBarAusgabe::runFoo, &foo_bar_ausgabe);

    t1.join();
    t2.join();

    return 0;
}