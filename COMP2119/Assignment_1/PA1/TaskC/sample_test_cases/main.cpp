#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int calculateExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;

    for (int i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                if (op == '+') values.push(a + b);
                else if (op == '-') values.push(a - b);
                else if (op == '*') values.push(a * b);
                else if (op == '/') values.push(a / b);
                else if (op == '^') values.push(static_cast<int>(pow(a, b)));
            }
            operators.pop();
        } else if (expression[i] == '+' || expression[i] == '-') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                if (op == '+') values.push(a + b);
                else if (op == '-') values.push(a - b);
            }
            operators.push(expression[i]);
        } else if (expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && operators.top() != '(' &&
                (operators.top() == '*' || operators.top() == '/')) {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                if (op == '*') values.push(a * b);
                else if (op == '/') values.push(a / b);
            }
            operators.push(expression[i]);
        } else if (expression[i] == '^' || expression[i] == '!') {
            while (!operators.empty() && operators.top() != '(' &&
                ((expression[i] == '^' && operators.top() == '^') ||
                (expression[i] == '!' && operators.top() == '!'))) {
                char op = operators.top();
                operators.pop();
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                if (op == '^') values.push(static_cast<int>(pow(a, b)));
                else if (op == '!') values.push(factorial(a));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        if (op == '+') values.push(a + b);
        else if (op == '-') values.push(a - b);
        else if (op == '*') values.push(a * b);
        else if (op == '/') values.push(a / b);
        else if (op == '^') values.push(static_cast<int>(pow(a, b)));
        else if (op == '!') values.push(factorial(a));
    }

    return values.top();
}

int main() {
    string expression;
    getline(cin, expression);

    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());

    int result = calculateExpression(expression);
    cout <<result;

    return 0;
}
