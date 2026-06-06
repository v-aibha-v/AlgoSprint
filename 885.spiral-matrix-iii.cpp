/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
public:
    int totalr, totalc;
    bool valid(int a,int b){
        if(a>=0 and a<totalr and b>=0 and b<totalc) return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int tr, int tc, int rs, int cs) {
        int count=tr*tc,t=1;
        totalr=tr,totalc=tc;
        vector<vector<int>> ans;
        ans.push_back({rs,cs});count--;
        while(count!=0){
            for(int i=0;i<t and count!=0;i++){
                cs+=1;
                if(valid(rs,cs)) {ans.push_back({rs,cs});count--;}
            }
            for(int i=0;i<t and count!=0;i++){
                rs+=1;
                if(valid(rs,cs))  {ans.push_back({rs,cs});count--;}
            }
            t++;
            for(int i=0;i<t and count!=0;i++){
                cs-=1;
                if(valid(rs,cs)) {ans.push_back({rs,cs});count--;}
            }
            for(int i=0;i<t and count!=0;i++){
                rs-=1;
                if(valid(rs,cs))  {ans.push_back({rs,cs});count--;}
            }
            t++;
        }
        return ans;
    }
};
// @lc code=end

