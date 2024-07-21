#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

void addContainer(vector<stack<char>> &stacks, char container) {
    for (int i = 0; i < stacks.size(); i++) {
        if (stacks[i].top() >= container) {
            stacks[i].push(container); 
            return;
        }
    }
    stack <char> newStack;
    newStack.push(container);
    stacks.push_back(newStack);
}

int main() {
    string inp;
    ll casei = 0;

    while (true) {
        cin >> inp;

        if (inp == "end") {
            break;
        }

        vector<stack<char>> stacks;
        for (int i = 0; i < inp.size(); i++) {
            addContainer(stacks, inp[i]);
        }

        casei++;
        cout << "Case " << casei << ": " << stacks.size() << endl;
    }

    return 0;
}
