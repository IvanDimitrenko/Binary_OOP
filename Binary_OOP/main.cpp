#include "Binary.h"
#include"Header.h"

#define BINARY_OR_BINARY32;
void main()
{

	std::vector<bool> zrr = { 1,1,0,0,1,0,1 };
	std::vector<bool> vrr = { 0,1,1,0,0,1,1 };
	Binary  p(vrr);
	Binary  na(zrr);
	Binary zr;
	zr = p ^ na;
	cout << "xor_________" << zr << endl;
	zr = p | na;
	cout << "Or__________" << zr << endl;
	zr = p & na;
	cout << "And_________" << zr << endl;


	std::vector<bool> max_array =
	{
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1
	};

	Binary max_arr(max_array), max(18446744073709551615);
	cout << endl << max << endl << max_arr << endl;



	std::vector<bool> arr = { 1,0,1,0,1,1,1,0 };
	std::vector<bool> brr = { 0,0,1,0 };

	Binary a(arr), b(brr);
	Binary c(a / b);
  
	cout << c << endl;

}