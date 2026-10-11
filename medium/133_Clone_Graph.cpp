/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;
        
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (auto other: cur->neighbors) {
                if (oldToNew.find(other) == oldToNew.end()) {
                    oldToNew[other] = new Node(other->val);
                    q.push(other);
                }
                oldToNew[cur]->neighbors.push_back(oldToNew[other]);
            }
        }

        return oldToNew[node];
    }
};