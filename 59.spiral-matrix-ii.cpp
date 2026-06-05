/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr=0,er=n-1,sc=0,ec=n-1,var=1;
        vector<vector<int>> matrix(n,vector<int>(n,0));
         while(sr<=er and sc<=ec){
            for(int i=sc;i<=ec;i++) {matrix[sr][i]=var;var+=1;}
            sr+=1;
            for(int i=sr;i<=er;i++) {matrix[i][ec]=var;var+=1;}
            ec-=1;
           if(sr<=er and sc<=ec)
            {for(int i=ec;i>=sc;i--) {matrix[er][i]=var;var+=1;}
            er-=1;
            for(int i=er;i>=sr;i--) {matrix[i][sc]=var;var+=1;}
            sc+=1;}
        }   
        return matrix;
    }
};
// @lc code=end

