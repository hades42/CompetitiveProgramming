#include <bits/stdc++.h>
#define ll long long
const ll MOD = 998244353;
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
ll highestOneBit(ll i){
	i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (i >> 1);
}
ll pow(ll a, ll b, ll mod){
	ll ans = 1;
	while(b){
		if(b & 1) ans = (ans*a) % mod;
		b /= 2;
		a = (a*a) % mod;
	}
	return ans;
}

int main() {
	ll n, m , k;
	cin >> n >> m >> k;
	ll count1 = 0;
	ll other = 0;
	for(ll i = 0; i < m; i++){
		ll u, v; cin >> u >> v;
		if(u == 1 || v == 1){
			count1++;
		} else{
			other++;
		}
	}
	vector<ll> ans(k);
	ans[0] = ans[k-1] = 1;
	for(ll i = 1; i < k-1; i++){
		if(i&1){
			ans[i] = (n-1-count1);
		} else{
			ans[i] = (n - count1 - other);
		}
	}
	ll res = 1;
	for(ll i = 0; i < k; i++){
		res = (res * ans[i]) % MOD;
	}
	cout << res << endl;
}





























