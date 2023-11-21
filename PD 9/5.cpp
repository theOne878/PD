#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
const int number=10;
int main(){
    int array[number];
    cout<<"Enter the data of 10 boxes "<<endl;
    for(int i=0;i<number;i++){
        cout<<i+1<<": ";
        cin>>array[i];
    }
    for(int i=1;i<number;i++){
        for(int j=1;j<number;j++)
       {
        if(array[j] <array[j-1])
        {
            int temp=array[j];
            array[j]=array[j-1];
            array[j-1]=temp;
        }}
    }
    for(int j=0;j<number;j++){
        cout<<array[j]<<" ";
    }
}