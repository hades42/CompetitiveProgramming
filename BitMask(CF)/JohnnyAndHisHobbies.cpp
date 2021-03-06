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
vector<ll> primes_list;
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

vector<ll> factors(ll n){
	vector<ll> ans;
	for(ll i = 0; primes_list[i]*primes_list[i] <= n && i < primes_list.size(); i++){
		if(n % primes_list[i] == 0){
			while(n % primes_list[i] == 0){
				n = n/primes_list[i];
				ans.push_back(primes_list[i]);
			}
		}
	}
	if(n > 1){
		ans.push_back(n);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

bool check(ll k, vector<ll> arr, set<ll> s){
	for(ll i = 0; i < arr.size(); i++){
		if(!s.count(arr[i] ^k)){
			return false;
		}
	}
	return true;
}

vector<ll> cnt(3000005);
int main() {
	ll t; cin >> t; 
	while(t--){
		ll n, w; cin >> n >> w;
		for(ll i = 0; i < n; i++){
			ll n; cin >> n;
			cnt[n]++;
		}
		ll ans = 0;
		while(n>0){
			ll curr = w;
			for(ll i = (1 << 20); i >= 1; i >>= 1){
				while(cnt[i] > 0 && curr >= i){
					cnt[i]--;
					n--;
					curr -= i;
				}
			}
			ans++;
		}
		cout << ans << endl;
	}
}




































