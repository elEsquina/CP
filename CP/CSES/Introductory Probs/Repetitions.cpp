#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int max_size = 1;
    int k = 1;

    for (string::size_type i = 1; i < str.length(); i++){ 
        if (str[i] == str[i-1])
            k++;
        else {
            max_size = max(max_size,k);
            k = 1;
        }
    }
    cout << max(max_size,k);

    return 0;
}