/*
 * @lc app=leetcode id=3691 lang=cpp
 *
 * [3691] Maximum Total Subarray Value II
 */

// @lc code=start
class Solution {
public:
    using ll = long long;

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        // Compute maximum log value needed
        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        // Sparse tables for range max and range min
        vector<vector<int>> mx(LOG, vector<int>(n));
        vector<vector<int>> mn(LOG, vector<int>(n));

        // Base level stores original array
        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        // Build sparse tables
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {

                mx[j][i] = max(
                    mx[j - 1][i],
                    mx[j - 1][i + (1 << (j - 1))]
                );

                mn[j][i] = min(
                    mn[j - 1][i],
                    mn[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        // Returns max-min for any subarray in O(1)
        auto value = [&](int l, int r) -> ll {

            int len = r - l + 1;
            int j = 31 - __builtin_clz(len);

            int maximum = max(
                mx[j][l],
                mx[j][r - (1 << j) + 1]
            );

            int minimum = min(
                mn[j][l],
                mn[j][r - (1 << j) + 1]
            );

            return (ll)maximum - minimum;
        };

        // {value, left, right}
        using T = tuple<ll, int, int>;
        priority_queue<T> pq;

        // Start with the largest subarray for every left index
        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        ll ans = 0;

        // Pick the best k subarrays
        while (k--) {

            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            // Try the next shorter subarray with same left endpoint
            if (r > l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};
// @lc code=end
