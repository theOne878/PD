#include<iostream>
using namespace std;
int main(){
double veg_price,fr_price,to_veg,to_fruit;
cout << "Enter vegetable price per kilogram(in coins):" ;
cin>>veg_price;
cout << "Enter fruit price per kilogram(in coins):" ;
cin>>fr_price;
cout << "Enter total kilogram of vegetable:" ;
cin>>to_veg;
cout << "Enter total kilogram of fruit:" ;
cin>>to_fruit;
double earning=(veg_price/1.94*to_veg)+(fr_price/1.94*to_fruit);
cout << "Total earning in ruppees(rps):" << earning;















return 0;
}