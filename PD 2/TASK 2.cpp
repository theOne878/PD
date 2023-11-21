#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
void menu(){
    cout<<"      __  __                      "<<endl;
    cout<<"     |  \\/  | ___  __ _  __ _    "<<endl;
    cout<<"     | |\\/| |/ _ \\/ _` |/ _` |  "<<endl;
    cout<<"     | |  | |  __/ (_| | (_| |    "<<endl;
    cout<<"     |_|  |_|\\___|\\__, |\\__,_| "<<endl;
    cout<<"     |  \\/  | __ _|___/| |_      "<<endl;
    cout<<"     | |\\/| |/ _` | '__| __|     "<<endl;
    cout<<"     | |  | | (_| | |  | |_       "<<endl;
    cout<<"     |_|  |_|\\__,_|_|   \\__|    "<<endl;
}
bool signedUp(string name, string pass, const string username[], const string password[], const string role[], int count){    for(int i=0;i<count;i++){
        if(username[i]==name&&password[i]==pass){
            return true;
        }
    }
    return false;}
bool admin_signin(const string username[], const string password[], int& count){
     string ad_name,ad_pass;
    cout<<"Enter Your Name: ";
    cin>>ad_name;
    cout<<"Enter Password: ";
    cin>>ad_pass;
    if(ad_name=="Ibraheem"&&ad_pass=="Password"){
        return true;
    }
    else {
        cout<<"Invalid Username And Password";
        return false;
    }
    return true;   
}
void displayVegetables(const string Vegetables[], const int VegetablePrice[]){
      cout<< "Item No." << setw(10) << "Vegetable" << setw(20) << "Price" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 40; ++i) {
        if (!Vegetables[i].empty()){
        cout<< setw(11) << left << (i + 1) << setw(20) << left << Vegetables[i] << setw(10) << right << VegetablePrice[i] << endl;
    }
    }
     cout << "\nYou can only read these items, cannot change them." << endl;
    cout << "Enter '1' to exit: ";
    int exitOption;
    cin >> exitOption;
    if (exitOption == 1) {
        return;
    } else {
        cout << "You can only exit. Returning to the admin page." << endl;
    }  
}
void displayFruits(const string Fruits[], const int FruitsPrice[]){
        cout<< "Item No." << setw(10) << "Fruit" << setw(20) << "Price" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 45; ++i) {
        if (!Fruits[i].empty()){
        cout<< setw(11) << left << (i + 1) << setw(20) << left << Fruits[i] << setw(10) << right << FruitsPrice[i] << endl;
    }
    }
     cout << "\nYou can only read these items, cannot change them." << endl;
    cout << "Enter '1' to exit: ";
    int exitOption;
    cin >> exitOption;
    if (exitOption == 1) {
        return;
    } else {
        cout << "You can only exit. Returning to the admin page." << endl;
    }
}
void displayCosmetics(const string Cosmetics[], const int CosmeticsPrice[]){
        cout<< "Item No." << setw(10) << "Cosmetic" << setw(20) << "Price" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 30; ++i) {
        if (!Cosmetics[i].empty()){
        cout<< setw(11) << left << (i + 1) << setw(20) << left << Cosmetics[i] << setw(10) << right << CosmeticsPrice[i] << endl;
    }
    }
     cout << "\nYou can only read these items, cannot change them." << endl;
    cout << "Enter '1' to exit: ";
    int exitOption;
    cin >> exitOption;
    if (exitOption == 1) {
        return;
    } else {
        cout << "You can only exit. Returning to the admin page." << endl;
    }
}
void displayFastFood(const string FastFood[], const int FastFoodPrice[]){
        cout<< "Item No." << setw(13) << "Fast Food Item" << setw(20) << "Price" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < 20; ++i) {
        if (!FastFood[i].empty()){
        cout<< setw(12) << left << (i + 1) << setw(20) << left << FastFood[i] << setw(10) << right << FastFoodPrice[i] << endl;
    }
    }
     cout << "\nYou can only read these items, cannot change them." << endl;
    cout << "Enter '1' to exit: ";
    int exitOption;
    cin >> exitOption;

    if (exitOption == 1) {
        return;
    } else {
        cout << "You can only exit. Returning to the admin page." << endl;
    }
}
void addNewVegetable(string Vegetables[], int VegetablePrice[], int& newIndex){
        static int newIndex = 15; 
    if (newIndex < 40) {
        string newVegetable;
        int newVegetablePrice;
        cout << "Enter the name of the new vegetable: ";
        cin.ignore();
        getline(cin, newVegetable);
        cout << "Enter the price of " << newVegetable << ": ";
        cin >> newVegetablePrice;
        if (newVegetable.empty()) {
            cout << "Invalid input: Vegetable name cannot be empty." << endl;
            return;
        }
        if (newVegetablePrice <= 0) {
            cout << "Invalid input: Vegetable price must be a positive value." << endl;
            return;
        }
        Vegetables[newIndex] = newVegetable;
        VegetablePrice[newIndex] = newVegetablePrice;
        cout << "New vegetable record added successfully at index " << (newIndex + 1) << "!" << endl;
        newIndex++;
    } else {
        cout << "Invalid index for adding a new vegetable record either Array is full or name is empty." << endl;
    }
}
void addNewFruits(string Fruits[], int FruitsPrice[], int& newIndex){
        static int newIndex=12;
    if(newIndex<45){
        string newFruit;
        int newFruitPrice;
        cout<<"Enter the Name of New fruit: ";
        cin.ignore();
        getline(cin,newFruit);
        cout<<"Enter the price of "<<newFruit<<": ";
        cin>>newFruitPrice;
        if (newFruit.empty()) {
            cout << "Invalid input: Fruit name cannot be empty." << endl;
            return;
        }
        if (newFruitPrice <= 0) {
            cout << "Invalid input: Fruit price must be a positive value." << endl;
            return;
        }
        Fruits[newIndex]= newFruit;
        FruitsPrice[newIndex]=newFruitPrice;
        cout << "New Fruit record added successfully at index " << (newIndex + 1) << "!" << endl;
        newIndex++;
    } else {
        cout << "Invalid index for adding a new Fruit record either Array is full or name is empty." << endl;
    }
}
void addNewCosmetics(string Cosmetics[], int CosmeticsPrice[], int& newIndex){
      static int newIndex=10;
    if(newIndex<30){
    string newCosmetics;
    int newCosmeticsPrice;
    cout<<"Enter The Name of New cosmetic Product: ";
    cin.ignore();
    getline(cin,newCosmetics);
    cout<<"Enter The price of "<<newCosmetics<<": ";
    cin>>newCosmeticsPrice;
    if (newCosmetics.empty()) {
            cout << "Invalid input: Cosmetics name cannot be empty." << endl;
            return;
        }
        if (newCosmeticsPrice <= 0) {
            cout << "Invalid input: Cosmetics price must be a positive value." << endl;
            return;
        }
    Cosmetics[newIndex]=newCosmetics;
    CosmeticsPrice[newIndex]=newCosmeticsPrice;
    cout<<" New Cosmetic Product Record Added Successfully "<< (newIndex+1)<< "!"<<endl;
    newIndex++;
    }
    else{
        cout<<"Invalid Index For Adding A New Cosmetic either Array is full or name is empty."<<endl;
    }  
}
void addNewFastFood(string FastFood[], int FastFoodPrice[], int& newIndex){
        static int newIndex=6;
    if(newIndex<20){
    string newFastFood;
    int newFastFoodPrice;
    cout<<"Enter The Name of New FastFood Product: ";
    cin.ignore();
    getline(cin,newFastFood);
    cout<<"Enter The price of "<<newFastFood<<": ";
    cin>>newFastFoodPrice;
    if (newFastFood.empty()) {
            cout << "Invalid input: FastFood name cannot be empty." << endl;
            return;
        }
        if (newFastFoodPrice <= 0) {
            cout << "Invalid input: FastFood price must be a positive value." << endl;
            return;
        }
    FastFood[newIndex]=newFastFood;
    FastFoodPrice[newIndex]=newFastFoodPrice;
    cout<<" New FastFood Product Record Added Successfully "<< (newIndex+1)<< "!"<<endl;
    newIndex++;
    }
    else{
        cout<<"Invalid Index For Adding A New FastFood either Array is full or name is empty."<<endl;
    }
}
void newvegetableprice(string Vegetables[], int VegetablePrice[]);
void newfruitprice(string Fruits[], int FruitsPrice[]);
void newcosmeticsprice(string Cosmetics[], int CosmeticsPrice[]);
void newfastfoodprice(string FastFood[], int FastFoodPrice[]);
void admin(const string username[], const string password[], const string role[], string Vegetables[], int VegetablePrice[],
           string Fruits[], int FruitsPrice[], string Cosmetics[], int CosmeticsPrice[],
           string FastFood[], int FastFoodPrice[], int& count) {
    if (admin_signin(username, password, count)) {
        int adminOption;
        cout << "You Have Successfully Logged In As Admin" << endl;
        system("pause");
        system("cls");
        do {
            cout << "1: View The Vegetables List" << endl;
            cout << "2: View The Fruits List" << endl;
            cout << "3: View The Cosmetics List" << endl;
            cout << "4: View Fast Food List" << endl;
            cout << "5: Insert New Vegetables Record" << endl;
            cout << "6: Insert New Fruits Record" << endl;
            cout << "7: Insert New Cosmetics Products Record" << endl;
            cout << "8: Insert New Fast Food Items Record" << endl;
            cout << "9: Edit the price of Vegetables" << endl;
            cout << "10: Edit the price of Fruits" << endl;
            cout << "11: Edit the price of Cosmetics" << endl;
            cout << "12: Edit the price of FastFood" << endl;
            cout << "13: Delete Vegetables Record" << endl;
            cout << "14: Delete Fruits Record" << endl;
            cout << "15: Delete Cosmetics Products Record" << endl;
            cout << "16: Delete Fast Food Items Record" << endl;
            cout << "17: View The Customers" << endl;
            cout << "18: Delete The Customer" << endl;
            cout << "19: Promote The Regular To special customer" << endl;
            cout << "20: Issue A Sale On items" << endl;
            cout << "21: Exit" << endl;
            cout << "Enter The Option :";
            cin >> adminOption;
            switch (adminOption) {
                case 1: {
                    system("cls");
                    displayVegetables(Vegetables, VegetablePrice);
                    break;
                }
                case 2: {
                    system("cls");
                    displayFruits(Fruits, FruitsPrice);
                    break;
                }
                case 3: {
                    system("cls");
                    displayCosmetics(Cosmetics, CosmeticsPrice);
                    break;
                }
                case 4: {
                    system("cls");
                    displayFastFood(FastFood, FastFoodPrice);
                    break;
                }
                case 5: {
                    system("cls");
                    addNewVegetable(Vegetables, VegetablePrice, count);
                    break;
                }
                case 6: {
                    system("cls");
                    addNewFruits(Fruits, FruitsPrice, count);
                    break;
                }
                case 7: {
                    system("cls");
                    addNewCosmetics(Cosmetics, CosmeticsPrice, count);
                    break;
                }
                case 8: {
                    system("cls");
                    addNewFastFood(FastFood, FastFoodPrice, count);
                    break;
                }
                case 9: {
                    newvegetableprice(Vegetables, VegetablePrice);
                    break;
                }
                case 10: {
                    newfruitprice(Fruits, FruitsPrice);
                    break;
                }
                case 11: {
                    newcosmeticsprice(Cosmetics, CosmeticsPrice);
                    break;
                }
                case 12: {
                    newfastfoodprice(FastFood, FastFoodPrice);
                    break;
                }
                case 13: {
                    // Implement delete functionality for Vegetables
                    break;
                }
                case 14: {
                    // Implement delete functionality for Fruits
                    break;
                }
                case 15: {
                    // Implement delete functionality for Cosmetics
                    break;
                }
                case 16: {
                    // Implement delete functionality for FastFood
                    break;
                }
                case 17: {
                    // Implement view customers functionality
                    break;
                }
                case 18: {
                    // Implement delete customer functionality
                    break;
                }
                case 19: {
                    // Implement promote regular to special customer functionality
                    break;
                }
                case 20: {
                    // Implement issue sale functionality
                    break;
                }
                case 21: {
                    cout << "  Exiting admin menu  " << endl;
                    break;
                }
                default: {
                    cout << "Invalid Choice" << endl;
                }
            }
        } while (adminOption != 21);
    }
}

