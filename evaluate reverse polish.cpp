#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int evalRPN(char** tokens, int tokensSize) {
    // The maximum size of the stack will never exceed tokensSize
    int* stack = (int*)malloc(sizeof(int) * tokensSize);
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* s = tokens[i];

        // Check if the token is an operator (+, -, *, /)
        // Note: s[1] check handles negative numbers like "-11"
        if ((s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') && s[1] == '\0') {
            int val2 = stack[top--]; // Second operand
            int val1 = stack[top--]; // First operand

            switch (s[0]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        } else {
            // Token is a number; convert string to integer and push
            stack[++top] = atoi(s);
        }
    }

    int result = stack[top];
    free(stack);
    return result;
}
