class SnapshotArray {
public:
    unordered_map<int, vector<pair<uint16_t, uint32_t>>> vec;
    uint16_t cur = 0;
    
    SnapshotArray(int length) {}
    
    int snap() {
        return cur++;
    }
    
    int find(int i, int sn) {
        if (vec.find(i) == vec.end()) return -1;
        
        const auto& arr = vec[i];
        int l = 0, r = arr.size();
        while(l < r) {
            int mid = (l+r)/2;
            if(arr[mid].first <= sn) l = mid+1;
            else r = mid;
        }
        return l-1;
    }
    
    void set(int index, int val) {
        if (vec.find(index) == vec.end()) {
            vec[index].emplace_back(cur, val);
            return;
        }
        
        int idx = find(index, cur);
        if(idx >= 0 && vec[index][idx].first == cur) {
            vec[index][idx].second = val;
            return;
        }
        vec[index].emplace_back(cur, val);
    }
    
    int get(int index, int snap_id) {
        int idx = find(index, snap_id);
        if (idx == -1) return 0;  // Default value for unset indices
        return vec[index][idx].second;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
