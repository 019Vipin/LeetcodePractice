#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void findsubsets(int idx, vector<int>& nums, vector<int> temp) {
        if (idx >= nums.size()) {
            ans.push_back(temp);  
            return;
        }

        temp.push_back(nums[idx]);
        findsubsets(idx + 1, nums, temp);

        temp.pop_back();
        findsubsets(idx + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        findsubsets(0, nums, temp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets are:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
