#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1e18;
using namespace std;

template<typename T>
void print(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}

template<typename T>
void print2d(const T& t) {
    std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

const ll maxSize = 100100;
bool primes[maxSize];
void precompute(){
	fill(primes, primes + maxSize, true);
	primes[0] = false;
	primes[1] = false;
	for(ll i = 2; i*i < maxSize; i++){
		if(primes[i]){
			for(ll j = i + i; j < maxSize; j+= i){
				primes[j] = false;
			}
		}
	}
}

int main() {
	ll n, m,k; cin >> n >> m >> k;
	vector<ll> arr(m+1);
	for(ll i = 0; i < m+1; i++){
		cin >> arr[i];
	}
	ll ans = 0;
	for(ll i = 0; i < m; i ++){
		ll count = 0;
		ll fedor = arr[m];
		for(ll z = 0; z < n; z++){
			ll a = arr[i] & 1;
			ll b = fedor & 1;
			if(a != b) count++;
			arr[i] >>= 1;
			fedor >>= 1;
		}
		if(count <= k) ans++;
	}
	cout << ans << endl;
}