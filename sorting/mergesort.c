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
void merge(int left[],int right[],int mid,int a[],int n)
{	int k =0,i =0,j =0;
	while(i < mid && j < n-mid)
	{
		if(left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < mid)
	{
		a[k] = left[i];
		i++;
		k++;
	}
	while(j < (n-mid))
	{
		a[k] = right[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int n)
{
	if(n < 2)
		return;
	else{
		
	}
	int i, mid = n/2;
	int left[mid],right[n-mid];
	for(i = 0;i < mid;i++)
	{
		left[i] = a[i];
	}
	for(i = mid;i < n;i++)
	{
		right[i-mid] = a[i];
	}
	
	mergesort(left,mid);
	mergesort(right,n-mid);
	merge(left,right,mid,a,n);
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
    mergesort(a,n);
    printf("Your sorted numbers: ");
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}