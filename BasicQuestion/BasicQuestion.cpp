#include <iostream>
using namespace std;

int main()
{
	int* ptr = new int(10);

	int *ptr1 = ptr + (long long)5* 1024*1024*1024;

	return 0;
}