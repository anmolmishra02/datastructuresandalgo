#include<bits/stdc++.h>
using namespace std;

bool check(int *a,int cow,int mid,int n)
{   
  int count=1;
  int lastcow=a[0];
  for(int i=1;i<n;i++)
  {   
      if(count==cow)
      {
          return true;
      }
      if(a[i]-a[0]>=mid)
      {   lastcow=a[i];
          count++;
      }
      
  }
  return false;
}

int mincows(int*a,int n,int k)
{
    int s=0;
    int e=a[n-1]-a[0];
    int ans=-1;
    int mid;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        if(check(a,k,mid,n))
        {   ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        
        
    }
    
    return ans;
}


int main()
{
    int n;
    cout<<"Enter no of stalls";
    cin>>n;
    cout<<"Enter position of stalls"<<endl;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int k;
    cout<<"Enter the no of cows you want to insert";
    cin>>k;
    sort(a,a+n);
    cout<<"minimum distance required to place"<<mincows(a,n,k);
    
    
}