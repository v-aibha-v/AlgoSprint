/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 */

// @lc code=start
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size(),count=0;vector<int> ans;
        for(int i=0;i<n;++i){
            if(nums[i]<pivot) ans.push_back(nums[i]);
            else if(nums[i]==pivot) count++;
        }
        for(int i=0;i<count;++i) ans.push_back(pivot);
        for(int i=0;i<n;++i){
            if(nums[i]>pivot) ans.push_back(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

