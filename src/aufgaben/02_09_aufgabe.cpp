
#include <iostream>
#include <thread>
#include <mutex>

class ZaehlerImpl{
    private:
        int zaehler_;
        std::mutex zaehler_mutex_;


    public:
        ZaehlerImpl(){ zaehler_ = 0;};
        ~ZaehlerImpl(){};

        void erhoeheZahler(int zahl){
            // todo implementieren Sie hier eine thread safe erhoehung um zahl
             std::lock_guard<std::mutex> lock{zaehler_mutex_};
             std::cout << "Erhoehe um " << zahl << std::endl;             
             zaehler_+=zahl;
        }

        void ausgabeZaehler(){
            std::cout << "Zaehler ist " << zaehler_ << std::endl;
        }
};

int main()
{
    ZaehlerImpl zaehler_impl;

    std::thread t1(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 10);
    std::thread t2(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 1);
    std::thread t3(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 6);
    std::thread t4(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 8);
    std::thread t5(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 4);
    std::thread t6(&ZaehlerImpl::erhoeheZahler, &zaehler_impl, 2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout << "Zaehler sollte 31 sein." << std::endl;
    zaehler_impl.ausgabeZaehler();

    return 0;
}