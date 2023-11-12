#include<iostream>
using namespace std;
int main(){
    
    int rows=10;
    for(int i=10;i<=rows;i--){
    if(i<=0)
    break;
    
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
            
        }
        
cout<<endl;
    }
}
