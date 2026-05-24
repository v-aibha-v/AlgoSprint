/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<int> &arr, int d, int n, int idx, vector<int> &visited, vector<int> &memo)
    {
        if (idx >= n or idx < 0)
            return 0;
        if (memo[idx] != -1)
            return memo[idx];
        int maxi = 0;
        for (int i = 1; i <= d; i++)
        {
            int ni = i + idx;
            if (ni >= n or arr[ni] >= arr[idx])
                break;
            if (arr[ni] < arr[idx] and visited[ni] == -1)
            {
                visited[ni] = 0;
                int val = 1 + dfs(arr, d, n, ni, visited, memo);
                maxi = max(maxi, val);
                visited[ni] = -1;
            }
        }
        for (int i = 1; i <= d; i++)
        {
            int ni = idx - i;
            if (ni < 0 or arr[ni] >= arr[idx])
                break;
            if (arr[ni] < arr[idx] and visited[ni] == -1)
            {
                visited[ni] = 0;
                int val = 1 + dfs(arr, d, n, ni, visited, memo);
                maxi = max(maxi, val);
                visited[ni] = -1;
            }
        }
        return memo[idx] = maxi;
    }
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size();
        vector<int> visited(n, -1);
        int maxi = 0;
        vector<int> memo(n, -1);
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, dfs(arr, d, n, i, visited, memo));
        }
        return maxi + 1;
    }
};
// @lc code=end
