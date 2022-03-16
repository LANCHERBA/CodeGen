#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int input;
	cout << "Please insert an array size: ";
	cin >> input;
	int* ptr = (int*)malloc(input * sizeof(int));

	if (!ptr) {
		cout << "Memory Allocation Failed";
		exit(1);
	}

	for (int i = 0; i < input; i++) {
		ptr[i] = i * 2 + 1;
	}
	cout << "Initialized values" << endl;

	for (int i = 0; i < input; i++) {
		cout << *(ptr + i) << endl;
	}

	free(ptr);

	return 0;
	
}

