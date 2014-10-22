/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        return cloneGraph(node, map);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &map) {
        if (map.find(node) != map.end()) return map[node];
        else if (node == NULL) return NULL;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        map[node] = newNode;
        for (UndirectedGraphNode *neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor, map));
        }
        return newNode;
    }
};