#include<iostream>

using namespace std;
const int N = 1000 + 10;

void ShellSort(int *arr, int n)
{
	int Increment = 1, j;
	while(Increment * 2 <= n)
	{
		Increment *= 2;
	}
	for(;Increment > 0; Increment /= 2)
	{
		for(int i = Increment; i < n; i++)
		{
			int tmp = arr[i];
			for(j = i; j>= Increment; j -= Increment)
			{
				if(tmp < arr[j - Increment])
					arr[j] = arr[j - Increment];
				else break;
			}
			arr[j] = tmp;
		}
	}
}
int main()
{
	int arr[N], n;
	cin>>n;
	for(int i = 0; i<n; i++)
		scanf("%d", &arr[i]);
	ShellSort(arr, n);
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
