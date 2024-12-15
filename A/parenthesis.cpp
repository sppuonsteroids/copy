#include <iostream>
#include <stack>
using namespace std;

// Function to check if the expression is well-parenthesized
bool isWellParenthesized(string expression) {
    stack<char> s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch); // Push opening brackets
        } 
        else if (ch == ')' || ch == '}' || ch == ']') { //for closing brackets check if stack is empty or not
            if (s.empty()) return false; // No matching opening bracket if stack is empty
            if ((ch == ')' && s.top() != '(') ||   //this is for if stack is not empty
                (ch == '}' && s.top() != '{') ||
                (ch == ']' && s.top() != '[')) {
                return false; // Mismatched bracket
            }
            s.pop(); // Remove matching opening bracket
        }
    }
    return s.empty(); // Check if all brackets are matched
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
