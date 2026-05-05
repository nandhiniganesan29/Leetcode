#include <string.h>

int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    int n1 = strlen(version1);
    int n2 = strlen(version2);

    while (i < n1 || j < n2) {
        long num1 = 0, num2 = 0;

        // Parse revision from version1
        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        // Parse revision from version2
        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        // Compare the current revisions
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;

        // Skip the dots
        i++;
        j++;
    }

    return 0;
}
