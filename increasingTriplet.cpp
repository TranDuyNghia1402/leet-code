#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> container {nums[0]};
        for (int i = 1; i < nums.size(); i++) {  
            if (container[container.size()-1] < nums[i]) 
                container.push_back(nums[i]);
            else {
                if (container[0] == nums[i]) continue;
                if (container[0] > nums[i])  container[0] = nums[i];
                else container[1] = nums[i];

            }
            if (container.size() == 3) return true;        
        }
        return false;
    }

    bool increasingTriplet2(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        } else {              // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
}
};

int main() {
    vector<int> nums {2, 6, 1, 8};
    Solution solution;
    for (auto x : nums) cout << x << "\t";
    cout << "\nresult: " << (solution.increasingTriplet2(nums) ? "True" : "False");
    return 0;
}