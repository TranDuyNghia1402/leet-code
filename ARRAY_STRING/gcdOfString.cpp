#include <iostream>

int main() {
    std::string a, b, rs;
    std::cin >> a >> b;
    if (a[0] != b[0]) rs = "";
    int common_length;
    int limit = (a.length() > b.length()) ? a.length() : b.length();
    for (int i = 0; i < limit; i++) {
        if (limit == a.length()) {
            if (a[0] == a[i]) {
                common_length = i;
            }
        } else {
            if (b[0] == b[i]) {
                common_length = i;
            }
        }
    }
    std::cout << rs << "\n" << rs.length();
    return 0;
}