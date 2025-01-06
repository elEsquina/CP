#include <iostream>
#include <cmath>
using namespace std;
void solve(int n, int s, int r){
    if (n == 1){
        cout << s << " " << r << endl;
        return;
    }
    int i;
    if (s == 1 && r == 3 || s == 3 && r == 1)
        i = 2;
    else if (s == 2 && r == 1 || s == 1 && r == 2)
        i = 3;
    else 
        i = 1;

    solve(n-1, s, i);
    cout << s << " " << r << endl;
    solve(n-1,i, r);
}
int main(){
    int n; cin>>n;
    cout << (int) pow(2, n) - 1 << endl;
    solve(n, 1, 3);
    return 0;
}