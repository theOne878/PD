#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
int IsMalus(int count,int number,int total,int sum,int total1,int total2);
int main(){
    int count=0;
    int number;
    cin>>number;
    int total;
    int total1;
    int total2;
    total=total1=total2=number;
    
    int sum=0;
    cout<<IsMalus(count,number,total,sum,total1,total2);
    return 0;
}
int IsMalus(int count,int number,int total,int sum,int total1,int total2){
    while(number>0){
        
        number=number/10;
        count++;
      
    }
int h;
    
    h=count;
    while(total>0){
        total1=total%10;
        total=total/10;
       
        sum=sum+pow(total1,h);
        h--;
    }
    
   if(sum==total2){
    cout<<"true";
   }
   else{
    cout<<"false";
   }
}

