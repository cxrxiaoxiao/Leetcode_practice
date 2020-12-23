#pragma once
#include<vector>
#include<queue>
#include<deque>
#include<iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
}; 
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool isleft = true;

        while (!q.empty()) {
            deque<int> level;
            for (int i = 0; i < q.size(); i++) {
                auto node = q.front();
                q.pop();
                if (isleft) {
                    level.push_back(node->val);
                }
                else
                {
                    level.push_front(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(vector<int>{level.begin(), level.end()});
            isleft = !isleft;
        }
        return ans;
    }
};