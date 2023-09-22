#include<iostream>
using namespace std;
int main(){
string name;
double ad_ticket,ch_ticket,ad_sold,ch_sold,charity;
cout << "Enter the movie name:" ;
getline(cin,name);
cout << "Enter the adult ticket price:" ;
cin>>ad_ticket;
cout << "Enter the child ticket price:" ;
cin>>ch_ticket;
cout << "Enter the number of adult tickets sold: $" ;
cin>>ad_sold;
cout << "Enter the number of child tickets sold: $" ;
cin>>ch_sold;
cout << "Enter the percentage of amount donated to charity:" ;
cin>>charity;
double sales=(ch_ticket*ch_sold)+(ad_ticket*ad_sold);
double chari=sales/charity;
double remaining=sales-chari;
cout<< "Movie:" << name <<endl;
cout<<"total amount generated from ticket sales: $" << sales <<endl;
cout<<"Donation to charity: $"<< chari <<endl;
cout<<"Remaining amout after donation:"<< remaining <<endl;

















return 0;
}