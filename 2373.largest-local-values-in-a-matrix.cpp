/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    int maxi(vector<vector<int>>& grid , int n , int row, int col){
        int max_ele=INT_MIN;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                max_ele=max(max_ele,grid[i][j]);
            }
        }
        return max_ele;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                ans[i][j]=maxi(grid,n,i,j);
            }
        }
        return ans;
    }
};
// @lc code=end

