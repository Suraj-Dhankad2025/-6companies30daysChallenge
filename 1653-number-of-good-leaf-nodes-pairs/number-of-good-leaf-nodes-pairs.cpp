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
    int ans=0;
    vector<int> find(TreeNode* root, int dis){
        if(root->left==NULL && root->right==NULL){
            return {};
        }
        vector<int>l;
        vector<int>r;
        if(root->left){
            l = find(root->left, dis);
            if(l.size()==0){
                l.push_back(1);
            }
        }
        if(root->right){
            r = find(root->right, dis);
            if(r.size()==0){
                r.push_back(1);
            }
        }
        for(int i=0; i<l.size(); i++){
            for(int j=0; j<r.size(); j++){
                if(l[i]+r[j]<=dis){
                    ans++;
                }
            }
        }
        for(int i=0; i<l.size(); i++){
            l[i]+=1;
        }
        for(int i=0; i<r.size(); i++){
            r[i]+=1;
            l.push_back(r[i]);
        }
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        find(root,distance);
        return ans;
    }
};