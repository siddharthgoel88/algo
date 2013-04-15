#include <stdio.h>
#define MAX 10

void flip(int size[MAX], int n)
{
	int i,temp;

	for(i=0;i<=(n/2);i++)
	{
		temp = size[i];
		size[i] = size[n-i];
		size[n-i] = temp;
	}
}

int find_max(int size[MAX],int n)
{
	int i,max=0;

	for(i=1;i<=n;i++)
	{
		if(size[i]>size[max])
			max = i;
	}

	return max;
}

void psort(int size[MAX],int n)
{
	int i,pos;

	for(i=n-1;i>0;i--)
	{
		pos = find_max(size,i);

		if(pos == i)
			continue;

		if(pos)
			flip(size,pos);

		flip(size,i);
	}
}

int main()
{
	int count,i,size[MAX];

	printf("Enter number of pancakes:");
	scanf("%d",&count);

	printf("Enter integral size for each :\n");

	for(i=0;i<count;i++)
		scanf("%d",&size[i]);

	psort(size,count);

	printf("Sorted order :\n");

	for(i=0;i<count;i++)
		printf("%d ",size[i]);

	printf("\n");

	return 0;
}
