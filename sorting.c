#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int i=0,j=0;
void swap(int *a,int i,int min)
{
    int temp;
    temp = a[i];
    a[i]= a[min];
    a[min] = temp;

}
void display(int *a,int n)
{
    printf("Your sorted numbers: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void calc_time(clock_t	start,clock_t	end,char *func){
	
	 double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
	 printf("%s took %f seconds to execute \n",func, time_taken);
}
void selectionsort(int a[],int n)
{

    int  min;
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
void insertionsort(int a[],int n)
{	int key;
	for(i = 1;i < n;i++)
	{
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
void bubblesort(int a[],int n)
{
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
void merge(int left[],int right[],int mid,int a[],int n)
{	int k =0;
	i =0;
	j =0;
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
int partition(int a[],int start,int end)
{
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
	clock_t	start;
	clock_t end;
    int ch,n;
    char ans;
    while(1)
    {
    	printf("How many number do you want to enter:");
	    scanf("%d",&n);
	    int a[n];
	    printf("Want random numbers(y/Y):");
	    scanf(" %c",&ans);
	    
	    if(ans == 'y' || ans == 'Y')
	    {
	    	int b[n];
    		for(i = 0; i < n; i++)
	    	{
	    		a[i] = rand();
	    		b[i] = a[i];
	        //	printf("\n%d : %d",i+1,a[i]);
	    	}
	    	start = clock();
	        selectionsort(b,n);
	        end = clock();
	        calc_time(start,end,"Selection Sort");
	        
	   		for(i = 0; i < n; i++)
	    	{
	    		b[i] = a[i];
	    	}
       		start = clock();
  		 	bubblesort(b,n);
	        end = clock();
	        calc_time(start,end,"Bubble Sort");
    	    
   	    	for(i = 0; i < n; i++)
	    	{
	    		b[i] = a[i];
	    	}
 			start = clock();
  		 	insertionsort(b,n);
	        end = clock();
	        calc_time(start,end,"Insertion Sort");
	        
        	for(i = 0; i < n; i++)
	    	{
	    		b[i] = a[i];
	    	}
 	 		start = clock();
	 	 	mergesort(b,n);
	        end = clock();
	        calc_time(start,end,"Merge Sort");
	        
        	for(i = 0; i < n; i++)
	    	{
	    		b[i] = a[i];
	    	}
 	 		start = clock();
	 	 	quicksort(b,0,n-1);
	        end = clock();
	        calc_time(start,end,"Quick Sort");
    	}
    	else
    	{
  			printf("\nEnter the numbers \n");
		    for(i = 0; i < n; i++)
		    {
		        printf("%d :",i+1);
		        scanf("%d",&a[i]);
		    }
	    
	    
		    printf("\n\n1.) Selection Sort \n");
		    printf("2.) Bubble Sort \n");
		    printf("3.) Insertion Sort \n");
		    printf("4.) Merge Sort \n");
		    printf("5.) Quick Sort \n");
		    printf("6:) Exit \n");
		    printf("Choose your option:");
		    scanf("%d",&ch);
		    switch(ch)
		    {
		    case 1:
		    	
		    	start = clock();
		        selectionsort(a,n);
	        	display(a,n);
		        end = clock();
		        calc_time(start,end,"Selection Sort");
		        break;
		    case 2:
	    		start = clock();
	  		 	bubblesort(a,n);	  		 	    
				display(a,n);
		        end = clock();
		        calc_time(start,end,"Bubble Sort");
		        break;
		    case 3:
	 			start = clock();
	  		 	insertionsort(a,n);
  		 		display(a,n);
		        end = clock();
		        calc_time(start,end,"Insertion Sort");
		        break;
		    case 4:
	 	 		start = clock();
		 	 	mergesort(a,n);
		 	 	display(a,n);
		        end = clock();
		        calc_time(start,end,"Merge Sort");
		        break;
		    case 5:
	 	 		start = clock();
		 	 	quicksort(a,0,n-1);
	 	 		display(a,n);
		        end = clock();
		        calc_time(start,end,"Quick Sort");
		        break;
		    case 6:
		        exit(1);
		        break;
		    default:
		        printf("Enter valid number \n\n");
		        break;
		    }
	    }
	    printf("Do you want to continue(y/Y):");
	    scanf(" %c",&ans);
	    if(ans != 'y' && ans != 'Y')
	    {
    		break;
	    }
	
    }
    
    return 0;
}
