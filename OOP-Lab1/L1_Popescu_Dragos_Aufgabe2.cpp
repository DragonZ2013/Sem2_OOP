#include <iostream>

using namespace std;

int isprim(int x)
{
    if(x<=1)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0)
            return 0;
    return 1;
}

int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}


void sequence(int a[],int x)
{
    int lenc=1,lenmax=-1,pc=0,pmax;
    for(int i=0;i<x-1;i++)
        if(cmmdc(a[i],a[i+1])==1)
            lenc++;
        else
        {
            if(lenc>lenmax)
            {
                lenmax=lenc;
                pmax=pc;
            }
            pc=i+1;
            lenc=1;
        }
    if(lenc>lenmax)
    {
        lenmax=lenc;
        pmax=pc;
    }
    //cout<<lenmax<<' '<<pmax<<'\n';
    for(int i=0;i<lenmax;i++)
        cout<<a[i+pmax]<<' ';

    
}

int main()
{
    //a)
    int n;
    cout<<"a)\nn=";
    cin>>n;
    int x=0,k=0;
    while(x<n)
    {
        if(isprim(k))
        {
            x++;
            cout<<k<<' ';
        }
        k++;
    }
    //b)
    cout<<"\nb)\nNumber of elements:";
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sequence(a,n);
    
}