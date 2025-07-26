#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique;
        int maxElement = nums[0];
        int sum = 0;

        for (int num : nums) {
            maxElement = max(maxElement, num);
            if (!unique.count(num)) {
                unique.insert(num);
                if (num >= 0) {
                    sum += num;
                }
            }
        }

        return maxElement < 0 ? maxElement : sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -10, 6, 2, -10, 6};
    cout << "Max Unique Subarray Sum: " << sol.maxSum(nums) << endl;
    return 0;
}
