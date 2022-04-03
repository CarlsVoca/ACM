#include<iostream>
using namespace std;
int a[100005];
void quicksort(int left,int right)
{
    int i,j,base;
    i=left; j=right;
    base=a[(i+j)/2];
    while (i<=j){
        while (a[i]<base) i++;
        while (a[j]>base) j--;
        if (i<=j){
            int t=a[i]; a[i]=a[j];a[j]=t;
            i++;
            j--;
        }
    }
    if (left<j) quicksort(left,j);
    if (i<right) quicksort(i,right);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    quicksort(0,n-1);
    for (int i=0;i<n;i++)
     cout<<a[i]<<" ";
     return 0;
}