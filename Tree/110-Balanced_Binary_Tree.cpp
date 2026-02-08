class Solution {
public:
    int maxheight(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1+max(maxheight(root->left), maxheight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if((abs(maxheight(root->left)-maxheight(root->right))<=1)&&(isBalanced(root->left) && isBalanced(root->right))) return true;
        return false;
    }
};