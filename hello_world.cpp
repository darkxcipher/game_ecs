#include <iostream>

int main(int argc, char * argv[])
{
	int a = 22;
  int b = 13;

  std::string first = "dark";
  std::string last = "cipher";

  std::string name = first + " " + last;
  int age = a * b;

  std::cout << "hello, world!" << std::endl;
  std::cout << age << std::endl ;
  std::cout << name << std::endl;

  return 0;
}
