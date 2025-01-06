using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;

map<string, string> parsetodict(string s) {
    map<string, string> dic;
    string key, value;
    bool storeinkey = true;
    
    if (s.size() == 2) {
        return dic;
    }    

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '{') {
            continue;
        }

        else if (s[i] == ':'){
            storeinkey = false;
            continue;
        }
        else if (s[i] == ',' || s[i] == '}') {
            dic[key] = value;
            key = "";
            value = "";
            storeinkey = true;
            continue;
        }

        if (storeinkey) {
            key += s[i];
        }
        else {
            value += s[i];
        }
    }
    return dic;
}

int main() {
    int t;
    string s1, s2;
    map<string, string> dic1, dic2;

    cin >> t;
    while(t--) {
        vector<string> splus, sminus, sstar;
        cin >> s1 >> s2;
        dic1 = parsetodict(s1);
        dic2 = parsetodict(s2);

        for(const auto& kv: dic2) {
            if (dic1.find(kv.first) == dic1.end()) {
                splus.push_back(kv.first);
            }
            else if (dic1[kv.first] != kv.second) {
                sstar.push_back(kv.first);
            }
        }
        for(const auto& kv: dic1) {
            if (dic2.find(kv.first) == dic2.end()) {
                sminus.push_back(kv.first);
            }
        }

        sort(splus.begin(), splus.end());
        sort(sminus.begin(), sminus.end());
        sort(sstar.begin(), sstar.end());

        if (splus.size() > 0) {
            cout << "+";
            for (int i = 0; i < splus.size(); ++i) {
                cout << splus[i];
                if (i != splus.size() - 1) {
                    cout << ",";
                }
            }
            cout << "\n";
        }
        
        if (sminus.size() > 0) {
            cout << "-";
            for (int i = 0; i < sminus.size(); ++i) {
                cout << sminus[i];
                if (i != sminus.size() - 1) {
                    cout << ",";
                }
            }
            cout << "\n";
        }
        
        if (sstar.size() > 0) {
            cout << "*";
            for (int i = 0; i < sstar.size(); ++i) {
                cout << sstar[i];
                if (i != sstar.size() - 1) {
                    cout << ",";
                }
            }
            cout << "\n";
        }

        if (splus.size() == 0 && sminus.size() == 0 && sstar.size() == 0)
            cout << "No changes"<< "\n";

        cout << "\n";
    }
    return 0;
}