#include "CGPA.hpp"

int main()
{
  std::cout << "Enter number of marks of student: " ;
  unsigned int numberOfMarks = 0;
  std::cin >> numberOfMarks;
  std::vector<float> marks;
  for(int i = 0; i < numberOfMarks; i++)
  {
    std::cout << "Enter mark " << i + 1 <<" :";
    float temp_mark;
    std::cin >> temp_mark;
    marks.push_back(temp_mark);
  }
  Student student(marks);
  student.CalculateCGPA();
  student.CalculateCGPAPercentage();
  std::cout << "CGPA of the student is: " << student.GetCGPA() << std::endl;
  std::cout << "CGPA Percentage of the student is: " << student.GetCGPAPercentage() << std::endl;
  

}

