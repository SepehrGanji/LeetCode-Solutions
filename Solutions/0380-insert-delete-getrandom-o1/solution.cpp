class RandomizedSet {
private:
    set<int> st;
    
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()) return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end()) return false;
        st.erase(st.find(val));
        return true;
    }
    
    int getRandom() {
        int n = st.size();
        int idx = rand() % n;
        auto it = st.begin();
        advance(it, idx);
        return *(it);
    }
};
