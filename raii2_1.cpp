#include <iostream>

void pp (int & i)
{
  std::cout << &i << " " << i << " " << sizeof(i) << "\n";
}


template <typename T>
class DynamicArray
{
  T*    m_arr;
  size_t  m_size;
public:

    DynamicArray(size_t size)
      : m_size(size)
      , m_arr (new T[size])
    {
      std::cout << "array constructor\n";
    }

    ~DynamicArray(){
      delete [] m_arr;
      std::cout << "array destroctor\n";
    }

    T get(size_t index) const 
    {
      return m_arr[index];
    }

    void set(size_t index, T val)
    {
      m_arr[index] = val;
    }

    void print() const 
    {
      for (size_t i = 0; i < m_size; i++) {

        std::cout << i << " " << m_arr[i] << "\n";
        
      }
    }

    const T & operator[](size_t index) const {
      return m_arr[index];
    }
  
    T & operator [] (size_t index) {
      return m_arr[index];
    }

};

int main (int argc, char *argv[]) {

  DynamicArray<float> myArray(10);
  
  //myArray.set(4, 232.12323);

  myArray[5] = 55552.34234;

  std::cout << myArray[5] << "\n";
  myArray.print();

  
  return 0;
}
