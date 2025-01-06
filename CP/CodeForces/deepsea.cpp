#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ll t, n, k, sunk; 
    cin >> t;

    while (t--){
        sunk = 0;
        cin >> n;
        cin >> k;
        ll arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        ll j = n-1;
        ll i = 0;
        bool is_i = false;
        while(i < n  && j > 0 && i < j){

            int mini = min(arr[i], arr[j]);

            if (mini == arr[i]) is_i = true;
            else is_i = false;

            k -= 2*mini;
            if (k < 0) break;
            sunk++;
            
            if (is_i){ 
                arr[i] -= mini;
                i++;
            }
            else {
                arr[j] -= mini;
                j++;
            }
        }
        cout << sunk << endl;
    }
}