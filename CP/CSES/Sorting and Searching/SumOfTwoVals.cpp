#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

typedef long long ll;
using namespace std;

int main(){
    ll n, x, temp;
    cin >> n; cin >> x;
    ll i = 0, j = n-1;
    vector<pair<ll, ll>> inp;

    for (int k = 0; k < n; k++){
        cin >> temp;
        inp.push_back(make_pair(temp, k+1));
    }
    sort(inp.begin(), inp.end());
    
    while(i!=j){
        if (inp[i].first + inp[j].first > x)
            j--;
        else if (inp[i].first + inp[j].first < x)
            i++;
        else{ 
            cout << inp[i].second << " " << inp[j].second << endl;
            break;
        }
    }
    
    if (i == j)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}