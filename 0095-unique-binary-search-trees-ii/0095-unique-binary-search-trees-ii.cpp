class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> trees;

        
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        
        for (int rootValue = start; rootValue <= end; rootValue++) {

            
            vector<TreeNode*> leftTrees =
                build(start, rootValue - 1);

            
            vector<TreeNode*> rightTrees =
                build(rootValue + 1, end);

            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(rootValue);

                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};