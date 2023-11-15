#include <iostream>
#include <thread>
#include <chrono>
#include <shared_mutex>
#include <vector>

using namespace std::chrono_literals;

using namespace std;
shared_mutex mu;
int a = 5;
void task_reader()
{
    mu.lock_shared();
    cout << a;
    this_thread::sleep_for(100ms);
    mu.unlock_shared();
}
void task_writer()
{
    mu.lock();
    a = 15;
    mu.unlock();
}

int main()
{
  vector<thread> thr_reader1;
  vector<thread> thr_writer;
  vector<thread> thr_reader2;

  for(int i = 0; i < 20; i++)
  {
    thr_reader1.push_back(thread(task_reader));
  }

  for(int i = 0; i < 2;i++)
  {
    thr_writer.push_back(thread(task_writer));
  }

  for(int i = 0; i < 20;i++)
  {
    thr_reader2.push_back(thread(task_reader));
  }

  for(auto& thr : thr_reader1)
  {
    thr.join();
  }
  for(auto& thr : thr_reader2)
  {
    thr.join();
  }
  for(auto& thr : thr_writer)
  {
    thr.join();
  }
  
}