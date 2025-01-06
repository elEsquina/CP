#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

int main(){
    ll n; 
    cin >> n; 
    set<int> mySet;
    while (n--){
        ll q;
        cin >> q;
        mySet.insert(q);
    }
    cout << mySet.size();
    return 0;
}