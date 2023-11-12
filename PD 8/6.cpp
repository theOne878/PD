#include <iostream>
#include <string>
using namespace std;
int calculateColoringTime(string* array, int size);
int main() {
    int size;
    int count = 0;
    cout << "Enter the number of inputs: ";
    cin >> size;
    string array[size];
    for (int i = 0; i < size; i++) {
        count++;
        cout << "Element of " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "Time to colour: " << calculateColoringTime(array, size) << " Seconds" << endl;
    return 0;
}
int calculateColoringTime(string* array, int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] != array[i + 1]) {
            count++;
        }
    }
    return (size * 2) + count;
}
