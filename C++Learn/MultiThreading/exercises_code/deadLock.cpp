#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mu1;
mutex mu2;


void task1()
{
    cout <<  " Task 1 trying to lock mu1" << endl;
    mu1.lock();
    this_thread::sleep_for(chrono::milliseconds(100));
    cout <<  "Task 1 locked mu1 and trying to lock mu2" << endl;
    while(!mu2.try_lock())
    {
        cout << "Task 1 trying to lock mu2" << endl;
    }
    mu1.unlock();
    mu2.unlock();
}

void task2()
{
    cout <<  " Task 2 trying to lock mu2" << endl;
    mu2.lock();
    cout <<  "Task 2 locked mu2 and trying to lock mu1" << endl;
    mu1.lock();
    mu2.unlock();
    mu1.unlock();
}


int main()
{
    thread thr1(task1);
    thread thr2(task2);
    thr1.join();
    thr2.join();
}