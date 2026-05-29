/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;for(int ele: nums){int sum=0,temp=ele;while(temp>0){sum+=(temp%10);temp/=10;} if(sum<mini)mini=sum;}return mini;
    }
};
// @lc code=end

