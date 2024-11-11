class Solution {
public:
    vector<int> sz;
    int height = 0;

    void updateHeight(TreeNode* root, int curr) {
        if(root == nullptr) return;
        height = max(height, curr);
        updateHeight(root->left, curr+1);
        updateHeight(root->right, curr+1);
    }

    pair<int, bool> sizeOff(TreeNode* root, int level) {
        if(root == nullptr) return {0, false};
        auto lsize = sizeOff(root->left, level-1);
        auto rsize = sizeOff(root->right, level-1);
        int my_size = 1 + lsize.first + rsize.first;
        if(root->left == nullptr && root->right == nullptr) {
            // leaf!
            sz.push_back(my_size);
            return {1, true};
        }
        
        if(lsize.first == rsize.first && lsize.second && rsize.second) {
            int lg = log2(my_size+1);
            if(pow(2, lg) == my_size+1) {
                sz.push_back(my_size);
                return {my_size, true};
            }
        }
        return {0, false};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        updateHeight(root, 1);
        sizeOff(root, height);
        sort(sz.begin(), sz.end());
        for(auto el: sz) cout << el << ' ';
        cout << endl;
        int n = sz.size();
        if(n-k >= 0) {
            return sz[n-k];
        }
        return -1;
    }

};
