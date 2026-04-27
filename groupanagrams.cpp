#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper to sort characters in a string (the key for our anagram groups)
 */
int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

/**
 * Structure to keep track of original strings and their sorted versions
 */
typedef struct {
    char* original;
    char* sorted;
} Word;

int compareWords(const void* a, const void* b) {
    return strcmp(((Word*)a)->sorted, ((Word*)b)->sorted);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    Word* words = (Word*)malloc(strsSize * sizeof(Word));
    for (int i = 0; i < strsSize; i++) {
        words[i].original = strs[i];
        words[i].sorted = strdup(strs[i]);
        qsort(words[i].sorted, strlen(words[i].sorted), sizeof(char), compareChars);
    }

    // Sort the words array based on the 'sorted' strings
    qsort(words, strsSize, sizeof(Word), compareWords);

    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    int groupCount = 0;

    int i = 0;
    while (i < strsSize) {
        int j = i;
        // Find the range of strings that have the same sorted key
        while (j < strsSize && strcmp(words[i].sorted, words[j].sorted) == 0) {
            j++;
        }

        int currentGroupSize = j - i;
        result[groupCount] = (char**)malloc(currentGroupSize * sizeof(char*));
        for (int k = 0; k < currentGroupSize; k++) {
            result[groupCount][k] = words[i + k].original;
        }

        (*returnColumnSizes)[groupCount] = currentGroupSize;
        groupCount++;
        i = j; // Move to the next unique sorted key
    }

    // Clean up temporary sorted strings
    for (int k = 0; k < strsSize; k++) free(words[k].sorted);
    free(words);

    *returnSize = groupCount;
    return result;
}
