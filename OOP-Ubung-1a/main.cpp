#include <iostream>

using namespace std;

char *find (const char * s, char * f)
{

    int i=0,j=0,leng;
    for(leng=0;s[leng]!=0;leng++)
        continue;
    while(s[i]!=0&&f[j]!=0)
    {
        if(i==leng)
            return f+j-i;//i couldn't use f+j-i for location pointer with "const"
        if(s[i]==f[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
            i=0;
        }
    }
    return NULL;
}
void test(int &n)
{
    n=3;
}
void strcpy(char *dest,const char *source)
{   int leng;
    for(leng=0;source[leng]!=0;leng++)
        dest[leng]=source[leng];
    dest[leng]='\0';
}

int main()
{
    int x=1;
    test(x);
    cout<<x;/*
    char a[100];
    strcpy(a,"test");
    cout<<a;*/
    return 0;
}
