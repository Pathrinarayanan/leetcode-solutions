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
    int parentA , parentB;
    int levelA , levelB;
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        cousin(root, x, y , 0,0);
        if(parentA != parentB && levelA == levelB){
            return true;
        }
        return false;
        
    }
    void cousin(TreeNode * root, int x , int y , int level , int temp){
            if(root== NULL)
                return ;
        if(root->val == x){
            parentA = temp;
            levelA = level;
        }
        if(root->val == y){
            parentB = temp;
            levelB   = level;
        }
        cousin(root->left, x, y , level+1, root->val);
        cousin(root->right, x , y , level+1, root->val);
        return;
    }
};