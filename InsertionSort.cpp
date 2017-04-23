#include<iostream>

using namespace std;
const int N = 1000 + 10;
void InsertionSort(int *arr, int n)
{
	for(int i = 0; i<n; i++)
	{
		for(int j = i + 1; j<n; j++)
		{
			if(arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
int main()
{
	int arr[N], n;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	InsertionSort(arr, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
