#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, p;
    cin >> n;
    vector<string> out;
    out.push_back("");
    for (int i = 0; i < n; i++){
        p = out.size();
        for (int j = p - 1; j >= 0; j--)
            out.push_back(out[j]);
        p *= 2;
        for (int j = 0; j < p; j++)
            out[j] = ((j < p / 2) ? "0" : "1") + out[j];
    }
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << endl;
    return 0;
}
