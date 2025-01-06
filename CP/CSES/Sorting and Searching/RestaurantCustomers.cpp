#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    ll t, n, a, b;
    cin >> n;
    t = n;

    vector<tuple<ll, ll, bool>> inp;
    while(t--){
        cin >> a; cin >> b;
        inp.push_back(make_tuple(a, t, true));
        inp.push_back(make_tuple(b, t, false));
    }
    sort(inp.begin(), inp.end());

    ll maxi = 0;
    ll k = 0;
    for (size_t  i = 0; i < inp.size(); i++){
        if (get<2>(inp[i])) k += 1;
        else k -= 1;
        maxi = max(k, maxi);
    }
    cout << maxi << endl;
    return 0;
}