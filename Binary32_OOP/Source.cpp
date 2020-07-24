#include"Binary32.h"
#include"Header.h"

#define BINARY_OR_BINARY32
void main()
{
	std::vector<bool> arr = {1,1,1,1,1,1,1,0,0,0,0,0};
	Binary32 a; 
    a = Binary32 (4294967294);		// Max value
	cout << a;

	Binary32 b1(arr);
	cout << b1;

	cout << "\n--------------------------------------------\n";
	
	Binary32 sum, t(93), g(17);
	sum = t - g;
	cout << sum;




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