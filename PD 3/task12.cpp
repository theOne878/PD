#include<iostream>
using namespace std;
int main(){
int paint,width,height;
cout<<"Number of square meter you can paint:";
cin>>paint;
cout<<"Width of a single wall:";
cin>>width;
cout<<"Height of a single wall:";
cin>>height;
int number=paint/(width*height);
cout<<"Number of walls you can paint:"<<number;








return 0;






}