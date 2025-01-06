#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


typedef long long ll;
using namespace std;

ll findMedian(vector<ll>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return (ll) (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    } else {
        return (ll) nums[n / 2];
    }
}

int main(){
    ll n, p, mean;
    cin >> n;

    vector<ll> inp; 
    for (ll i = 0; i < n ; i++){
        cin >> p;
        inp.push_back(p);
    }
    mean = findMedian(inp); 

    p = 0;
    for (ll i = 0; i < n ; i++){
        p += abs(inp[i] - mean);
    }  
    cout << p;

}