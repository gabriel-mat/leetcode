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
        if(node == nullptr) return nullptr;

        unordered_map<int, Node *> seen;
        return cloneGraph(node, seen);
    }

    Node *cloneGraph(Node *node, unordered_map<int, Node*> &seen){
        Node *clone = new Node(node->val);
        seen[node->val] = clone;

        for(Node *neighbor : node->neighbors)
            if(seen.count(neighbor->val))
                clone->neighbors.push_back(seen[neighbor->val]);
            else
                clone->neighbors.push_back(cloneGraph(neighbor, seen));

        return clone;
    }
};

/*
 *  Na próxima solução, uso uma InPlace transformation
 * uso as referências do nó original para a clonagem.
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<int, Node*> seen;
        return solve(node, seen);
    }

    Node* solve(Node* node, unordered_map<int, Node*> &seen) {
        Node* clone = new Node(node->val, node->neighbors);
        seen[node->val] = clone;

        for (Node* &neighbor : clone->neighbors)
            if (seen.count(neighbor->val))
                neighbor = seen[neighbor->val];
            else
                neighbor = solve(neighbor, seen);

        return clone;
    }
};
