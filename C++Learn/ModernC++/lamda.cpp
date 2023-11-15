#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{2,3,4,5,6,15,8,9,10};
    int value = 3;
    int odd_count = count_if(vec.begin(),vec.end(),[value](int element){return (element % value == 0);});
    cout << odd_count << endl;
}