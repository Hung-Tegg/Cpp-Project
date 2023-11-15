/*
  Write the hello thread program by adding a function
    The function takes a std::thread object as argument
    It displays the object's thread ID
  Pass the std::thread object created in main() to this function
  Where, if anywhere, should join() be called
*/

#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;
using namespace std;

void HelloThread(thread threadObj)
{
    cout << "Thread id of the thread: " << threadObj.get_id() << endl;
    threadObj.join();
}

void Process()
{
    cout << " Processing" << endl;
}

thread ReturnThread()
{
    
    return thread(Process);
}

void ThrowException()
{
    try
    {
      throw(exception());
    }
    catch(...)
    {
      cout << " meet a exception" << endl;
    }
}

int main()
{
  // Thread call to function return thread object
  thread a(ReturnThread());
  cout << a.get_id() << endl;
  a.join();

  // Thread call to function need to pass the thread object
  thread thr(Process);
  HelloThread(std::move(thr));


  thread threadException(ThrowException);
  threadException.join();
} 