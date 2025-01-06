#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef long long ll;
using namespace std;

int main(){
    ll n, temp, maxi, sum;
    cin >> n;
    maxi = LLONG_MIN;
    sum = 0;
    for (int k = 0; k < n; k++){
        cin >> temp;
        sum += temp;
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }

    cout << maxi << endl;
    return 0;
}