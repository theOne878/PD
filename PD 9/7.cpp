#include <iostream>
using namespace std;
bool reArranged(int arr[],int length);
int main(){
	int length;
	cout << "Enter the length of the array: ";
	cin >> length;
	int arr[length];
	cout << "Enter the elements of the array: "<< endl;
	for(int i=0; i<length; i++){
		cin >> arr[i];
	}
	cout << "Can be arranged: "<<reArranged(arr,length);
}
bool reArranged(int arr[],int length){
	int temp;
	int arranged[length];
	for(int i=0; i<length; i++){
		temp = arr[i];

		for(int j=length;j>i;j--){
				if(arr[j]<temp){
					temp=arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
		}
		arranged[i] = temp;
	}
	for(int i=0; i<length-1;i++){
		if(arranged[i+1] != arranged[i]+1){
			return false;
		}
	}
	return true;
}

