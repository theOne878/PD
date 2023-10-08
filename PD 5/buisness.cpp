#include <iostream>
#include <string>
using namespace std;


void displayHeader() {
system("COLOR 97");
    cout << "+-------------------------------------+-------------------------------------------+----------------------+" << endl;
    cout << "|                                   Ibraheem Fresh and Fit Grocery                                       |" << endl;
    cout << "+-------------------------------------+-------------------------------------------+----------------------+  " << endl;
}
void displayheader2(){
system("COLOR 97");
cout<<"#######################################################################################         "<<endl;
cout<<"#__ ____  ____   ___  __  __  ____  ____ ___  ___     ____ ____   ____  __  __  __    #         "<<endl;
cout<<"#|| || )) || \\\\ // \\\\ ||  || ||    ||    ||\\\\//||    ||    || \\\\ ||    (( \\ ||  ||    #  "<<endl;
cout<<"#|| ||=)  ||_// ||=|| ||==|| ||==  ||==  || \\/ ||    ||==  ||_// ||==   \\\\  ||==||    #"<<endl;
cout<<"#|| ||_)) || \\\\ || || ||  || ||___ ||___ ||    ||    ||    || \\\\ ||___ \\_)) ||  ||    #"<<endl;
cout<<"#                                                                                     #"<<endl;
cout<<"# ___  __  __ ____       ____ __ ______      ___  ____    ___     ___  ____ ____  _  _#"<<endl;
cout<<"#// \\\\ ||\\ || || \\\\     ||    || | || |     // \\\\ || \\\\  // \\\\   //   ||    || \\\\ \\\\//#"<<endl;
cout<<"#||=|| ||\\\\|| ||  ))    ||==  ||   ||      (( ___ ||_// ((   )) ((    ||==  ||_//  )/ #"<<endl;
cout<<"#|| || || \\|| ||_//     ||    ||   ||       \\\\_|| || \\\\  \\\\_//   \\\\__ ||___ || \\\\ //  #"<<endl;
cout<<"#######################################################################################"<<endl;
cout<<""<<endl;}

void addItem1(string& item1Name, double& item1Price) {
    cout << "Enter the name of Item  1: ";
    cin >> item1Name;
    cout << "Enter the price of Item 1: ";
    cin >> item1Price;
}

void addItem2(string& item2Name, double& item2Price) {
    cout << "Enter the name of Item  2: ";
    cin >> item2Name;
    cout << "Enter the price of Item 2: ";
    cin >> item2Price;
}


void addItem3(string& item3Name, double& item3Price) {
    cout << "Enter the name of Item  3: ";
    cin >> item3Name;
    cout << "Enter the price of Item 3: ";
    cin >> item3Price;
}


double calculateTotalBill(double item1Price, double item2Price, double item3Price) {
    double subtotal = item1Price + item2Price + item3Price;
    double tax = 0.03 * subtotal;
    double totalAmount = subtotal + tax;
    return totalAmount;
}


void displayReceipt(string item1Name, double item1Price, string item2Name, double item2Price, string item3Name, double item3Price) {
    cout << "\nReceipt:\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Name\t\t\tPrice\t\t\t       TotalPrice\n";
    cout << "----------------------------------------------------------------------\n";
    cout << item1Name << "                   pkr " << item1Price <<"                         "<<item1Price << endl;
    cout <<"         "<< "\t\t\t\t   " <<"             "<<"                                               " <<endl; 
    cout << item2Name << "                   pkr " << item2Price <<"                         "<<item2Price << endl;
    cout <<"         "<< "\t\t\t\t   " <<"             "<<"                                               " <<endl; 
    cout << item3Name << "                   pkr " << item3Price <<"                        +"<<item3Price <<  endl;
    cout <<"         "<< "\t\t\t\t   " <<"                    "<<item1Price+item2Price+item3Price<<endl;    
    cout << "----------------------------------------------------------------------\n";
}

int main() {
    string item1Name, item2Name, item3Name;
    double item1Price = 0, item2Price = 0, item3Price = 0;

    displayHeader();
    displayheader2();
    system("pause");
    system("cls");
    system("COLOR 87");
    addItem1(item1Name, item1Price);
    addItem2(item2Name, item2Price);
    addItem3(item3Name, item3Price);

    double totalAmount = calculateTotalBill(item1Price, item2Price, item3Price);

    displayReceipt(item1Name, item1Price, item2Name, item2Price, item3Name, item3Price);
    cout << "-----------------------------------------------------------------------\n";
    cout << "Total Payable (without tax):\tpkr " << item1Price + item2Price + item3Price << endl;
    cout << "Tax (3%):\t\t\tpkr " << 0.03 * (item1Price + item2Price + item3Price) << endl;
    cout << "Total Payable (including tax):\tpkr " << totalAmount << endl;
    cout << "Total payable Amount in $ is:   $"<<totalAmount/282 <<endl;

    return 0;
}
