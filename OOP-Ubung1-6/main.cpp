#include <iostream>

using namespace std;

int mat_res[100][100];

int main()
{
    int n,m,p;
    cout<<"n,m,p:";
    cin>>n>>m>>p;
    int mat1[m][n],mat2[n][p];
    cout<<"Elem of mat1("<<m<<"x"<<n<<"):\n";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> mat1[i][j];

    cout<<"Elem of mat2("<<n<<"x"<<p<<"):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            cin >> mat2[i][j];

    for(int i = 0;i<m;i++)
        for(int j = 0;j<p;j++)
            for(int k = 0;k<n;k++)
                mat_res[i][j]+=mat1[i][k]*mat2[k][j];

    for(int i = 0; i < m; i++)
        {for(int j = 0; j < p; j++)
            cout << mat_res[i][j]<<' ';
        cout<<'\n';}


    return 0;
}
