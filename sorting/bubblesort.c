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
void bubblesort(int *a,int n)
{
	int i,j;
    for(i = 0; i < n-1; i++)
    {
        int flag =0;
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a,j,j+1);
                flag =1;
            }
        }
        if(flag == 0)
            break;
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
    bubblesort(a,n);
    printf("Your sorted numbers: ");
    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}