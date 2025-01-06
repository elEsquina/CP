#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int solve(vector<string>& arr, int queens){
    if (queens == 0){
        return 1;
    }

    int i,j,k, pos; pos = 0;
    j = 8 - queens;
    for (k = 0; k < 8; k++){
        if (arr[j][k] == '.'){

            vector<string> tempArr;
            std::copy(arr.begin(), arr.end(), std::back_inserter(tempArr));

            for (i = 0; i < 8; i++){
                tempArr[j][i] = '#';
                tempArr[i][k] = '#';

                if (j+i < 8 && k+i<8)
                    tempArr[j+i][k+i] = '#';
                if (j-i >= 0 && k-i>=0)
                    tempArr[j-i][k-i] = '#';
                if (j+i < 8 && k-i>=0)
                    tempArr[j+i][k-i] = '#';
                if (j-i >= 0 && k+i<8)
                    tempArr[j-i][k+i] = '#';
            }
            tempArr[j][k] = '0';

            pos += solve(tempArr, queens - 1);
        }
    }
    
    return pos;
}

int main() {
    vector<string> arr;
    for (int i = 0; i < 8; i++){
        string p;
        cin >> p;
        arr.push_back(p);
    }
    cout << solve(arr,8) << endl;

    return 0;
}
