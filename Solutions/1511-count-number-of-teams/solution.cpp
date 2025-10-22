const int n = 100005;

class SegTree{
private:
    vector<int> tree;
public:
    SegTree() {
        tree.resize(n * 4);
    }
    void build(vector<int>& arr, int treeIdx, int lo, int hi) {
        if(lo == hi) {
            tree[treeIdx] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(arr, 2*treeIdx+1, lo, mid);
        build(arr, 2*treeIdx+2, mid+1, hi);
        tree[treeIdx] = tree[2*treeIdx+1] + tree[2*treeIdx+2];
    }

    int query(int treeIndex, int lo, int hi, int i, int j) {
        if (lo > j || hi < i)
            return 0; 

        if (i <= lo && j >= hi)
            return tree[treeIndex];

        int mid = (lo + hi) / 2;
        return query(2 * treeIndex + 1, lo, mid, i, j) + query(2 * treeIndex + 2, mid+1, hi, i, j);
    }

    void update(int treeIndex, int lo, int hi, int arrIndex, int val) {
        if(lo == hi) {
            tree[treeIndex] = val;
            return;
        }

        int mid = (lo+hi)/2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;
        if (arrIndex <= mid) {
            update(leftChild, lo, mid, arrIndex, val);
        } else {
            update(rightChild, mid + 1, hi, arrIndex, val);
        }
        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> arr(n+1, 0);
        for(auto el: rating) arr[el]++;
        SegTree tr;
        tr.build(arr, 0, 0, n);
        int ans = 0;
        int en = rating.size();
        for(int x = 0 ; x < en ; x++) {
            tr.update(0, 0, n, rating[x], 0);
            //forward pass on y
            for(int y = x + 1 ; y < en ; y++) {
                tr.update(0, 0, n, rating[y], 0);
                if(rating[x] < rating[y]) ans += tr.query(0, 0, n, rating[y], n);
                else ans += tr.query(0, 0, n, 0, rating[y]);
            }
            //backward pass on y
            for(int y = en-1 ; y >= x+1 ; y--) tr.update(0, 0, n, rating[y], 1);
        }
        return ans;
    }
};
