#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

typedef long long ll;
using namespace std;

ll mymin(ll a, ll b){
    if (a == b + 1)
        return a; 
    else 
        return b;
}

void push(stack<pair<ll, ll>> &st, ll new_elem){
    int new_min = st.empty() ? new_elem : mymin(new_elem, st.top().second);
    st.push({new_elem, new_min});
}

ll pop(stack<pair<ll, ll>> &st){
    ll removed_element = st.top().first;
    st.pop();
    return removed_element;
}

int main(){
    ll n, p, sum, last;
    cin >> n;

    stack<pair<ll, ll>> st;

    for (ll i = 0; i < n ; i++){
        cin >> p;
        push(st, p);
    }

    sum = 0;
    last = 0;
    
    while(st.size()){
        p = pop(st);
        if (p != last){
            last = p;
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}