#include <iostream>
#include <cmath>
using namespace std;
int Malus(int number);
int main(){
    int number;
    int start;
    int end;
    int count1=0;
    int sum1=0;
    cout<<"Enter start:";
    cin>>start;
    cout<<"Enter end: ";
    cin>>end;
    for(int number=start;number<=end;number++){
        if(Malus(number)){
          sum1=sum1+number;
          count1++;
        }
    }
     cout<<sum1/count1;
    
}
int Malus(int number){
    int total,total1,total2;
    int count=0;
    total=total1=total2=number;
    while(number>0){
        number=number/10;
        count++;
    }
    int h;
    h=count;
    int sum=0;
    while(total>0){
    total1=total%10;
    total=total/10;
    sum=sum+pow(total1,h);
    h--;
    }
    if(sum==total2){
        return total2;
    }
    else{
        return 0;
    }
}
