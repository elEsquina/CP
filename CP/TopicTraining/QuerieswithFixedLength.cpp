#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int get_max(stack<pair<int, int>>& st1, stack<pair<int, int>>& st2){
    int maximum;
    if (st1.empty() || st2.empty()) 
        maximum = st1.empty() ? st2.top().second : st1.top().second;
    else
        maximum = max(st1.top().second, st2.top().second);
    return maximum;
}

void add(stack<pair<int, int>>& st, int elem){
    int maximum = st.empty() ? elem : max(elem, st.top().second);
    st.push({elem, maximum});
}

int remove(stack<pair<int, int>>& st1, stack<pair<int, int>>& st2){
    if (st2.empty()) {
        while (!st1.empty()){
            int element = st1.top().first;
            st1.pop();
            add(st2, element);
        }
    }
    int remove_element = st2.top().first;
    st2.pop();
    return remove_element;
}


vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> sol;
    for (int j = 0; j < queries.size(); j++){
        int mini = INT_MAX;

        stack<pair<int, int>> s1, s2;
        for (int i = 0; i < arr.size(); i++){
            if(i>=queries[j]){
                mini = min(mini, get_max(s1, s2));
                remove(s1, s2);
            } 
            add(s1, arr[i]); 
        }
        mini = min(mini, get_max(s1, s2));
        sol.push_back(mini);
    }
    return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
