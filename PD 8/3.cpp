#include<iostream>
using namespace std;
bool same(string* numbers, int size);
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    string numbers[size];
    for (int i=0;i<size;i++) {
        cout<<"Element " <<i+1<<": ";
        cin>>numbers[i];
    }
    cout << same(numbers, size);
    return 0;
}
bool same(string* numbers, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (numbers[i] != numbers[i + 1]) {
            return false;
        }
    }
    return true;
}
