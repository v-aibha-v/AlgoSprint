/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size(), start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[start] and nums[mid] > nums[end])
            {
                // upper phase
                if (nums[mid] < target)
                    start = mid + 1;
                else
                {
                    if (nums[start] > target)
                        start = mid + 1; // not >=
                    else
                        end = mid - 1; // tsrget >=start
                }
            }
            else
            {
                if (nums[mid] > target)
                    end = mid - 1;
                else
                {
                    if (nums[end] < target)
                        end = mid - 1;
                    else
                        start = 1 + mid;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
