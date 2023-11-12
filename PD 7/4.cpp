#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int cube(int m);
int main(){
    int m;
    int volume=0;
    int n=1;
    cout<<"Enter the number of cubes: ";
    cin>>m;
    while(volume<m){
        volume+=n*n*n;
        n++;
        if(volume==m){
            cout<< n-1;
        }
    }
}