#include<iostream>
using namespace std;
void eqaulity(int x,int y);
int main(){
int x,y;
eqaulity(x, y);
return 0;
}
void eqaulity(int x,int y){
cout<<"Enter the first number: ";
cin>>x;
cout<<"Enter the second number: ";
cin>>y;
if(x==y){
cout<<"true";
}
if(x!=y){
cout<<"false";
}

}