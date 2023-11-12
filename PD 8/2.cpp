#include <iostream>
#include <string>
using namespace std;
string containsSeven(int* numbers,int size);
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int numbers[size];
    for (int i=1;i<=size;++i) {
        cout<<"Element of "<<i<<": ";
        cin>>numbers[i];
    }
    string result=containsSeven(numbers,size);
    cout<<result<<endl;
    return 0;
}
string containsSeven(int* numbers,int size){
    for(int i=1;i<=size;++i){
        while(numbers[i]!=0){
            int digit=numbers[i]%10;
            if(digit==7){
                return "Boom!";
            }
            numbers[i]/=10;
        }
    }
    return "There is no 7 in the array";
}
