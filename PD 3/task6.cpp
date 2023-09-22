#include<iostream>
using namespace std;
int main(){
double size,cost,area;
cout << "Enter the size of fertilizer bag in pounds:" ;
cin >>size;
cout << "Enter the cost of bag: $" ;
cin >> cost;
cout << "Enter the area in square feet that can be covered by the bag:" ;
cin >> area;
double costperpound=cost/size;
double costperfoot=area*size;
cout << "Cost of fertilizer per pound: $" << costperpound  <<endl;
cout << "Cost of fertilizing per square foot: $" <<costperfoot <<endl;














return 0;
}