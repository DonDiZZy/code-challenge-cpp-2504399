
#include <iostream>
#include <thread>
#include "semaphore.h"

class BrotBauer
{
private:
    pthread_barrier_t thread_barriere;
    sem_t brot_semaphor;
    sem_t kaese_semaphore;

public:
    BrotBauer()
    {
        pthread_barrier_init(&thread_barriere, 0, 3); // Benoetigen genau 3 threads um die barriere zu erreichen
        sem_init(&brot_semaphor, 0, 2);               // Benoetigen zwei Brote
        sem_init(&kaese_semaphore, 0, 1);             // Benoetigen einen Kaese
    };
    ~BrotBauer(){};

    void runBrot()
    {
        for (int i = 0; i < 10; i++)
        {
            brot();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void runKaese()
    {
        for (int i = 0; i < 10; i++)
        {
            kaese();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    void brot()
    {
        sem_wait(&brot_semaphor);               // Zwei Brot-threads koennen den Semaphor passieren
        pthread_barrier_wait(&thread_barriere); // Muessen auf den 3. Kaese-thread warten
        std::cout << "Brot";
        sem_post(&brot_semaphor);
    }

    void kaese()
    {
        sem_wait(&kaese_semaphore);             // only one oxygen can arrive
        pthread_barrier_wait(&thread_barriere); // but wait for 3 threads at this barrier, 2 of twhich must be hydrogen
        std::cout << "Kaese";
        sem_post(&kaese_semaphore);
    }
};

int main()
{
    BrotBauer brot_bauer;

    std::thread t1(&BrotBauer::runKaese, &brot_bauer);
    std::thread t2(&BrotBauer::runBrot, &brot_bauer);
    std::thread t3(&BrotBauer::runBrot, &brot_bauer);
    std::thread t4(&BrotBauer::runKaese, &brot_bauer);
    std::thread t5(&BrotBauer::runBrot, &brot_bauer);
    std::thread t6(&BrotBauer::runBrot, &brot_bauer);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    return 0;
}