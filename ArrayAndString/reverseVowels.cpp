#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        string vowels = "";
        string str = "aeiou";
        for (int i = 0; i < s.length(); i++) {
            if (str.find(tolower(s[i])) != string::npos) {
                index.push_back(i);
                vowels += s[i];          
            }       
        }
        for (int i = 0; i < index.size(); i++) {
            swap(s[index[i]],vowels[index.size()-1-i]);
        }
        return s;
    }

    string reverseVowels2(string s) {
        string str = "aeiou";
        int first_vowel = 0;
        for (int last_vowel = s.length()-1; last_vowel >= 0; last_vowel--) {
            if (str.find(tolower(s[first_vowel])) != string::npos) {
                if (str.find(tolower(s[last_vowel])) != string::npos) {
                    swap(s[last_vowel], s[first_vowel]);
                    first_vowel++;
                }
            }
            else {
                first_vowel++;
                last_vowel++;
            }
            if (last_vowel <= first_vowel) return s;      
        }
        return s;
    }
};

int main() {
    Solution solution;
    cout << solution.reverseVowels2("hello") << endl;
    cout << solution.reverseVowels2("leetcode") << endl;
    return 0;
}