#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
    ll N, R;
    ll r, x , y;
    vector<tuple<ll,ll,ll>> inp;
    cin >> N; cin >> R;

    for(int i = 0; i < N; i++){
        cin >> r; cin >> x; cin >> y;
        inp.push_back(make_tuple(r, x, y));
    }

    ll count = 0;
    ll x0, y0, r0;
    for (int x = -R; x <= R; x++){
        for(int y = -R; y <= R;  y++){
            if (x*x + y*y <= R*R){
                for (int k = 0; k < N; k++){
                    x0 = get<1>(inp[k]) - x;
                    y0 = get<2>(inp[k]) - y;
                    r0 = get<0>(inp[k]);
                    if (x0*x0 + y0*y0 <= r0*r0){
                        count++;
                        break;
                    }
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}