void signIn(const string username[], const string password[], const string role[], int count) {
    string name, pass;
    cout << "Enter Your name: ";
    cin >> name;
    cout << "Enter Your Pass: ";
    cin >> pass;
    if (signedUp(name, pass, username, password, role, count)) {
        cout << "You have successfully logged in " << name << " As A " << role[count - 1];
    }
    else {
        cout << "You haven't Registered Yet";
        cout << "\nSignUp First To continue\n";
    }
}
int signUp(string username[], string password[], string role[], int& count){
        int Option=1;
    while(Option!=2){
    cout<<"Enter Your Username:";
    cin>>username[count];
    cout<<"Enter your password:";
    cin>>password[count];
    cout<<"Enter your Role:";
    cin>>role[count];
    cout<<"You have successfully Signed Up\n";
    count++;
    cout<<"Do You want to Add Or Exit";
    cout<<"\n1: Add";
    cout<<"\n2: Exit";
    cout<<"\nYour Option: ";
    cin>>Option;
    switch(Option){
        case 1:
    {
        cout<<"Returning TO add more\n";
    }
    case 2:{
        break;
    }
    }
    }
    cout<<"Username"<<setw(18)<<"Password"<<setw(16)<<"Role\n";
    for(int i=0;i<count;i++){
        cout<<username[i]<<setw(20)<<password[i]<<setw(18)<<role[i]<<endl;
    }
    return 0;
}
int main() {
    const int number = 100;
    string username[number] = { " " };
    string password[number] = { " " };
    string role[number] = { " " };
    string Vegetables[40] = { "Beans", "Cabbage", "Capsicum", "Corn", "Garlic", "Ginger", "Lemon", "Onion", "Pepper", "Radish", "Spinach", "Tomato", "Pumpkin", "Potato", "Okra" };
    string Fruits[45] = { "Apple", "Banana", "Mango", "Peach", "Strawberry", "Orange", "Grapes", "pineapple", "Papaya", "Pear", "Dates", "Plum" };
    string Cosmetics[30] = { "Shampoo", "Oil", "Conditioner", "Cleanser", "Scrub", "Lipstick", "Perfume", "Bodyspray", "BodyLotion", "Facewash" };
    string FastFood[20] = { "Pizza", "Burger", "Paratha", "Fries", "HotDog", "Wings" };
    int VegetablePrice[40] = { 210,90,40,110,50,70,35,100,45,120,85,105,150,135,170 };
    int FruitsPrice[45] = { 120,100,400,220,300,210,150,380,340,200,420,240 };
    int CosmeticsPrice[30] = { 650,500,470,1100,800,350,1150,750,400,550 };
    int FastFoodPrice[20] = { 650,400,250,140,300,450 };
    int count = 0;
    menu();
    cout << "\n                               Welcome To Mega Mart        \n";
    int option;
    while (option != 4) {
        cout << " 1: Login As Admin";
        cout << "\n 2: SignUp (New User Only)";
        cout << "\n 3: SignIn (If you already Have Registered)";
        cout << "\n 4: Exit  ";
        cout << "\n Enter Your Option: ";
        cin >> option;

        switch (option) {
            case 1: {
                admin(username, password, role, Vegetables, VegetablePrice, Fruits, FruitsPrice,
                      Cosmetics, CosmeticsPrice, FastFood, FastFoodPrice, count);
                break;
            }
            case 2: {
                signUp(username, password, role, count);
                break;
            }
            case 3: {
                signIn(username, password, role, count);
                break;
            }
            case 4: {
                cout << "Thanks For Using Our service";
                return 0;
            }
            default: {
                cout << "Enter A Valid Option" << endl;
            }
        }
    }

    return 1;
}
