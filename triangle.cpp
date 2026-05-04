int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // Start from the second-to-last row
    for (int i = triangleSize - 2; i >= 0; i--) {
        // Iterate through each element in the current row
        for (int j = 0; j <= i; j++) {
            // Find the smaller of the two adjacent children in the row below
            int leftChild = triangle[i + 1][j];
            int rightChild = triangle[i + 1][j + 1];
            
            // Add the smaller child to the current element
            if (leftChild < rightChild) {
                triangle[i][j] += leftChild;
            } else {
                triangle[i][j] += rightChild;
            }
        }
    }

    // The top element now contains the minimum path sum
    return triangle[0][0];
}
