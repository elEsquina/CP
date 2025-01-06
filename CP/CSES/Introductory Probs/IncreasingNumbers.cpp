#include <iostream>
#include <string>

using namespace std;

int main(){
    long n, cur, prev;
    long c = 0;
    
    cin >> n;
    cin >> prev; 
    cur = prev; 

    for(int i = 1; i< n ;i++){
        cin >> cur;
        if (cur < prev)
            c += prev - cur;
        prev = max(cur, prev);
    }

    cout << c;
    return 0;
};
