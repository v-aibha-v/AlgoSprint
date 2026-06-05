/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<int> ans;
        int sr=0,er=r-1,sc=0,ec=c-1;
        // cout
        while(sr<=er and sc<=ec){
            for(int i=sc;i<=ec;i++) {ans.push_back(matrix[sr][i]);cout<<ans.back();cout<<" ";}
            sr+=1;
            for(int i=sr;i<=er;i++) {ans.push_back(matrix[i][ec]);cout<<ans.back();cout<<" ";}
            ec-=1;
           if(sr<=er and sc<=ec)
            {for(int i=ec;i>=sc;i--) {ans.push_back(matrix[er][i]);cout<<ans.back();cout<<" ";}
            er-=1;
            for(int i=er;i>=sr;i--) {ans.push_back(matrix[i][sc]);cout<<ans.back();cout<<" ";}
            sc+=1;}
        }   
        return ans;
    }
};
// @lc code=end

