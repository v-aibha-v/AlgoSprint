/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),maxi=0,t=0,start=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) t++;
            while(start<=i and t>k) {
                if(nums[start]==0) t--;
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};
// @lc code=end

