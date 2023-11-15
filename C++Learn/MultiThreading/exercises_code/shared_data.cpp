
/*
Implement a singleton class and run multi thread test it
*/
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
mutex mu;
class sin
{
public:
    // function to get the unique instance
    static sin* createSin()
    {
        if (obj == nullptr)
        {
            mu.lock();
            if (obj == nullptr)
            {
                obj = new sin();    
            }
            mu.unlock();
        }
        
        return obj;
    }
    sin& operator=(sin&& obj) = default; // move constructor
    sin(sin&& obj) = default; //move operator

    void setA(int a)
    {
        this->a = a;
    }
    int getA()
    {
        return this->a;
    }

private:
    int a;
    static sin * obj;
    sin(){
        cout << "This is the constructor of singleton class" << endl;
    }
    sin(const sin& obj) = delete;
    sin& operator=(const sin& obj) = delete;

};

sin * sin::obj = nullptr;

void get_sin()
{
    sin* obj_l = sin::createSin();
    obj_l->setA(10);
    cout << obj_l->getA() << endl;
}


int main()
{
  vector<thread> vec;
  for(int i = 0; i < 50; i++)
  {
    vec.push_back(thread(get_sin));
  }
  for(auto& vecc : vec)
  {
    vecc.join();
  }
}