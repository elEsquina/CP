#include <iostream>
#include <string>

using namespace std;

int main(){
    long n;
    cin >> n;

    if (n == 3 || n == 2){
        cout << "NO SOLUTION";
        return 0;
    }

    long c = 0, p = 1;

    for(long i = 0; i <= n ; i++){

        if (i > n/2 && 2*c + 1 <= n)
            cout << 2*c++ + 1 << " ";
        else if(2*p <= n)
            cout << 2*p++ << " ";
        
    }
    
    return 0;
};
