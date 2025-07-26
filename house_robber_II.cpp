#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robh(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int nonPick = prev;
            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> arr1, arr2;
        for (int i = 0; i < n; i++) {
            if (i != 0) arr1.push_back(nums[i]);
            if (i != n - 1) arr2.push_back(nums[i]);
        }

        int ans1 = robh(arr1);
        int ans2 = robh(arr2);

        return max(ans1, ans2);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 2}; 
    cout << "Max Robbed Amount: " << sol.rob(nums) << endl;
    return 0;
}
