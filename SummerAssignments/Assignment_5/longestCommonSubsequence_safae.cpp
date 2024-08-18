#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCS(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> c(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    return c[n][m];
}

int main() {
    string str1, str2, blank;
    while (true) {
        getline(cin, str1);
        getline(cin, str2);
        
        if (str1.empty() && str2.empty())
            break;
            
        int result = LCS(str1, str2);
        cout << result << endl;
        str1.clear();
        str2.clear();
    }
    return EXIT_SUCCESS;
}