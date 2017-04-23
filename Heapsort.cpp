#include<iostream>

using namespace std;

const int N = 100000 + 10;
int a[N];

void PerDown(int *arr,int i, int n)
{

	int child, tmp;
	for(tmp = arr[i]; i*2<n; i = child)
	{
		child = i*2;
		if(child != n-1 && arr[child] < arr[child+1])
			child ++;
		if(arr[child] > tmp)
			arr[i] = arr[child];
		else break;
	}
	arr[i] = tmp;

}
void HeapSort(int *arr, int n)
{
	int i;
	for(i = n/2-1; i>=0; i--)
	{
		PerDown(arr, i, n);
	}
	for(i = n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		PerDown(arr, 0, i);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	HeapSort(arr, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
