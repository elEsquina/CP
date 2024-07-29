#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int s, d, quotient, q, yearSum, a, b;
    string input;

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }
        istringstream iss(input);
        iss >> s >> d;

        a = 5, b = 0;
        while (a*s - b*d > 0) {
            a--;
            b++;
        }
        quotient = a;

        yearSum = 0;
        vector<int> v(12, 0);
        for (int j = 0; j < 12; j++) {
            q = 0;
            for (int k = j; k < j + 5; k++) {
                if (v[k] != 0) {
                    q += v[k] > 0;
                    continue;
                } 
                if (q < quotient) {
                    v[k] = s;
                    q++;
                } else v[k] = -d;
                
            }
            yearSum += v[j];
        }

        if (yearSum > 0)
            cout << yearSum << endl;
        else
            cout << "Deficit" << endl;
    }

    return EXIT_SUCCESS;
}
