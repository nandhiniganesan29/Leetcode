int calculate(char* s) {
    int result = 0;
    int current = 0;
    int last = 0;
    char op = '+';

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] >= '0' && s[i] <= '9') {
            current = current * 10 + (s[i] - '0');
        }

        if ((s[i] < '0' || s[i] > '9') && s[i] != ' ') {
            
            if (op == '+') {
                result += last;
                last = current;
            }
            else if (op == '-') {
                result += last;
                last = -current;
            }
            else if (op == '*') {
                last = last * current;
            }
            else if (op == '/') {
                last = last / current;
            }

            op = s[i];
            current = 0;
        }
    }

    // Process the last number
    if (op == '+') {
        result += last;
        last = current;
    }
    else if (op == '-') {
        result += last;
        last = -current;
    }
    else if (op == '*') {
        last = last * current;
    }
    else if (op == '/') {
        last = last / current;
    }

    result += last;

    return result;
}
