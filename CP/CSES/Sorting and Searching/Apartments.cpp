#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll n, m, k; 
    cin >> n >> m >> k; 
    
    vector<ll> apSizes, desiredSizes;
    while (n--){
        ll q;
        cin >> q;
        desiredSizes.push_back(q);
    }
    while (m--){
        ll q;
        cin >> q;
        apSizes.push_back(q);
    }

    ll count = 0;
    sort(apSizes.begin(), apSizes.end());
    sort(desiredSizes.begin(), desiredSizes.end());
    ll app = 0, peop = 0;
    while (app < apSizes.size() && peop < desiredSizes.size()){
        if (desiredSizes[peop] - k <= apSizes[app] && apSizes[app] <= k + desiredSizes[peop]){
            app++; peop++; count++;
        }
        else if(apSizes[app] > desiredSizes[peop])
            peop++;
        else
            app++;
    }
    cout << count << endl;
    return 0;
}
