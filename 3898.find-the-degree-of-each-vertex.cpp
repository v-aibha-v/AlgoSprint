/*
 * @lc app=leetcode id=3898 lang=cpp
 *
 * [3898] Find the Degree of Each Vertex
 */

// @lc code=start
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int ele: matrix[i]){
                if(ele==1) ans[i]++;
            }
        }
        return ans;
    }
};
// @lc code=end

