#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
typedef long long ll;
using namespace std;
 
int main(){
    ll t, N, temp;
    cin >> t;
 
 
    while (t--){
        cin >> N;
 
        queue<ll> inp;
        vector<ll> copy;
        ll steps, cur, cste;
 
        for (int i = 0; i < N; i++){
            cin >> temp;
            inp.push(temp);
            copy.push_back(temp);
        }
        if (N == 1){
            cout << 0 << endl;
            continue;
        }
        sort(copy.begin(), copy.end());
 
        steps = -1;
        cur = 0;
        while(cur < N){
            cste = inp.front();                
            inp.pop();
            if (cste == copy[cur]){
                cur += 1;
            } 
            inp.push(cste);
            steps++;
        }
 
        cout << steps << endl;
 
    }
    
    return 0;
}