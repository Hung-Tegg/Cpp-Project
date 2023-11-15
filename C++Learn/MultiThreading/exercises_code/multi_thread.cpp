#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void func(int a)
{
    this_thread::sleep_for(std::chrono::seconds(a));
    cout << "This is the children " << a << " thread" << endl;
}

int main()
{
  thread a(func,1);
  thread b(func,2);
  thread c(func,3);
  a.join();
  b.join();
  c.join();
}