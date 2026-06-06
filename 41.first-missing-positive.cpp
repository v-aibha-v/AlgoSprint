/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool presentone=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1) presentone=true;
            else if(nums[i]<=0 or nums[i]>n) nums[i]=1;
        }
        if(presentone==false) return 1;
        for(int i=0;i<n;i++){
            int idx= abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]= nums[idx]*-1; 
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};
// @lc code=end

