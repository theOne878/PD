#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
bool isRepeatingCycle(int* arr,int n,int cycleLength) {
    if (cycleLength>n) {
        return true;
    }
    for (int i=0;i<n;i++) {
        if (arr[i]!=arr[i%cycleLength]) {
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int userArray[n];
    cout << "Enter elements of the array separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> userArray[i];
    }
    int cycleLength;
    cout << "Enter the length of each cycle: ";
    cin >> cycleLength;
    bool result = isRepeatingCycle(userArray, n, cycleLength);
    cout << result << endl;
    return 0;
}
