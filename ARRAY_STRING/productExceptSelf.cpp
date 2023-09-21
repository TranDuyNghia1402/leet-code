#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left_product = {1}, right_product = {1};
        for (int i = 1; i < nums.size(); i++) {
            left_product.push_back(left_product[i-1] * nums[i-1]);
            right_product.push_back(right_product[i-1] * nums[nums.size()-i]);
        }  
        for (int i = 0; i < left_product.size(); i++) {
            left_product[i] *= right_product[left_product.size()-1-i];
        }
        return left_product;
    }
};

int main() {
    vector<int> input {-1,1,0,-3,3};

    Solution solution;

    for (auto element : solution.productExceptSelf(input))
        cout << element << "\t";

    return 0;
}