#include "CGPA.hpp"

Student::Student(std::vector<float> marks)
{
  this->marks = marks;
}

float Student::GetCGPA()
{
  return this->CGPA;
}

float Student::GetCGPAPercentage()
{
  return this->CGPAPercentage;
}

void Student::CalculateCGPA()
{
  float CGPA = 0;
  for(std::vector<float>::iterator iter = this->marks.begin() ; iter != this->marks.end(); iter++)
  {
    CGPA += *iter;
  }
  this->CGPA = (CGPA / this->marks.size());
}


void Student::CalculateCGPAPercentage()
{
  this->CGPAPercentage = (this->CGPA * 0.95);
}
