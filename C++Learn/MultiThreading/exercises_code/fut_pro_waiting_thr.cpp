#include <iostream>
#include <thread>
#include <future>

using namespace std;

void produce(promise<int>&& pro)
{
    pro.set_value(117);
}

void consume(shared_future<int> fut)
{
    cout << fut.get() << endl;
}


int main()
{
    promise<int> pro;
    shared_future<int> fut = pro.get_future();
    //shared_future<int> shared_fut = fut.share();
    thread producer(produce, move(pro));
    thread consumer(consume, (fut));
    thread consumer2(consume, fut);
    producer.join();
    consumer.join();
    consumer2.join();
}