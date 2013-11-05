#include <iostream>
using namespace std;


void getDuplicate(int arr[],int size)
{
    int pos = 0;
    int desiredPos = 0;
    while(pos < size)
    {
        if(arr[pos] <= 0)
        {
            pos++;
			continue;
        }
        desiredPos = arr[pos] -1;
        if(arr[desiredPos] > 0)
        {
            arr[pos] = arr[desiredPos];
            arr[desiredPos] = -1;
        }
        else
        {
            arr[desiredPos]--;
            arr[pos] = 0;
            pos++;
        }
    }
}

int main()
{
	int A[] = {9,9,9,9,9,9,9,8,7,9,9};
	getDuplicate(A, sizeof(A)/sizeof(int));

	return 0;
}
