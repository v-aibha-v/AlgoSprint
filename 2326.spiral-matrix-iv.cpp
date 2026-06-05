/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int sr = 0, er = m - 1, sc = 0, ec = n - 1;
        ListNode *temp = head;
        while (temp != nullptr and sr <= er and sc <= ec)
        {
            for (int i = sc; i <= ec and temp; i++)
            {
                matrix[sr][i] = temp->val;
                temp = temp->next;
            }
            sr++;
            for (int i = sr; i <= er and temp; i++)
            {
                matrix[i][ec] = temp->val;
                temp = temp->next;
            }
            ec--;
            if (sr <= er and sc <= ec)
            {
                for (int i = ec; i >= sc and temp; i--)
                {
                    matrix[er][i] = temp->val;
                    temp = temp->next;
                }
                er--;
                for (int i = er; i >= sr and temp; i--)
                {
                    matrix[i][sc] = temp->val;
                    temp = temp->next;
                }
                sc++;
            }
        }
        return matrix;
    }
};

// @lc code=end
