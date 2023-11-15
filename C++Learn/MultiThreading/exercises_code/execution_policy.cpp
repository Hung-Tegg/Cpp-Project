#include <thread>
#include <iostream>
#include <vector>
#include <execution>
using namespace std;
int main()
{
    vector<int> vec(20);
    int count = 0;
    for_each(__libcpp_execute_once,vec.begin(),vec.end(),
    [&count](int& a){
        a = ++count;
    });
    for (auto& vecs : vec)
    {
        cout << vecs <<endl;
    }
}