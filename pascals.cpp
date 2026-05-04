/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));
    
    // Initialize the first element
    row[0] = 1;
    
    // Build the row using the property: 
    // row[j] = prev_row[j-1] + prev_row[j]
    for (int i = 1; i <= rowIndex; i++) {
        row[i] = 0; // Initialize new element
        for (int j = i; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
}
