
#include <future>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void add(int a, int b, promise<int> pro)
{
  pro.set_value(a+b);
}

int main()
{
  promise<int> pro_local;
  future<int> fut_local = pro_local.get_future();
  thread thr(add,1,2,std::move(pro_local));
  thr.join();
  cout << fut_local.get() << endl;
}