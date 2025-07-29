#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:  
    int count = 0;

    void findsubsets(int idx, int currOR, vector<int>& nums, int maxOR) {
        if (idx == nums.size()) {
            if (currOR == maxOR) {
                count++;
            }
            return;
        }

        findsubsets(idx + 1, currOR | nums[idx], nums, maxOR);

        findsubsets(idx + 1, currOR, nums, maxOR);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;

        for (int num : nums) {
            maxOR |= num;
        }

        findsubsets(0, 0, nums, maxOR);
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1};

    int result = sol.countMaxOrSubsets(nums);
    cout << "Number of subsets with max OR: " << result << endl;

    return 0;
}
