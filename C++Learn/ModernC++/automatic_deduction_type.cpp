#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> strs{"alo", "blo"};
    for (auto& str : strs)
    {
        cout << str << endl;
    }
}