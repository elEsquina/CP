#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    string p;
    while (t--){
        cin >> p;
        int freqA = 0;
        int freqB = 0;
        for (int i = 0; i < p.size(); i++){
            if (p[i] == 'A') freqA++;
            if (p[i] == 'B') freqB++;
        }
        if (freqA > freqB) cout << 'A' << endl;
        else
        cout << 'B'  << endl;
    }
}