#include <iostream>
#include <vector>
using namespace std;


void sigma_sieve(vector<long long>& sigma, long long prev, long long N) {
    for (long long i = 0; i < N - prev + 1; i++){
        sigma.push_back(1);
    }
    long long i = prev;
    long long j = 0;
    for(i = prev; i <= N; i++){
            for( j = i + i; j <= N; j += i){
                sigma[j] += i;
            }
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> sigma(3, 1); 
    sigma[2] = 3;
    long long maxi = 2;
    for (long long i = 0; i < n; i++){
    	long long l;
    	cin >> l;
        if (max(l, maxi) == l){
            sigma_sieve(sigma, maxi, l);
            maxi = l;
        }
    	cout << sigma[l] << endl;
    }

    return 0;
}


