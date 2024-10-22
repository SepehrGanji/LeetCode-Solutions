/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<pair<int, Node*>> qu;
        qu.push(make_pair(0, root));
        while(!qu.empty()) {
            auto full_el = qu.front(); qu.pop();
            int level = full_el.first;
            Node* el = full_el.second; 
            if(el == NULL) continue;
            while(ans.size() < level+1) ans.push_back({});
            ans[level].push_back(el->val);
            for(auto ch: el->children) {
                qu.push(make_pair(level+1, ch));
            }
        }
        return ans;
    }
};
