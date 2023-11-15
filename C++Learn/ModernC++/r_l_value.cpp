#include <iostream>
#include <vector>

using namespace std;

void sufVector(vector<string>&& strs)
{
   cout << strs.size() << endl;
}

int main()
{
    vector<string> vec_str{"hung","thu","nhut","tuan","hieu"};
    cout << vec_str.size() << endl;
    sufVector(move(vec_str));
    cout << vec_str.size() << endl; // it will print out zero because this obj already move into the function
} 