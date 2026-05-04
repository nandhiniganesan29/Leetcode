#include <stdlib.h>
#include <string.h>

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

// A simple lookup table to store pointers to cloned nodes.
// Node values are typically between 1 and 100 per LeetCode constraints.
struct Node* visited[101];

struct Node* dfs(struct Node* node) {
    if (node == NULL) return NULL;

    // 1. If we have already cloned this node, return the clone
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    // 2. Create the new node (the clone)
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    
    // Store it in our visited map immediately to handle cycles
    visited[node->val] = clone;

    // 3. Clone the neighbors
    if (node->numNeighbors > 0) {
        clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
        for (int i = 0; i < node->numNeighbors; i++) {
            clone->neighbors[i] = dfs(node->neighbors[i]);
        }
    } else {
        clone->neighbors = NULL;
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) return NULL;

    // Initialize visited map to NULL for each call
    for (int i = 0; i < 101; i++) {
        visited[i] = NULL;
    }

    return dfs(s);
}
