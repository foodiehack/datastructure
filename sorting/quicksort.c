#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void swap(int *a,int i,int min)
{
    int temp;
    temp = a[i];
    a[i]= a[min];
    a[min] = temp;

}
int partition(int a[],int start,int end)
{	int i;
	int pivot = a[end];
	int pindex = start;
	for(i = start ;i < end;i++)
	{
		if(a[i] <= pivot)
		{
			swap(a,i,pindex);
			pindex++;
		}
	}
	swap(a,pindex,end);
	return pindex;
}
void quicksort(int a[],int start,int end)
{	
	if(start < end)
	{
		int pindex;
		pindex = partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}

}
int main()
{	
	int i,n; 
	printf("How many number do you want to enter:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the numbers \n");
 	for(i = 0; i < n; i++)
    	{
        	printf("%d :",i+1);
        	scanf("%d",&a[i]);
    	}
    	quicksort(a,0,n-1);
    	printf("Your sorted numbers: ");
    	for(i = 0; i < n; i++)
        	printf("%d ",a[i]);
    	printf("\n");
    	return 0;
}
