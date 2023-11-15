#include <iostream>

using namespace std;

void overFunction(int value) 
{
    cout << value << endl;
}

void overFunction(int* ptr_to_int)
{
    cout << *ptr_to_int << endl;
}

int main()
{
  // overFunction(NULL); //  the compiler don't know which function to call
  overFunction(nullptr);
}