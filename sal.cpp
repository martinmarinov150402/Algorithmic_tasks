#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    int a[1000];
    bool used[1000];
    int suma=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        suma+=a[i];
    }
    sort(a,a+n);
    /*for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/
    if(a[n-1]>suma/k)
    {
        printf("%d\n",a[n-1]);
    }
    else
    {
        for(int cap = suma/k;cap<suma;cap++)
        {
           int maxa=0;
           for(int i=0;i<n;i++)used[i]=0; 
           for(int j=0;j<k;j++)
            {
                int tmp=0;
                for(int i=n-1;i>=0;i--)
                {
                    if(used[i])continue;
                    if(tmp+a[i]<=cap)
                    {
                        tmp+=a[i];
                        used[i]=1;
                    }
                }
                maxa=max(tmp,maxa);
            }
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                if(!used[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                printf("%d\n",maxa);
                break;
            } 
        }
        
         
    }
    //int minimal=max(a[k-1],suma/k);
    
}
/*
6 2
26 7 10 30 5 4

ANS:42
*/