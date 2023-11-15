#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

void produce(promise<int>&& pro)
{
    exception_ptr a;
    pro.set_exception(a);

}

void consume(future<int>&& fut)
{
    cout << fut.get() << endl;
    
}

int main()
{
    promise<int> pro;
    future<int> fut = pro.get_future();
    thread thr(produce,move(pro));
    thread thr1(consume, move(fut));
thr.join();
thr1.join();
}
