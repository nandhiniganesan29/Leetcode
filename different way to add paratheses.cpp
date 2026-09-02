class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' ||
                expression[i] == '-' ||
                expression[i] == '*') {

                vector<int> left =
                    diffWaysToCompute(expression.substr(0, i));

                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (expression[i] == '+')
                            ans.push_back(a + b);
                        else if (expression[i] == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, it is a number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};
