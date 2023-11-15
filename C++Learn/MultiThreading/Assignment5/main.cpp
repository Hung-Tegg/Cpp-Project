#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
using namespace std;

class some_type {
	
public:
    some_type()
    {
        cout << "Called constructor" << endl;
    }
	void do_it() { 
        cout << "Okey go" << endl;
    }
};

atomic<some_type *> ptr{nullptr};            // Variable to be lazily initialized
std::mutex process_mutex;

void process() {
    if (!ptr) {                     // First check of ptr
        
         // Second check of ptr
            ptr = new some_type;   // Initialize ptr
    }
    some_type* ptr_non_atomic = ptr;
    ptr_non_atomic->do_it();
}

int main()
{
  vector<thread> thr;
  for(int i = 0; i < 10; i++)
  {
    thr.push_back(thread(process));
  }
  for (auto & thrs : thr){
    thrs.join();
  }
}