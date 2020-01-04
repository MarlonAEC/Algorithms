#include <cstdio>
#include <iostream>

using namespace std;

int L[21];
int C[21][101];
int main()
{
    int n, q, MW;
    cin>> n;
    for(int i = 1;i <= n;i++)
        cin>> L[i];

    cin>> q;
    for(int k = 0;k < q;k++){
        cin>> MW;
        for(int i = 0;i <= n;i++) C[i][0] = 0;
        for(int w = 0;w <= MW;w++) C[0][w] = 0;

        for(int i = 1;i <= n;i++)
            for(int w = 1;w <= MW;w++){
                if(L[i] > w)
                    C[i][w] = C[i - 1][w];
                else
                    C[i][w] = max(C[i - 1][w], C[i - 1][w - L[i]] + L[i]);
            }

        for(int i = 1;i <= n;i++){
            for(int w = 1;w <= MW; w++){
                cout<< C[n][MW]<<" ";
            }
            cout<<"\n";
        }
        //cout<< C[n][MW]<<endl;
        if(C[n][MW] == MW)
            cout<< "yes"<<endl;
        else
            cout<< "no"<<endl;
    }

    return 0;
}
