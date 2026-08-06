/*
 * @lc app=leetcode id=3310 lang=cpp
 *
 * [3310] Remove Methods From Project
 */

// @lc code=start
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Mark all suspicious methods
        vector<int> vis(n, 0);
        queue<int> q;

        q.push(k);
        vis[k] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        // Check whether any outside method invokes a suspicious method
        for (int u = 0; u < n; u++) {
            if (vis[u]) continue;

            for (int v : adj[u]) {
                if (vis[v]) {
                    // Suspicious group cannot be removed
                    vector<int> ans;
                    for (int i = 0; i < n; i++)
                        ans.push_back(i);

                    return ans;
                }
            }
        }

        // No outside method invokes suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};
// @lc code=end

