#include <iostream>
using namespace std;
int Binarysearch(int A[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        // If the element is present at the middle itself
        if(A[mid]==x)
            return mid;
        // If element is smaller than middle element, then it can only be present in left sub-array
        if(A[mid]>x)
            return Binarysearch(A,l,mid-1,x);
        // If element is greater than middle element, then it can only be present in right sub-array
        return Binarysearch(A,mid+1,r,x);
    }
    // if element is not present in array, we return -1
    return -1;
}
int main()
{
    int A[200],N,x,i;
    cout<<"Enter the no. of terms in array: ";
    cin>>N;
    cout<<"Enter the elements of array: "<<endl;
    for(i=0;i<N;i++)
        cin>>A[i];
    cout<<"Enter the element to be searched: ";
    cin>>x;
    int y=Binarysearch(A,0,N-1,x);
    if(y==-1)
        cout<<"The searched element is not present in array";
    else
        cout<<"The searched element "<<x<<" is present in array at position: "<<y+1;
    return 0;
}
