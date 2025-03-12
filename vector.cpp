#include <iostream>
#include <vector>
#include <fstream>
class Student {

  std::string m_first = "First";
  std::string m_last = "Last";
  int m_id = 0;
  float m_avg = 0;

public:
  Student() {}

  Student(std::string first, std::string last, int id, float avg)
   : m_first (first)
    , m_last (last)
    , m_id (id)
    , m_avg (avg)
  {

  }

  int getAvg() const
  {
    return m_avg;
  }

  int getID() const 
  {
    return m_id;
  }

  std::string getFirst() const 
  {
    return m_first;
  }

  std::string getLast() const 
  {
    return m_last;
  }

  void print() const
  {
    std::cout << m_first << " " << m_last << " " << m_id << " " << m_avg << " \n";
  }

};

class Course
{
  std::string m_name = "Course";
  std::vector<Student> m_students;

public:

  Course() {}

  Course(const std::string& name)
    : m_name(name)
  {
  }
  void addStrudent(const Student& s)
  {
    m_students.push_back(s);
  }

  const std::vector<Student> getStudent() const 
  {
    return m_students;
  }

  void loadFromFile (const std::string& filename)
  {
    std::ifstream fin(filename);
    std::string first, last;
    int id;
    float avg;

    while (fin >> first) 
    {
      fin >> last;
      fin >> id;
      fin >> avg;
    
      addStrudent(Student(first, last, id, avg));

    }
  }

  void print() const 
  {
    for (const auto& s : m_students)
    {
      s.print();
    }
  }

};


/*
int main (int argc, char *argv[]) {

  std::vector<float> supervec;
  supervec.push_back(444.23423);
  supervec.push_back(321.1323);

  
  for (size_t i = 0; i < supervec.size(); i++)
  {
    std::cout << supervec[i] << "\n";
  }

  for (auto a : supervec)
  {
    std::cout << a << "\n";
  }

  Student s1;
  const Student s2("alcice", "gold", 1, 33);
  const Student s3("bob", "silver", 1221, 99);
  
  Course comp4300( "COMP 4300");

  comp4300.addStrudent(s1);
  comp4300.addStrudent(s2);
  comp4300.addStrudent(s3);
  comp4300.addStrudent(Student("billy","grow", 4, 13));
  comp4300.print();
    //std::cout << s3.getLast() << "\n";
  //s2.print();


  return 0;
}
*/ 

int main (int argc, char *argv[]) {
  
  Course c ("COMP 4300");
  c.loadFromFile("students.txt");
  c.print();

  return 0;
}
