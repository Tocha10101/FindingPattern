#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#define CHAR_NUM 256

using namespace std;

vector<char> make_symb_table(vector<char> pattern) {
    vector<char> badchars(CHAR_NUM);
    
    for (int i = 0; i < CHAR_NUM; i++) {

        badchars[i] = pattern.size();
    }
    
    int i;
    for (i = 0; i < pattern.size() - 1; i++) {
        badchars[(int) pattern[i]] = pattern.size() - 1 - i;
    }
    return badchars;
}


int main() {
    vector<char> patt{'l', 'o', 'c', 'o'};
    
    vector<char> chars = make_symb_table(patt);

    // for (int i = 0; i < patt.size(); i++) {
    //     cout << patt[i] << " : " << chars[patt[i]] << endl; 
    // }

    std::string alpha = "Tú me tienes loco, loco contigo";
    std::string stra(patt.begin(), patt.end());
    cout << "To find: " << stra << endl;
    cout << "In: " << alpha << endl;
    vector<char> text(alpha.begin(), alpha.end());
    // vector<string> text;
    // for (auto &c : v) {
    //     text.push_back(std::string(1, c));
    // }

    // for (auto el : patt) {
    //     cout << el << endl;
    // }

    // the algorithm itself
    
    int len_patt = patt.size();
    int len_text = text.size();
    
    int i = 0, j, at_least_one, found = 0, found_count = 0;
    cout << "before the chercher" << endl;
    while (i < len_text - len_patt + 1) {
        at_least_one = 0;
        found = 1;
        for (j = len_patt - 1; j > 0; j--) {
            if (text[i + j] != patt[j]) {
                found = 0;
                break;
            } else {
                at_least_one = 1;
            }
        }

        if (found) {
            cout << "Found a pattern for index: " << i << endl;
            found_count = 1;
        }

        if (at_least_one) {
            i += chars[patt[len_patt - 1]];
        } else {
            i += chars[text[i + j]];
        }
    }

    if (!found_count) {
        cout << "Can't find a pattern =(" << endl;
    }

    return 0;
}