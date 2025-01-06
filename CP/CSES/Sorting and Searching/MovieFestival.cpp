#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    ll t, n, a, b;
    cin >> n;
    t = n;

    vector<pair<ll, ll>> inp;
    while(t--){
        cin >> a; cin >> b;
        inp.push_back(make_pair(b, a));
    }
    sort(inp.begin(), inp.end());

    size_t ptr = 0;
    size_t out = inp.size();
    for (size_t i = 1; i < inp.size(); i++){
        if (inp[ptr].first > inp[i].second)
            out--;
        else
            ptr = i;
    }

    cout << out << endl;
    return 0;
}