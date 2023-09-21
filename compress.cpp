#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(' ');
        char mark_char = chars[0];
        int mark = 1;
        string m;
        for (int i = 1; i < chars.size(); i++) {
            if (mark_char == chars[i]) {
                mark++;            
                chars.erase(chars.begin()+i);
                i--;
            }
            else {
                if (mark != 1) {
                    m = to_string(mark); 
                    for (int j = 0; j < m.length(); j++)
                        chars.insert(chars.begin()+i+j, m[j]);                
                    i+=m.length();
                    mark = 1;
                }
                mark_char = chars[i];
            }
        }   
        chars.pop_back();     
        return chars.size();
    }
};

int main() {
    vector<char> chars {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    Solution solution;
    int result = solution.compress(chars);
    cout << "chars after compress:\n";
    for (auto x : chars) {
        cout << x << " ";
    }
    cout << endl << "length of chars: " << result;
    return 0;
}