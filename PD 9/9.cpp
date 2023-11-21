#include<iostream>
using namespace std;
int specialNumber(int length,int arr[]);
int main(){
	int length;
	cout << "Enter the length of the array: ";
	cin >> length;
	int arr[length];
	cout << "Enter the elements of the array: "<< endl;
	for(int i=0; i<length; i++){
		cin >> arr[i];
	}
	cout << "Special value: " << specialNumber(length,arr);
}
int specialNumber(int length,int arr[]){
			for(int specialNum=2;specialNum<1000;specialNum++){
					int counter = 0;	
				for(int i=0; i<length;i++){	
					if(arr[i]>=specialNum){
						counter++;
					}
				}
				if(counter==specialNum){
					return specialNum;
					}
			}
	return -1;
}
