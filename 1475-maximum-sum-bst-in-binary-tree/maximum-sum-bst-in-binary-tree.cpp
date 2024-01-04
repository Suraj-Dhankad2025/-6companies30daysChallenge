/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Tree{
        bool isBST;
        int max;
        int min;
        int sum;
        Tree(bool a, int b, int c, int d){
            isBST = a;
            max = b;
            min = c;
            sum = d;
        }
    };
    Tree* find(TreeNode* root, int &ans){
        if(root==NULL){
            return new Tree(1, INT_MIN, INT_MAX, 0);
        }
        Tree* left = find(root->left, ans);
        Tree* right = find(root->right, ans);

        bool bst = left->isBST && right->isBST && root->val>left->max && root->val<right->min;
        int sum = left->sum + right->sum + root->val;
        if(bst){
            ans = max(ans, sum);
        }
        int newMin = min(root->val, min(left->min, right->min));
        int newMax = max(root->val, max(left->max, right->max));
        return new Tree(bst, newMax, newMin, sum);
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        find(root, ans);
        return ans;
    }
};