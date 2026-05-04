#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    char* word;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx]) curr->children[idx] = createNode();
        curr = curr->children[idx];
    }
    curr->word = word; // Store the full word at the end node
}

void backtrack(char** board, int r, int c, int rs, int cs, TrieNode* node, char** res, int* returnSize) {
    char ch = board[r][c];
    int idx = ch - 'a';
    if (ch == '#' || !node->children[idx]) return;

    node = node->children[idx];
    if (node->word) {
        res[(*returnSize)++] = strdup(node->word);
        node->word = NULL; // Avoid duplicates
    }

    board[r][c] = '#'; // Mark as visited
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < rs && nc >= 0 && nc < cs)
            backtrack(board, nr, nc, rs, cs, node, res, returnSize);
    }
    board[r][c] = ch; // Restore
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) insert(root, words[i]);

    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            backtrack(board, i, j, boardSize, boardColSize[i], root, res, returnSize);
        }
    }
    return res;
}
