#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    int size;
    int count=0;
    cout<<"Enter the number of saturdays You work on: ";
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cout<<"Enter miles run for saturday "<<i+1<<": ";
        cin>>array[i];
        }
    for(int i=0;i<size-1;i++){
        if(array[i]<array[i+1]){
            count++;
        }
    }
    cout<<"Total progress days: "<<count;
    return 0;
}
