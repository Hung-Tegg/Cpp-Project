/* write a thread with entry point is: 
   1. functor which overload the operator()
   2. lamda expression
   3. member function of a class

   A. receive 2 int and print the sum 
*/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


mutex mu;
class functor 
{
  public:
  void operator()(int a, int b)
  {
    lock_guard<mutex> lock_mu(mu);
    cout << "This is called by functor: " << a + b <<  endl;
  }
};

class class_thread
{
  public:
  void doWork(int a, int b)
  {
    lock_guard<mutex> lock_mu(mu);
    cout << "This is called by member function in class: " << a + b << endl;
  }
};


int main()
{
    functor functor_var;
    thread functor_thread(functor_var, 10, 15);
    class_thread class_var;
    thread class_thread(&class_thread::doWork, class_var, 10, 20);
    thread lamda_thread([](int a, int b){
      lock_guard<mutex> lock_mu(mu);
      cout << "This is called by lamda expression: " << a + b << endl;
    }, 20, 30);
    class_thread.join();
    functor_thread.join();
    lamda_thread.join();
}