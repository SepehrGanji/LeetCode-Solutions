class NumArray {
public:
    vector<int> tree; int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        buildTree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
    
    void buildTree(vector<int> &nums, int treeIdx, int l, int r) {
        if(l == r) {
            tree[treeIdx] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        int left_child = 2 * treeIdx + 1;
        int right_child = 2 * treeIdx + 2;
        
        buildTree(nums, left_child, l, mid);
        buildTree(nums, right_child, mid+1, r);
        
        tree[treeIdx] = tree[left_child] + tree[right_child];
    }
    
    int queryTree(int treeIndex, int low, int high, int i, int j) {
        if(low > j || high < i) return 0;
        if(low >= i && high <= j) return tree[treeIndex];
        
        int mid = (low + high) / 2;
        int left_child = 2 * treeIndex + 1;
        int right_child = 2 * treeIndex + 2;
        
        return queryTree(left_child, low, mid, i, j) + queryTree(right_child, mid+1, high, i, j);
    }
    
    void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if(lo == hi) {
            tree[treeIndex] = val;
            return;
        }
        
        int mid = lo + (hi - lo) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;
        if (arrIndex <= mid) {
            // Update left subtree
            updateTree(leftChild, lo, mid, arrIndex, val);
        } else {
            // Update right subtree
            updateTree(rightChild, mid + 1, hi, arrIndex, val);
        }
        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
