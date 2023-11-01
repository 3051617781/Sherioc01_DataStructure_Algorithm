//二分法求近似值
#include<cstdio>
#include<iostream>
using namespace std;
const double eps = 0.0000000001;
double f(double x){return x*x;}
double calSqrt(double l, double r, int n){
    double mid;
    while(r - l > eps){
        mid = (r + l) / 2;
        if(f(mid) > n)r = mid;
        else l = mid;
    }
    return mid;
}

int main(){
    cout<<calSqrt(1, 2 ,2);//1.41421 
}