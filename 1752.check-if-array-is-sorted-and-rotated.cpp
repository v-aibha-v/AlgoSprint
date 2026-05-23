/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size(), idx = 0;
        if (nums[0] >= nums[n - 1])
        {
            while (idx + 1 < n and nums[idx + 1] >= nums[idx])
                idx++;
            idx++;
            while (idx + 1 < n and nums[idx + 1] >= nums[idx])
                idx++;
            return idx >= n - 1;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
