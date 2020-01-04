#include <bits/stdc++.h>

using namespace std;

double F[100], F_1raDeri[100], F_2daDeri[100];
int grado;

double Formula2(double X)
{
    double x = F[0], y = F_1raDeri[0];

    for(int i = 1;i <= grado;i++)
        x += F[i] * pow(X, i);

    for(int i = 1;i < grado;i++)
        y += F_1raDeri[i] * pow(X, i);

    return x / y;
}

double Formula(double X)
{
    double x = F[0], y = F_2daDeri[0];

    for(int i = 1;i <= grado;i++)
        x += F[i] * pow( X,i );

    for(int i = 1;i < grado - 1;i++)
        y += F_2daDeri[i] * pow(X, i);

    return x * y;
}

int main()
{
    double epsilon;

    cout<<"Entre el valor del error maximo que se puede obtener:\n";
    cin>>epsilon;
    cout<<"Entre el intervalo a analizar (a b):";
    int a, b;
    cin>> a>>b;
    cout<<"Entre el grado del polinomio a anlisar:\n";
    cin>>grado;
    cout<<"Entre los coeficientes de las variablea de la funcion polinómica a analisar(de menor a mayor):\n";
    for(int i = 0;i <= grado;i++)
        cin>>F[i];

    for(int i = grado; i >= 0 ; i--)
        F_1raDeri[i - 1] = i * F[i];

    for(int i = grado - 1;i >= 0;i--)
        F_2daDeri[i - 1] = i * F_1raDeri[i];

    double A = Formula(a);

    cout<<"A: "<<A<<endl;
    double B = Formula(b);
    cout<<"B"<<B<<endl;
    double X, X_0;

    if(A > 0)
        X_0 = a;
    else if(B > 0)
        X_0 = b;
    else{
        cout<<"No se puede realizar el intervalo no garantiza una solucion\n";
        return 0;
    }

    X = X_0 - Formula2(X_0);
    cout<<"x_0:"<<X_0<<endl;
    cout<<"X:"<<X<<endl;
    int cont = 0;
    while( abs(X - X_0) <= epsilon ){
        swap(X, X_0);
        X = X_0 - Formula2(X_0);
        cont++;
    }

    cout<<"El resultado es: "<< X <<endl;
    cout<<"Se encontro en la iteracion "<<cont<<endl;

    return 0;
}
