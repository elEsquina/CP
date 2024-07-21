#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n, a, cost;
    priority_queue<int, vector<int>, compare> numbers;

    while (true) {
        cin >> n;
        if (n == 0) 
            break;
        while (n--) {
            cin >> a;
            numbers.push(a);
        }

        cost = 0;
        while (!numbers.empty()) {
            a = numbers.top();
            numbers.pop();
            if (numbers.empty())
                break;
            a += numbers.top();
            numbers.pop();
            cost += a;
            numbers.push(a);
        }
        cout << cost << endl;
    }
    return EXIT_SUCCESS;
}