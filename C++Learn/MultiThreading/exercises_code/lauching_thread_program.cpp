/* Write a thread */

#include <thread>
#include <iostream>

using std::thread;

void func_run_by_thread()
{
    std::cout << "Hello Thread Program " << std::this_thread::get_id() <<  std::endl;
}

int main()
{
  thread thr(func_run_by_thread);
  thr.join();
  std::cout << "Hello Program by main thread " << std::this_thread::get_id() << std::endl;
}