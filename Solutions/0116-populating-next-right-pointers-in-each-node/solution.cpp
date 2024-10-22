/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> qu;
        qu.push(make_pair(root, 0));
        while(!qu.empty()) {
            auto curr = qu.front(); qu.pop();
            Node* curr_node = curr.first; 
            int curr_level = curr.second;
            if(curr_node != NULL) {
                if(!qu.empty() && qu.front().second == curr_level) {
                    curr_node->next = qu.front().first;
                }
                qu.push(make_pair(curr_node->left, curr_level+1));
                qu.push(make_pair(curr_node->right, curr_level+1));
                // qu.push(curr_node->right);
            }
        }
        
        return root;
    }
};
