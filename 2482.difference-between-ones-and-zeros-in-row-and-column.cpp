/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<int> oner(r, 0), onec(c, 0), zeror(r, 0), zeroc(c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int ele = grid[i][j];
                if (ele == 0)
                {
                    zeroc[j]++;
                    zeror[i]++;
                }
                else
                {
                    oner[i]++;
                    onec[j]++;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                grid[i][j] = oner[i] + onec[j] - zeroc[j] - zeror[i];
            }
        }
        return grid;
    }
};
// @lc code=end
