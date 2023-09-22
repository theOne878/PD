#include<iostream>
using namespace std;
int main(){
double iv,a,t;
cout << " Enter initial velocity (m/s):" ;
cin >> iv;
cout << " Enter acceleration (m/s^2):" ;
cin >>a;
cout << " Enter time(s):" ;
cin >> t;
double fv = (a*t)+iv;
cout<< " Final velocity is:" <<fv;

















return 0;
}
