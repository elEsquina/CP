#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
    ll N, M, temp;
    cin >> N; cin >> M;

    vector<ll> inp;
    vector<double> out;
    for(int i = 0; i < M; i++){
        out.push_back(0);
    }
    for(int i = 0; i < N; i++){
        cin >> temp;
        out[temp-1] += 1;
    }

    for(int i = 0; i < M; i++){
        cout << ceil(out[i]/12) << endl;
    }

    return 0;
}