#include <iostream>
using namespace std;
int Binarysearch(int A[],int N,int x)
{
    int f=0,l,r,mid;
    for(l=0,r=N-1;l<=r;)
    {
        mid=l+(r-l)/2;
        // If the element is present at the middle itself
        if(x==A[mid])
            return mid+1;
        // If element is smaller than middle element, then it can only be present in left sub-array
        else
        if(x>A[mid])
            l=mid+1;
        // If element is greater than middle element, then it can only be present in right sub-array
        else
            r=mid-1;
    }
    return 0;
}
int main()
{
    int A[200],N,x,i;
    cout<<"Enter the no. of elements in array: ";
    cin>>N;
    cout<<"Enter elements of array: "<<endl;
    for(i=0;i<N;i++)
    cin>>A[i];
    cout<<"Enter the element to be searched: ";
    cin>>x;
    int y=Binarysearch(A,N,x);
    if(y!=0)
        cout<<"Position of "<<x<<" in given array is "<<y;
    else
        cout<<"Position of "<<x<<" is not found";
    return 0;
}
