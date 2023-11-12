#include<iostream>
using namespace std;
void sequence(int multiply,int numb);
int main(){
    int multiply=1;
    int numb;
    cout<<"Enter the number to amplify: ";
    cin>>numb;
    sequence(multiply,numb);
}
void sequence(int multiply,int numb){
    for(int i=1;i<=numb;i++){
            if(i%4==0){
        cout<< i*10<< " ";
            }
        else{
            if(i==numb){
                cout<<i;
            }
                else{
                    cout<< i<<" ";
                }
            
            
        }
        
    } 
}
