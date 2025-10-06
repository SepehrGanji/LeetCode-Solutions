class NumArray {
private:
    vector<int> tree;
    int n;

    void buildtree(vector<int>& nums, int treeIdx, int lo, int hi) {
        if(lo == hi) {
            tree[treeIdx] = nums[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        buildtree(nums, 2*treeIdx+1, lo, mid);
        buildtree(nums, 2*treeIdx+2, mid+1, hi);
        tree[treeIdx] = tree[2*treeIdx+1] + tree[2*treeIdx+2];
    }

    int querytree(int treeIndex, int lo, int hi, int i, int j) {
        if (lo > j || hi < i)
            return 0; 

        if (i <= lo && j >= hi)
            return tree[treeIndex];

        int mid = (lo + hi) / 2;
        return querytree(2 * treeIndex + 1, lo, mid, i, j) + querytree(2 * treeIndex + 2, mid+1, hi, i, j);
    }

    void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if(lo == hi) {
            tree[treeIndex] = val;
            return;
        }
        
        int mid = (lo+hi)/2;
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

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n * 4);
        buildtree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return querytree(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
