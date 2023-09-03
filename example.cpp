#include <cstdlib>
#include <iostream>
#include <vector>

#include "sequence_reverser.hpp"

int main() {
   const std::vector <int> vec{ 1, 2, 3, 4, 5 };
   for ( int val : kdf::reverse(vec) )
      std::cout << val << "...\n";
   std::cout << "Liftoff!" << std::endl;
   return EXIT_SUCCESS;
}

