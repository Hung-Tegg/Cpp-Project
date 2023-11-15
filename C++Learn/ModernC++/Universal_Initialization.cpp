#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int x{7};
    string str{"Let us begin"};
    int y = 7.7 ;
    cout << x << endl;
    cout << str << endl;
    cout << y << endl;
     
    vector<int> vec{4,2,3,5,1};
    for(auto & vecs : vec)
    {
        cout << vecs << endl;
    }
}