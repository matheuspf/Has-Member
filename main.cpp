#include "HasMember.h"


HAS_VAR(x)
HAS_FUNC(y)


struct Yes { int x; void y(){} };
struct No {};

struct True {};
struct False {};


template <class> struct Print;


int main ()
{
	Print<std::conditional_t<has_x<Yes>(), True, False>>();
	//Print<std::conditional_t<has_y<Yes>(), True, False>();

	Print<std::conditional_t<has_x<No>(), True, False>>();
	//Print<std::conditional_t<has_y<No>(), True, False>();


	return 0;
}