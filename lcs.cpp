#include<bits/stdc++.h>
using namespace std;

int lcs(char*s1,char*s2)
{
if(s1[0]=='\0' || s2[0]=='\0')
{
    return 0;
}
if(s1[0]==s2[0])
{
    return 1+lcs(s1+1,s2+1);
}
else
{
    return max(lcs(s1+1,s2),lcs(s1,s2+1));
}
    
}

int lcsfast(char*s1,char*s2,int m,int n,int**dp)
{
    if(m==0||n==0)
    {
        return 0;
    }
    int ans;
    if(dp[m][n]>-1) 
    {return dp[m][n];
    }
    if(s1[0]==s2[0])
    {
        ans=1+lcsfast(s1+1,s2+1,m-1,n-1,dp);
    }
    else
    {
        ans=max(lcsfast(s1+1,s2,m-1,n,dp),lcsfast(s1,s2+1,m,n-1,dp));
    }
    dp[m][n]=ans;
    return ans;
}

int lcs2(char*a,char*b)
{
    int m=strlen(a);
    int n=strlen(b);
    int**dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans=lcsfast(a,b,m,n,dp);
    for(int i=0;i<=m;i++)
    {
        delete [] dp[i];
    }
    delete dp;
    return ans;
    
}


int main()
{
    
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;
    cout<<"lcs is "<<lcs2(a,b)<<endl;
    cout<<"lcs is "<<lcs(a,b)<<endl;
    
    
    
}
