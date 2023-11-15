#include <iostream>
#include <thread>
using namespace std;

void func()
{
    cout << "Children Thread Hello World" << endl;
}

class wrapper_for_thread
{
    private:
      thread thra;
    public:
      wrapper_for_thread( void(call)() )
      {
        thread thr(call);
        thra = move(thr);
      }
      ~wrapper_for_thread()
      {
       thra.join();
      }
};

int main() {

    try {
        wrapper_for_thread thr(func); 
        throw std::exception();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught\n"; 
    }
    
}