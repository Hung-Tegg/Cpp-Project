#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <condition_variable>
#include <mutex>
using namespace std;

string share_str{"I Love You Chu Ca Mo"};
condition_variable alo;
mutex muu;
bool is_write = false;
void write()
{
  this_thread::sleep_for(std::chrono::milliseconds(500));
 
  lock_guard<mutex> muuu(muu);
  cout << "Writeeeeeeeeeeeee " << share_str << endl;
  share_str = "Now, I don't love you anymore";
  alo.notify_all();
   is_write = true;


}

void read()
{

  unique_lock<mutex> mu(muu);
  cout << "Before modified, the string is: " << share_str << endl;
  alo.wait(mu, [](){return is_write;});
  cout << "After modified, the string is: " << share_str <<  endl << "ID: " << this_thread::get_id() << endl;
}

int main()
{
    thread read_thr(read);
    thread read_thr1(read);
    thread read_thr2(read);
    thread write_thr(write);
    read_thr.join();
    read_thr1.join();
    read_thr2.join();
    write_thr.join();

}