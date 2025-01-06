#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    ll N, A, B, temp;
    cin >> N;
    cin >> A; cin>>B;
    vector<ll> inp; 

    for (int i = 0; i < N; i++){
        cin >> temp;
        inp.push_back(temp);
    }

    if (A < 0) sort(inp.rbegin(), inp.rend());
    else sort(inp.begin(), inp.end());
    
    ll count = 0;
    for (int i = 0; i < N; i++){
        count += (i+1) * (A * inp[i] + B);
    }
    cout << count << endl;

    return 0;
}