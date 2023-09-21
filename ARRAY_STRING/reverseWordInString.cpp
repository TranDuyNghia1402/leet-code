#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        s += " ";
        std::vector<std::string> str_vec;
        std::string sub;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') 
                sub += s[i];        
            else {
                if (sub != "") str_vec.insert(str_vec.begin(), sub + " ");
                sub = "";
            }
        }
        for (auto str: str_vec) {
            sub += str;
        }
        return sub.erase(sub.length()-1);
    }

    std::string reverseWords2(std::string s) {
        s = " " + s;
        int mark = 0;
        std::string sub, result;
        for (int i = s.length()-1; i >= 0; i--){
            if (s[i] != ' ') { 
                mark++;
            }      
            else {
                sub = s.substr(i, mark+1);
                mark = 0;
                if (sub != "" && sub != " ") result += sub; 
                sub = "";
            }
        }
        return result.erase(0, 1);
    }
};

int main() {
    std::string s = "a good   example";
    std::cout << s.length() << std::endl;
    Solution solution;
    std::string result = solution.reverseWords2(s);
    for (int i = 0; i < result.length(); i++) 
        if (result[i] == ' ') result[i] = '-';
    std::cout << result;
    return 0;
}