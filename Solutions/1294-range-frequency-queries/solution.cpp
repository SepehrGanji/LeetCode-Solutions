class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    map<tuple<int, int, int>, int> cache;

    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0 ; i < arr.size() ; i++) {
            int el = arr[i];
            mp[el].push_back(i);
        }    
    }
    
    int lfind(int el, vector<int>& arr) {
        // first idx that is greater or eq
        int l = 0, r = arr.size();
        if(arr[r-1] < el) return r;
        while(l < r) {
            int mid = (l+r)/2;
            if(arr[mid] >= el) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    int rfind(int el, vector<int>& arr) {
        // last idx that is less than or eq
        int l = 0, r = arr.size();
        if(arr[0] > el) return -1;
        while(l < r) {
            int mid = (l+r)/2;
            if(arr[mid] <= el) l = mid+1;
            else r = mid;
        }
        return l-1;
    }

    int query(int left, int right, int value) {
        if(mp.find(value) == mp.end()) return 0;
        if(cache.find({left, right, value}) != cache.end()) return cache[{left, right, value}];
        auto arr = mp[value];
        int l = lfind(left, arr);
        int r = rfind(right, arr);
        int ans = r-l+1;
        cache[{left, right, value}] = ans;
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
