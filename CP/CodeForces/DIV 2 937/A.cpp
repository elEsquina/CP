#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll T, n, x, y; 

    cin >> T;

    while(T--){
        cin >> n >> x >> y;

        if (x >= y){
            if (n%y == 0){
                cout << n/y << endl;
            }
            else{
                cout << n/y + 1 << endl;
            }
        }
        else {
            if (n%x == 0){
                cout << n/x << endl;
            }
            else{
                cout << n/x + 1 << endl;
            }
        }
    }

    return 0;
}