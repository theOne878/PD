#include<iostream>
using namespace std;
void upperpart(int rows,int row);
void lowerpart(int rows,int bow);
int main(){
    
    int rows=10;
    int row=10;
    int bow=10;
    upperpart(rows,row);
    lowerpart(rows,bow);
}
void upperpart(int rows,int row){
        for(int i=1;i<=rows;i++){

        
        for(int j=1;j<=row-1;j++)
        {
            cout<<" ";
        }
        row--;
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void lowerpart(int rows,int bow){
            for(int i=1;i<=rows;i++){

        for(int j=1;j<=i-1;j++)
        {
            cout<<" ";
        }
        for(int k=1;k<=bow;k++)
        {cout<<"*";
        }
        bow--;
        cout<<endl;
    }
}

