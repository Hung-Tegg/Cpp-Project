#include <iostream>
#include <thread>
#include <future>

using namespace std;

int task(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    packaged_task<int(int,int)> p_task(task);
    future<int> fut = p_task.get_future();
    // thread thr(move(p_task),10,20);
    // thr.join();
    p_task(10,20);
    cout << fut.get() << endl;
}