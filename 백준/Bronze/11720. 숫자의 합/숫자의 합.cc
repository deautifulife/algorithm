#include <iostream>
using namespace std;


int main()
{
	int count =0;
	char ch;
	int sum = 0;

	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		cin >> ch;
		sum = sum + ch - 48;
	}
	cout << sum;

	return 0;
}
