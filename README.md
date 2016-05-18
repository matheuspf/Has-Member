# Has-Member
Simple C++14 helper for checking existence of members


Checks for existence of members of the given class at compile time.

Example of use:


'''c++'

#include "HasMember.h"

HAS_VAR(x)              // Creates checker for variable 'x' named 'has_x'
HAS_VAR(x, checker_x)   // Creates checker for variable 'x' named 'checker_x'

HAS_FUNC(y)             // Same as above but for functions
HAS_FUNC(y, checker_y)  


struct Yes { int x; void y(){} };   // Struct with variable 'x' and function 'y'
struct No {};                       // Empty struct

struct True {};     // Only for simplicity
struct False {};


template <class> struct Print;    // If instantiated, emits a compile time error with the name of the type passed by parameter


int main ()
{
	Print<std::conditional_t<has_x<Yes>(), True, False>>();     // True
	Print<std::conditional_t<checker_x<Yes>(), True, False>>(); // True
	//Print<std::conditional_t<has_y<Yes>(), True, False>();    // True

	Print<std::conditional_t<has_x<No>(), True, False>>();      // False
	Print<std::conditional_t<checker_x<No>(), True, False>>();  // False
	//Print<std::conditional_t<has_y<No>(), True, False>();     // False

  Print<std::conditional_t<has_x<int>(), True, False>>();     // False

	return 0;
	
}

'''
