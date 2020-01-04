#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

#define F first
#define S second
using namespace std;

typedef pair<double, int> par;
int n;
bool marca[101];
priority_queue< par, vector<par>, greater<par> > Q;
vector< vector<par> > adlist(110);
double X[101], Y[101];
int main()
{
    cin>> n;
    for(int i = 1;i <= n;i++)
        cin>> X[i]>> Y[i];
    for(int i = 1;i < n;i++)
        for(int j= i + 1;j <= n;j++){
                double difX = X[i] - X[j];
                double difY = Y[i] - Y[j];
                adlist[i].push_back( make_pair(sqrt(difX * difX + difY * difY),j));
                adlist[j].push_back( make_pair(sqrt(difX * difX + difY * difY),i));
        }
    Q.push( par(0,1));

    int newn;
    double sol = 0.0;
    while(!Q.empty()){
        int x = Q.top().S;
        double costo = Q.top().F;
        //cout<< costo<<" "<<x<<endl;
        Q.pop();
        if(!marca[x]){
            marca[x] = true;
            sol += costo;
            for(int i = 0;i < adlist[x].size();i++){
                newn = adlist[x][i].S;
                if(!marca[newn]){
                    costo = adlist[x][i].F;
                    Q.push( par(costo,newn) );
                }
            }
        }
    }

    printf("%.2lf\n",sol);
    return 0;
}
