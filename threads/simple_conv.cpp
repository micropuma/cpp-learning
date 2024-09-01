#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;

void consumer() {
    // locking
    unique_lock<mutex> lock(mtx);

    // waiting
    cv.wait(lock, [] { return data_ready; });

    cout << "Data consumed!" << endl;
}

void producer() {
    // Simulate data production
    this_thread::sleep_for(chrono::seconds(2));

    // use lock_guard to lock the mutex
    std::lock_guard<std::mutex> lck(mtx);

    // variable to avoid spurious wakeup
    data_ready = true;

    // logging notification to console
    cout << "Data Produced!" << endl;

    // notify consumer when done
    cv.notify_one();
}

// drive code
int main()
{
    thread consumer_thread(consumer);
    thread producer_thread(producer);

    consumer_thread.join();
    producer_thread.join();

        return 0;
}