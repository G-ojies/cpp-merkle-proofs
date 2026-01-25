#include <iostream>
#include <vector>
#include <string>
#include <stack>

class ScriptDebugger {
private:
    std::stack<int> stack;

public:
    void execute(std::string op) {
        if (op == "OP_ADD") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(a + b);
            std::cout << "Executed OP_ADD: " << a << " + " << b << " = " << (a + b) << "\n";
        } else if (op == "OP_DUP") {
            stack.push(stack.top());
            std::cout << "Executed OP_DUP: Duplicated " << stack.top() << "\n";
        } else if (op == "OP_EQUAL") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(a == b);
            std::cout << "Executed OP_EQUAL: " << a << " == " << b << " is " << (a == b) << "\n";
        } else {
            // If it's not an opcode, assume it's a number (data)
            stack.push(std::stoi(op));
            std::cout << "Pushed Data: " << op << "\n";
        }
    }

    void printStack() {
        std::cout << "Current Stack (Top to Bottom): ";
        std::stack<int> temp = stack;
        while (!temp.empty()) {
            std::cout << "[" << temp.top() << "] ";
            temp.pop();
        }
        std::cout << "\n----------------------------\n";
    }
};

int main() {
    ScriptDebugger vm;
    
    // Simulating a basic Script: "2 3 OP_ADD 5 OP_EQUAL"
    std::vector<std::string> script = {"2", "3", "OP_ADD", "5", "OP_EQUAL"};
    
    std::cout << "--- Starting Bitcoin Script Debugger ---\n";
    for (const std::string& step : script) {
        vm.execute(step);
        vm.printStack();
    }
    
    return 0;
}
