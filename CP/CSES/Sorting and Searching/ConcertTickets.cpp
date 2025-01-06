#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll n, m, k, q; 
    cin >> n >> m; 
    vector<ll> customers;
    multiset<ll> tickets;

	for (k = 0; k < n; ++k) {
        cin >> q;
        tickets.insert(q);
    }
    
	for (k = 0; k < m; ++k) {
        cin >> q;
		auto ptr = tickets.upper_bound(q);
        if (ptr == tickets.begin())
            cout << -1 << endl; 
        else{
            cout << *(--ptr) << endl;
            tickets.erase(ptr);
        }
    }

    return 0;
}