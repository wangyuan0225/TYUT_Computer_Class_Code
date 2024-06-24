#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
double f1(double *x,double *y,int t,int m){
    double temp = 0;
    for(int i = 0;i < m;i++){
        temp += pow(x[i],t);
    }
    return temp;
}
double f2(double *x,double *y,int t,int m){
    double temp = 0;
    for(int i = 0;i < m;i++){
        temp += pow(x[i],t)*y[i];
    }
    return temp;
}
int main(){
    int m,n;
    cout << "输入数据个数:" << endl;
    cin >> m;
    double x[m],y[m];
    cout << "输入数据:" << endl;
    for(int i = 0;i < m;i++){
        cin >> x[i] >> y[i];
    }
    cout << "输入拟合次数:" << endl;
    cin >> n;
    double a[n+1];
    double st[n+1][n+1],ed[n+1];
    for(int i = 0;i < n+1;i++){
        for(int j = 0;j <= i;j++){
            if(i == 0&&j == 0) st[0][0] = m;
            else{
                st[i][j] = st[j][i] = f1(x,y,i+j,m);
            }
        }
    }
    for(int i = 0;i < n+1;i++){
        ed[i] = f2(x,y,i,m);
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 0;j < i;j++){
            double l = st[i][j]/st[j][j];
            for(int p = 0;p < n+1;p++){
                st[i][p] -= st[j][p]*l;
            }
            ed[i] -= ed[j]*l;
        }
    }
    a[n] = ed[n]/st[n][n];
    for(int i = n-1;i >= 0;i--){
        int temp = n;
        int j;
        for(j = n;j >= i+1;j--){
            ed[i] -= st[i][j] *a[temp--];
        }
        a[i] = ed[i]/st[i][j];
    }
    cout << "y=" << a[0];
    for(int i = 1;i < n+1;i++){
        cout << showpos << a[i];
        for(int j = 0;j < i;j++){
            cout << "*x";
        }
    }
    cout << "\n";
    double e = 0;
    cout << "误差为:";
    for(int i = 0;i < m;i++){
        double z = 0;
        for(int j = n;j >= 0;j--){
            z += pow(x[i],j)*a[j];
        }
        e += pow((z-y[i]),2);
    }
    cout << e;
    return 0;
}