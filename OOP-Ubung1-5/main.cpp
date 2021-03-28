#include <iostream>
#include <cstring>

using namespace std;

void rem_repeat(char s[])
{int n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]==s[i+1])
            {char aux[100];
            strcpy(aux,s+i+1);
            strcpy(s+i,aux);
            n--;
            i--;
            }
}

int main()
{
    char stri[100]="abcddraalrt";
    rem_repeat(stri);
    cout<<stri;
    return 0;
}
