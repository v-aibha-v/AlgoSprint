/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_map<int, vector<int>> low, up;
        int n = word.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] >= 'a' and word[i] <= 'z')
                low[word[i] - 'a'].push_back(i);
            else
                up[word[i] - 'A'].push_back(i);
        }
        for (auto x : up)
        {
            if (low.find(x.first) != low.end())
            {
                // bool valid=true;
                // for(auto y:low[x.first]){
                //     if(y<x.second[0]) {ans++;break;}
                // }
                vector<int> t = low[x.first];
                if (t[t.size() - 1] < x.second[0])
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
