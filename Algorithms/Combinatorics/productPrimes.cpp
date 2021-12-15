using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
long long primeProduct(long long L, long long R) {
long long M=1000000007;

                int N = sqrt(R);

vector<bool> isprime(N + 1, true);

vector<int> primes;

long long ans = 1;

 

// Sieve

isprime[0] = isprime[1] = false;

 

for (int i = 2; i * i <= N; i++) {

if (isprime[i]) {

for (int j = i; i * j <= N; j++) {

isprime[i * j] = false;

}

}

}

 

//All prime numbers in primes vector

for (int i = 0; i <= N; i++) {

if (isprime[i])

primes.push_back(i);

}

 

// for (int i = 0; i < primes.size(); i++)

// cout << primes[i] << " ";

 

vector<bool> isprime1(R - L + 1, true);

 

for (int i = 0; i < primes.size(); i++) {

int k = ceil(1.0 * L / primes[i]);

 

for (int j = max(k, 2); primes[i] * j <= R; j++) {

isprime1[primes[i] * j - L] = false;

}

}

 

// for (int i = 0; i < isprime1.size(); i++)

// cout << isprime1[i] << " ";

 

for (int i = 0; i < (R - L + 1); i++) {

 

if (isprime1[i]) {

ans = ((ans % M) * ((i + L) % M)) % M;

}

}

 

return ans % M;

}
int main(){
     ll left,right;
     cin>>left>>right;
     cout<<primeProduct(left,right);
    getchar();
    return 0;
}