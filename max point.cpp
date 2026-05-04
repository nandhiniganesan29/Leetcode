#include <math.h>
#include <stdio.h>

// Helper to find Greatest Common Divisor to normalize slopes
int gcd(int a, int b) {
    while (b) {
        a %= b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) return pointsSize;

    int globalMax = 0;

    for (int i = 0; i < pointsSize; i++) {
        // For each point, we find how many other points share the same slope
        // In C, since we don't have a HashMap easily, we can use a simple array 
        // or re-scan, but for LeetCode constraints, a nested loop is fine.
        for (int j = i + 1; j < pointsSize; j++) {
            int count = 2; // Point i and Point j
            long dx = (long)points[j][0] - points[i][0];
            long dy = (long)points[j][1] - points[i][1];

            for (int k = 0; k < pointsSize; k++) {
                if (k == i || k == j) continue;
                
                long dxk = (long)points[k][0] - points[i][0];
                long dyk = (long)points[k][1] - points[i][1];

                // Check if (dy/dx) == (dyk/dxk) using cross-multiplication 
                // to avoid floating point precision issues: dy * dxk == dyk * dx
                if (dy * dxk == dyk * dx) {
                    count++;
                }
            }
            if (count > globalMax) globalMax = count;
        }
    }

    return globalMax == 0 ? pointsSize : globalMax;
}
