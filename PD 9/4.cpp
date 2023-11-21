#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int length,width,height;
    int number;int sum=0;
    cout<<"Enter the Number of Boxes: ";
    cin>>number;
    for(int i=0;i<number;i++){
        cout<<"Enter Length:";
        cin>>length;
        cout<<"Enter height: ";
        cin>>height;
        cout<<"Enter width: ";
        cin>>width;
        int product=length*height*width;
        sum+=product;
    }
    cout<<"Total volume of all boxes: "<<sum;
    return 0;
}