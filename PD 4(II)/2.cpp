#include<iostream>
using namespace std;
void trueORfalse(string x);
int main(){
string x;
trueORfalse(x);
return 0;
}
void trueORfalse(string x){
cout<<"Enter 'true' or 'false': ";
cin>>x;
if(x=="true"||x=="True"){
cout<<"false";
}
if(x=="false"||x=="False"){
cout<<"true";
}
}