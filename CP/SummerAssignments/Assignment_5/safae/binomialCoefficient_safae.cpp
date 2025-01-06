#include <iostream>
#include <vector>

#define A 10000000000
typedef long long ll;

using namespace std;

vector<vector<ll>> coeff(A, vector<ll>(A, 0));

void printVect(vector<pair<int, int>> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << "(" << (*it).first << "," << (*it).second << ")";
        if (it != v.end() - 1) {
            cout << " ";
        } else
            cout << endl;
    }
}

ll binomialCoefficient(ll n, ll k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == 0)
                coeff[i][j] = 1;
            coeff[i+1][j+1] = coeff[i][j] + coeff[i+1][j];
        }
    }
    return coeff[k][n];
}

int main() {
    int t;
    ll m;
    vector<pair<int, int>> coefficients;

    binomialCoefficient(A, A);

    cin >> t;
    while (t--) {
        cin >> m;
        for (ll j = 1; j < A; j++) {
            for (ll i = 1; i < j; i++) {
                if (coeff[i][j] == m)
                    coefficients.push_back(make_pair(j, i));
            }
        }
        cout << coefficients.size() << endl;
        printVect(coefficients);
        coefficients.clear();
    }

    return EXIT_SUCCESS;
}