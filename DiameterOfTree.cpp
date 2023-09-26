class Solution {
    private:
     int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }

        int lh=height(root->left);
        int rh=height(root->right);
        int ans=max(lh,rh)+1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int lh=diameterOfBinaryTree(root->left);
        int rh=diameterOfBinaryTree(root->right);

        int ht=height(root->left)+height(root->right);

        int ans=max(ht,max(lh,rh));

        return ans;
        
    }
};
