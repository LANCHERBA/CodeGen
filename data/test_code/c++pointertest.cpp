#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int input;
	int move_size;
	cout << "Please insert an array size: ";
	cin >> input;
	// Note: one int block has 4 bytes.
	cout << "Please insert how many blocks you want to move the pointer: ";
	cin >> move_size;
	// allocate input number of int memory blocks
	int* ptr = (int*)malloc(input * sizeof(int));

	// check if memory has been allocated successfully
	if (!ptr) {
		cout << "Memory Allocation Failed";
		exit(1);
	}

	cout << "Initializing values..." << endl << endl;

	for (int i = 0; i < input; i++) {
		ptr[i] = i * 2 + 1;
	}
	cout << "Initialized values" << endl;

	for (int i = 0; i < input; i++) {
		cout << *(ptr + i) << endl;
	}

	// try to move array pointer by input move_size
	try
	{
		cout << ptr << endl;
		ptr = ptr + move_size;
		cout << ptr << endl;
	}
	catch (...)
	{
		cout << "Pointer modification failure" << endl;
	}

	// reset ptr to its original address and deallocate memory
	ptr = ptr - move_size;
	free(ptr);
	
	system("pause");
	return 0;
	
}

