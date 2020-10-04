#include <iostream>
using namespace std;

int linear_search(int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int main()
{
    int i, n, x, r, a[200];
    cout<<"Enter the length of the array: ";
    cin>>n;
    cout<<"Enter the elments of the array: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to be searched: ";
    cin>>x;
    r = linear_search(a, n, x);
    (r == -1) ? cout<<"Entered element is not found in the array" : cout<<"Entered element " << x << " is found at position " << r+1;
    return 0;
}
