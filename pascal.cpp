int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    // Allocate array of pointers (one for each row)
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    // Allocate array to store the size of each row
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // Row 'i' has 'i + 1' elements
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        // First and last elements of every row are always 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Fill in the middle elements
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

