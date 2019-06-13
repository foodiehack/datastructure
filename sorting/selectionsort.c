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
void selectionsort(int *a,int n)
{

    int  i,j,min;
    for (i =0; i<n-1; i++)
    {
        min = i;
        for(j=i+1; j < n; j++)
        {
            if(a[min] > a[j])
                min = j;
        }
        swap(a,i,min);
    }
}
int main()
{	
	int i,n; 
	printf("How many number do you want to enter:");
	scanf("%d",&n);
	//int a[n];  This is a wrong way as memory is given to array at compile time.
	int *a = (int*)malloc(n*sizeof(int)); //dynamic memory allocation
	printf("\nEnter the numbers \n");
 	for(i = 0; i < n; i++)
    	{
        printf("%d :",i+1);
        scanf("%d",&a[i]);
   	 }
   	selectionsort(a,n);
   	printf("Your sorted numbers: ");
    	for(i = 0; i < n; i++)
        	printf("%d ",a[i]);
    	printf("\n");
    	return 0;
}
