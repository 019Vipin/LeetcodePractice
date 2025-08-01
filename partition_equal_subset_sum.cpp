#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int ts = 0;
        for (int i = 0; i < n; i++) {
            ts += nums[i];
        }
        if (ts % 2 == 1) {
            return false;
        }
        int k = ts / 2;
        vector<bool> prev(k + 1, false); 
        prev[0] = true;

        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> cur(k + 1, false);
            cur[0] = true;

            for (int j = 1; j <= k; j++) {
                bool notTaken = prev[j];
                bool taken = false;

                if (nums[i] <= j) {
                    taken = prev[j - nums[i]];
                }

                cur[j] = notTaken || taken;
            }
            prev = cur;
        }
        return prev[k];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << (sol.canPartition(nums) ? "True" : "False") << endl;
    return 0;
}
