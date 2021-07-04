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
	ll t; cin >> t;
	while(t--){
		ll n, l, r; cin >> n >> l >> r;
		vector<ll> arr(n);
		for(ll i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		ll ans = 0;
		for(ll i = 0; i < n - 1; i ++){
			auto a = lower_bound(arr.begin() + i + 1, arr.end(), l - arr[i]);
			auto b = upper_bound(arr.begin() + i + 1, arr.end(), r - arr[i]);
			ans += (b-a);
		}
		cout << ans << endl;
	}
}