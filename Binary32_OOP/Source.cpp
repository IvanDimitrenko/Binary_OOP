#include"Binary32.h"
#include"Header.h"

void main()
{
	std::vector<bool> arr = {1,1,1,1,1,1,1,0,0,0,0,0};
	Binary32 a; 
    a = Binary32 (4294967295);		// Max value
	cout << a;

	Binary32 b1(arr);
	cout << b1;

	cout << "\n--------------------------------------------\n";
	
	Binary32 sum, t(4213), g(3330);
	sum = t + g;
	cout  << t << g << sum;

	std::vector<bool> zrr = { 1,1,0,0,1,0,1 };
	std::vector<bool> vrr = { 0,1,1,0,0,1,1 };
	Binary32  p(vrr);
	Binary32 na(zrr);
	Binary32 zr;
	zr = p ^ na;
	cout << "xor_________" << zr << endl;
	zr = p | na;
	cout << "Or__________" << zr << endl;
	zr = p & na;
	cout << "And_________" << zr << endl;

/*
1100101
0110011
*/


	/*for (int i = 0; i < 30; i++)
	{
		for (int y = 1; y < 30; y++)
		{
		cout << "\n------------------------------------------\n";		
		cout << i << '%' << y;
			for (int j = 0; j < 30; j++)
			{
				if (i % y == j)
				{
					cout << '[' << j << ']';
				}
				cout << '*';
			}
		cout << "\n----------------------------------------\n";
		}
	}*/
}