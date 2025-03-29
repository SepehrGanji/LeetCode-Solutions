/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int i, int j, int n) {
        int onecnt = 0, zercnt = 0;
        for(int ii = i ; ii < i+n ; ii++)
            for(int jj = j ; jj < j+n ; jj++)
                if(grid[ii][jj] == 0) zercnt++;
                else onecnt++;
        if(onecnt == 0) {
            Node* root = new Node(0, true);
            return root;
        }
        if(zercnt == 0) {
            Node* root = new Node(1, true);
            return root;
        }
        Node* tL = helper(grid, i, j, n/2);
        Node* tR = helper(grid, i, j+n/2, n/2);
        Node* dL = helper(grid, i+n/2, j, n/2);
        Node* dR = helper(grid, i+n/2, j+n/2, n/2);
        Node* root = new Node(0, false, tL, tR, dL, dR);
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid[0].size());
    }
};
