#include<bits/stdc++.h>
using namespace std;
#define ll long long


long long merge(int *a,int left,int mid,int right)
{
    int i=left;
    int j=mid;
    ll count=0;
    int k=0;
    int temp[right-left+1];
    while(i<mid && j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
            count+=mid-i;
        }
    }
    while(i<mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=right)
    {
        temp[k++]=a[j++];
    }
    
    return count;
}



long long mergesort(int *a,int left,int right)
{
    long long count=0;
    int mid=(left+right)/2;
    if(right>left)
    {
        ll lcount=mergesort(a,left,mid);
        ll rcount=mergesort(a,mid+1,right);
        ll mycount=merge(a,left,mid+1,right);
        return mycount+lcount+rcount;
    }
    return count;
}
long long solve(int *a,int n)
{
    long long count=mergesort(a,0,n-1);
    
    return count;
}



int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans=solve(a,n);
    cout<<"total no of inversion are :"<<ans;
    
}
