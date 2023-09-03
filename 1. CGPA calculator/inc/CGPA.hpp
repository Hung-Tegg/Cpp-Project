#include <iostream>
#include <vector>
class Student
{
private:
  std::vector<float> marks;
  float CGPA;
  float CGPAPercentage;
public:
  Student(std::vector<float> marks);
  float GetCGPA();
  float GetCGPAPercentage();
  void CalculateCGPA();
  void CalculateCGPAPercentage();
};
