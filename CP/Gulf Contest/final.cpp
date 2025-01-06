#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <utility>

typedef long long ll;
using namespace std;

void devide(vector<ll> ref, ll& mini, ll a, ll b, ll s){
    queue<pair<ll,ll>> q;

    pair<ll, ll> thing;

    q.push(make_pair(a, b));
    while (!q.empty() && s > 0){

        thing = q.front();
        
        a = thing.first;
        b = thing.second;

        mini = min(abs(ref[b] - ref[a]), mini);
        s -= 1;
        ll mid = (b + a) / 2;
        if (a != mid){
            q.push(make_pair(a, mid));
        }
        if (b != mid){
            q.push(make_pair(mid, b));
        }
    }
}

int main(){
    ll T; 
    cin >> T; 

    while(T--){
        ll d, s, di;

        vector<ll> inp;

        cin >> d, cin >> s;
        
        for (int i = 0; i < d; i++){
            cin >> di;
            inp.push_back(di);
        }
        sort(inp.begin(), inp.end());

        ll mini = 1e9;
        devide(inp, mini, 0, d-1, s-1);

        cout << mini << endl;
    }

    

}