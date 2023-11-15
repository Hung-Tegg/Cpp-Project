#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::chrono_literals;
using namespace std;
mutex mu;
void task()
{
  mu.lock();
  cout << "This is task 1" << endl;
  this_thread::sleep_for(1000ms);
  mu.unlock();
}

void task2()
{
  do{
    this_thread::sleep_for(100ms);
    cout << "This is task 2: Trying to lock mutex" << endl;
  } while(!(mu.try_lock()));
  
  cout << "This is task 2: success lock the mutex" << endl;
  mu.unlock();
}

int main()
{
  thread thr1(task);
  thread thr2(task2);
  thr1.join();
  thr2.join();
}