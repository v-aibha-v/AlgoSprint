/*
 * @lc app=leetcode id=3761 lang=cpp
 *
 * [3761] Minimum Absolute Distance Between Mirror Pairs
 */

// @lc code=start
class Solution {
public:
    int reverse(int num) {
        int temp=0;
        while (num > 0) {
            temp = temp * 10 + (num % 10);
            num /= 10;
        }
        return temp;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int temp = reverse(nums[i]);
            if (mp.find(nums[i]) != mp.end()) {
                mini = min(mini, i - mp[nums[i]]);
            }
            mp[temp] = i;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
// @lc code=end

