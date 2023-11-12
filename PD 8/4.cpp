#include<iostream>
using namespace std;
void evenOddTransform(int* array, int size, int n);
int main(){
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>array[i];
    }
    int n;
    cout<<"Enter the number of modifications: ";
    cin>>n;
    evenOddTransform(array,size,n);
}
void evenOddTransform(int* array, int size, int n){
    for(int i=0;i<size;i++){
        if(array[i]%2==0){
            array[i]=array[i]-(2*n);
        }
        else{
            array[i]=array[i]+(n*2);
        }
    }
    cout<<"["<<array[0];
for(int i=1;i<size;i++){
cout<<","<<array[i];
}
cout<<"]";
}