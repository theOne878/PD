#include<iostream>
using namespace std;
bool isPrime(int number);
int main(){
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    cout<<isPrime(number);
}
bool isPrime(int number){
    if(number%2==0||number%3==0||number%5==0){
        return false;
    }
    else
    return true;

}
