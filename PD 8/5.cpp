#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int count = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int occurrencesInS1 = 0;
        int occurrencesInS2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            char c = s1[i];
            if (tolower(c) == ch) {
                occurrencesInS1++;
            }
        }
        for (int i = 0; i < s2.length(); i++) {
            char c = s2[i];
            if (tolower(c) == ch) {
                occurrencesInS2++;
            }
        }
        count += min(occurrencesInS1, occurrencesInS2);
    }
    cout << count << endl;
    return 0;
}
