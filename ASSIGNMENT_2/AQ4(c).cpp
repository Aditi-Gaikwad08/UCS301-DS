#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

int main() {
    string str, result;
    cout << "Enter a string: ";
    cin >> str;

    for(char c : str) {   // for-each loop
        if(!isVowel(c)) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}