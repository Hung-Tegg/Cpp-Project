#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
using namespace std::chrono_literals; 


using namespace std;

vector<int> dataFromNetwork;
vector<int> buffer;
float process_status;

mutex update_m;
mutex done_m;
condition_variable update_c;
condition_variable done_c;


void fetchData()
{
    for(auto& data : dataFromNetwork)
    {
        update_m.lock(); 
        buffer.push_back(data);
        update_m.unlock();
        update_c.notify_all();
        this_thread::sleep_for(10us);
    }
}

void displayProcess()
{
    while (1) 
    {
        cout << process_status << endl ;
        unique_lock<mutex> update_u(update_m);
        update_c.wait(update_u);
        process_status = static_cast<float>(static_cast<float>(buffer.size()) / static_cast<float>(dataFromNetwork.size()));
        if (process_status == 1)
        {
            done_c.notify_all();
            break;
        }
    }
}

void processData()
{
    unique_lock<mutex> done_u(done_m);
    done_c.wait(done_u);
    this_thread::sleep_for(1s);
    for (auto& vec : buffer)
    {
        cout << vec << " ";
    }

}

int main()
{
    for(int i = 0; i < 10000; i++)
    {
        dataFromNetwork.push_back(i);
    }
    process_status = 0;
    thread fetch_thread(fetchData);
    thread display_thread(displayProcess);
    thread process_thread(processData);
    fetch_thread.join();
    display_thread.join();
    process_thread.join();
}