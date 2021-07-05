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
int main() {
	ll t; cin >> t; 
	while(t--){
		ll n; cin >> n;
		vector<ll> arr(n);
		set<ll> s;
		for(ll i = 0; i < n; i++){
			cin >> arr[i];
			s.insert(arr[i]);
		}
		bool find = false;
		for(ll k = 1; k <= 1024; k++){
			if(check(k, arr, s)){
				find = true;
				cout << k << endl;
				break;
			}
		}
		if(!find){
			cout << -1 << endl;
		}
	}
}




































