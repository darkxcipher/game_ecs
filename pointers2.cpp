#include <iostream>

void pp(int & i)
{
  std::cout<< &i << " " << i << " " << sizeof(i) << "\n";
}

int main (int argc, char *argv[]) {
  
  int a = 10;
  int b = 25;
  int* pa = &a;
  int* pb = &b;

  pp(a);
  pp(b);
  
  *(pb-1) = 9999999;
  
  pp(a);
  pp(b);
  
  int arr[10] = { };
  int * harr = new int[10];

  for (size_t  i = 0; i < 10; i++) {

    pp(arr[i]);
  }

  for (size_t i = 0; i < 10; i++) {
   pp(harr[i]); 
  }

  return 0;
}
