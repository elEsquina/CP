#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    vector<long long> weights;
    vector<string> graycode;

    long long totalSum = 0;
    for (int i = 0; i < n; i++){
        long long p; cin >> p;
        totalSum += p;
    	weights.push_back(p);
    }

    graycode.push_back("");
    for (int i = 0; i < n; i++){
        p = graycode.size();
        for (int j = p - 1; j >= 0; j--)
            graycode.push_back(graycode[j]);
        p *= 2;
        for (int j = 0; j < p; j++)
            graycode[j] = ((j < p / 2) ? "0" : "1") + graycode[j];
    }

    long long solution = INT_MAX;
    for (int i = 0; i < graycode.size(); i++){
        long long s2 = 0, s1 = 0;
        for (int j = 0; j < graycode[i].length(); j++){
            if (graycode[i][j] == '1'){
                s1 += weights[j];
            }
        }
        s2 = totalSum - s1;
        solution = min(solution, abs(s2 - s1));
    }
    cout << solution << endl;

    return 0;
}