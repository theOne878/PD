#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int length;
    int sum=0;
    cout<<"Enter the length of array: ";
    cin>>length;
    string array[length];
    for(int i=0;i<length;i++){
        cin>>array[i];
        if(array[i]=="right"||array[i]=="Right"){
            sum+=90;
        }
        if(array[i]=="left"||array[i]=="Left"){
            sum-=90;
        }
    }
        sum=sum/360;
        
    
    cout<<abs(sum);
    return 0;
}