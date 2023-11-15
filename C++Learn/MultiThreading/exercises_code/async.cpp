#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
using namespace std;

int main()
{
  string str{"Fuck you Bitches!"};
  string::iterator str_i = find(str.begin(),str.end(), 'a');
  for(string::iterator i = str.begin(); i != str.end(); i++) 
  {
    static int j = 0;
    if (str_i == i)
    {
        cout << j << endl;
        break;
    }
    j++;
  }
}