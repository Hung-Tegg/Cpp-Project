#include "CGPA.hpp"

int main()
{
  std::vector<float> marks = {5,4,3,2,1};

  Student Hung(marks);
  Hung.CalculateCGPA();
  Hung.CalculateCGPAPercentage();
  std::cout << Hung.GetCGPA() << std::endl << Hung.GetCGPAPercentage() << std::endl;
  

}

