#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    string result = s1 + s2;   // Concatenation
    cout << "Concatenated string: " << result << endl;

    return 0;
}