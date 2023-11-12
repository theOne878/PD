#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int cargos;
	cout << "Enter the count of cargo for transportation: ";
	cin >> cargos;
	
	int cargo = 1;
	int tonnage = 0;
	int sumofCargo = 0;
	float bus, truck, train = 0;
	float averagePrice, percentofBus, percentofTruck, percentofTrain;
	
	while(cargo <= cargos){
		cout << "Enter the tonnage of cargo " << cargo << ": ";
		cin >> tonnage;
		
		sumofCargo = sumofCargo + tonnage;
		
		if(tonnage <= 3){
			bus = bus + tonnage;
		}
		if(tonnage > 3 && tonnage <= 11){
			truck = truck + tonnage;
		}
		if(tonnage > 11){
			train = train + tonnage;
		}
		cargo++;
	}
	averagePrice = (bus*200 + truck*175 + train*120) / sumofCargo;
	percentofBus = (bus/sumofCargo) * 100;
	percentofTruck = (truck/sumofCargo) * 100;
	percentofTrain = (train/sumofCargo) * 100;
	
	cout<<fixed<<setprecision(2)<<averagePrice<<endl<<setprecision(2)<<percentofBus<<"%"<<endl<<setprecision(2)<<percentofTruck<<"%"<<endl<<setprecision(2)<<percentofTrain<< "%";
}
