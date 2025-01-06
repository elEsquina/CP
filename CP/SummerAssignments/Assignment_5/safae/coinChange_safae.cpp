#include <iostream>
#include <vector>

#define size 5
#define cap 7490
using namespace std;

int coins[5] = {1, 5, 10, 25, 50};
int coinChange(int n) {
    vector<int> ways(cap, 0);
    ways[0] = 1;
    for (int i = 0; i < size; i++) {
        for (int j = coins[i]; j <= n; j++)
            ways[j] += ways[j - coins[i]];
    }
    return ways[n];
}

int main() {

    int input;
    while (cin >> input) {
        vector<int> change(5, input);
        cout << coinChange(input) << endl;
    }

    return EXIT_SUCCESS;
}