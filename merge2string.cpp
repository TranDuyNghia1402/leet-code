#include <iostream>
#include <string.h>

int main() {
    std::string w1, w2, rs, substr;
    std::cin >> w1 >> w2;
    int limit = w1.length() <= w2.length() ? w1.length() : w2.length();
    for (int i = 0; i < limit; i++) {
        rs += w1[i];
        rs += w2[i];
    }
    if (limit == w1.length()) {
        substr = w2.erase(0, limit);
    } 
    else {
        substr = w1.erase(0, limit);
    }
    rs += substr;
    std::cout << rs << "\n" << rs.length();
    return 0;
}