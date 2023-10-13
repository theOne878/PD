#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
const double banana=2.50;
const double apple=1.20;
const double orange=0.85;
const double grapefruit=1.45;
const double kiwi=2.70;
const double pineapple=5.50;
const double grapes=3.85;
const double banana1=2.70;
const double apple1=1.25;
const double orange1=0.90;
const double grapefruit1=1.60;
const double kiwi1=3.00;
const double pineapple1=5.60;
const double grapes1=4.20;
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity);
int main(){
    string fruit,dayOfWeek;
    double quantity;
    cout<<"Enter fuit name: ";
    cin>>fruit;
    cout<<"Enter the day of week: ";
    cin>>dayOfWeek;
    cout<<"Enter quantity: ";
    cin>>quantity;
    cout<<calculateFruitPrice(fruit,dayOfWeek,
quantity);
}
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity){
    if(dayOfWeek=="sunday"||dayOfWeek=="saturday"){
        if(fruit=="banana"){
            return banana1*quantity;
        }
        if(fruit=="apple"){
            return apple1*quantity;
        }
        if(fruit=="orange"){
            return orange1*quantity;
        }
        if(fruit=="grapefruit"){
            return grapefruit1*quantity;
        }
        if(fruit=="kiwi"){
            return kiwi1*quantity;
        }
        if(fruit=="pineapple"){
            return pineapple1*quantity;
        }
        if(fruit=="grapes"){
            return grapes1*quantity;
        }

    }
    else if(dayOfWeek=="monday"||dayOfWeek=="tuesday"||dayOfWeek=="wednesday"||dayOfWeek=="thursday"||dayOfWeek=="friday"){
        if(fruit=="banana"){
            return banana*quantity;
        }
        if(fruit=="apple"){
            return apple*quantity;
        }
        if(fruit=="orange"){
            return orange*quantity;
        }
        if(fruit=="grapefruit"){
            return grapefruit*quantity;
        }
        if(fruit=="kiwi"){
            return kiwi*quantity;
        }
        if(fruit=="pineapple"){
            return pineapple*quantity;
        }
        if(fruit=="grapes"){
            return grapes*quantity;
        }

    }
}
