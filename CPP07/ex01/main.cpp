
#include "iter.hpp"

template<typename T>
void print(T arr[])
{
  int i = 0;
  while (arr[i])
  {
    std::cout << "arr : " << arr[i] << std::endl;
  }
}

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
    int tab[] = { 0, 1, 2, 3, 4 }; 
    float tab1[] = { 0.0, 1.1, 2.2, 3.3, 4.4 }; 
    double tab2[] = { 0.5, 1.5, 2.5, 3.5, 4.5 }; 

    iter( tab, 5, print<const int> );
    iter( tab1, 5, print<float> );
    iter( tab2, 5, print<double> );

    return 0;
}