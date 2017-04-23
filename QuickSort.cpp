#include<iostream>

using namespace std;
const int N = 100000 + 10, Cutoff = 3;

int a[N];
void InsertionSort(int *arr, int n)
{
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
	}
}

int median3(int *arr, int l, int r)
{
	int mid = (l+r)/2;
	if(arr[l] > arr[mid])
		swap(arr[l], arr[mid]);

	if(arr[l] > arr[r])
		swap(arr[l], arr[r]);

	if(arr[mid] > arr[r])
		swap(arr[mid], arr[r]);

	swap(arr[mid], arr[r-1]);

	return arr[r-1];
}

void Qsort(int *arr, int l, int r)
{
	int i, j, Pivot;
	if(l + Cutoff <= r)
	{
		Pivot = median3(arr, l, r);
		i =  l, j = r-1;
		while(true)
		{
			while(arr[++i] < Pivot){}
			
			while(arr[--j] > Pivot){}

			if(i < j)
				swap(arr[i], arr[j]);
			else break;
		}
		swap(arr[i], arr[r-1]);
		Qsort(arr, l, i-1);
		Qsort(arr, i+1, r);
	}
	else InsertionSort(arr+l, r-l+1);
}

void QuickSort(int *arr, int n)
{
	Qsort(arr, 0, n-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	QuickSort(a, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
