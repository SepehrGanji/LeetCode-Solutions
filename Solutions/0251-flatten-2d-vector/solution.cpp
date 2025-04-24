class Vector2D {
public:
    vector<vector<int>>* arr;
    int i = 0, j = 0;
    
    Vector2D(vector<vector<int>>& vec) {
        arr = &vec;
    }
    
    int next() {
        goton();
        vector<vector<int>> vec = *arr;
        return vec[i][j++];
    }
    
    bool hasNext() {
        vector<vector<int>> vec = *arr;
        goton();
        return i < vec.size();
    }

    void goton() {
        vector<vector<int>> vec = *arr;
        while(i < vec.size() && j == vec[i].size()) {
            j = 0;
            i++;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
