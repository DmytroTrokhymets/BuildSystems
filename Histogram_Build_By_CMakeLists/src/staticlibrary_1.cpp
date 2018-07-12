#include "staticlibrary_1.h"

#include <iostream>

void PrintStar(size_t value)
{
   std::cout << value << ':';
   for(size_t i = 0; i < value; i++)
       std::cout << '*' << ' ';
   std::cout << std::endl;
}
