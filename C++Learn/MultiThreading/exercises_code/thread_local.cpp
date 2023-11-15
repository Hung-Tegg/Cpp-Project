#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

using namespace std;

thread_local int a = 5;

void task_write()
{
    a = 100;
}

void task_read(int i)
{
    this_thread::sleep_for(100ms);
    
    a += i;

    cout << a << endl;
}

int main()
{
  
  thread b(task_read, 1);
  thread a(task_read, 1);
  thread ba(task_read, 1);
  thread ab(task_read, 1);
  a.join();
  b.join();
  ab.join();
  ba.join();
}