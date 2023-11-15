#include <iostream>
#include <thread>
#include <string>


using namespace std;

void task(string str)
{
    for (string::iterator a = str.begin(); a < str.end(); a++){
       cout << *a;
    }
}


int main()
{
  string str{"HungHBT Pro code 1st the world"};
  thread thr1(task, str);
  thread thr2(task, str);
  thread thr3(task, str);
  thr1.join();
  thr2.join();
  thr3.join();

}