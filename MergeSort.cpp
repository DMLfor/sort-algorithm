#include<iostream>

using namespace std;
const int N = 100000 + 10;
int a[N];

void Merge(int *arr, int *ptr, int Lpos, int Rpos, int RightEnd)
{
	int LeftEnd = Rpos-1, TmpPos = Lpos, nums = RightEnd - Lpos + 1;
	while(Lpos<= LeftEnd && Rpos <= RightEnd)
	{
		if(arr[Lpos] <= arr[Rpos])
			ptr[TmpPos++] = arr[Lpos++];
		else ptr[TmpPos++] = arr[Rpos++];	
	}

	while(Lpos <= LeftEnd)
		ptr[TmpPos++] = arr[Lpos++];	

	while(Rpos <= RightEnd)
		ptr[TmpPos++] = arr[Rpos++]; 

	for(int j = 0; j<nums; j++, RightEnd--)
		arr[RightEnd] = ptr[RightEnd];
}


void Msort(int *arr, int *ptr, int l, int r)
{
	if(l < r)
	{
		int mid = (l+r)/2;
		Msort(arr, ptr, l, mid);
		Msort(arr, ptr, mid+1, r);
		Merge(arr, ptr, l, mid+1, r);
	}
}

void MergeSort(int *arr, int n)
{
	int *ptr = new int[n+1];
	Msort(arr, ptr, 0, n-1);
	delete [] ptr;
	
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	MergeSort(arr, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
