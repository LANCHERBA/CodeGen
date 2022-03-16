#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int input;
	cout << "Please insert an array size: ";
	cin >> input;
	int* ptr = (int*)malloc(input * sizeof(int));

	free(ptr);

	return 0;
}

