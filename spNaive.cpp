#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    char text[100], pattern[100];

    cout << "Enter a string to search: ";
    cin.getline(text, 100);
    
    cout << "Enter a pattern to search for: ";
    cin.getline(pattern, 100);

    int len_text = strlen(text), len_patt = strlen(pattern);
    int found = 0, at_least_once = 0;

    for (int i = 0; i < len_text - len_patt + 1; i++) {
        
        found = 1;
        for (int j = 0; j < len_patt; j++) {
            if (text[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            cout << "Found pattern which begins at index: " << i << endl;
            at_least_once = 1;
            continue;
        }

    }

    if (!at_least_once) {
        cout << "Can't find a pattern =(" << endl;
        return 1;
    }

    return 0;
}