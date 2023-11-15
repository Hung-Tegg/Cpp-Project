/* 
  Print out the thread id of the thread function
  Print out the id of main thread
  Print out the thread id of the thread function by main thread in 2 case:
    after calling join for thread function
    before calling join for thead function
*/

#include <thread>
#include <iostream>
#include <chrono>

using std::thread;
using namespace std::literals;
void func_run_by_thread()
{
  std::cout << "Hello Thread Program " << std::this_thread::get_id() <<  std::endl;
}

int main()
{
  thread thr(func_run_by_thread);
  std::cout << "Hello Program by main thread " << std::this_thread::get_id() << std::endl;
  thr.join();

  std::cout << "Thread hello has id is: " << thr.get_id() << std::endl;
  
}