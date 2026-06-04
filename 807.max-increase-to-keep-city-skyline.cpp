/*
 * @lc app=leetcode id=807 lang=cpp
 *
 * [807] Max Increase to Keep City Skyline
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<int> row(r,INT_MIN),col(c,INT_MIN);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int ele=grid[i][j];
                int a=min(row[i],col[j]);
                if(a-ele>0) ans+= (a-ele);
            }
        }
        return ans;
    }
};
// @lc code=end

