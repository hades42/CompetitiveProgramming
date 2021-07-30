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
	ll n, m; cin >> n >> m;
	vector<tuple<ll,ll,ll>> adj(n);
	vector<ll> path(n, -1);
	for(ll i = 0; i < m; i++){
		ll a,b,c; cin >> a >> b >> c;
		a--; b--;
		adj.push_back({a,b,c});
	}
	vector<ll> dist(n, INF);
	ll cycle = -1;
	for(ll i = 1; i <= n+1; i++){
		for(auto e: adj){
			ll a , b ,w;
			tie(a,b,w) = e;
			if(dist[b] > dist[a] + w){
				if(i == n + 1){
					cycle = b;
				}
				path[b] = a;
				dist[b] = dist[a] + w;	
			}
		}
	}
	if(cycle == -1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<ll> ans;
	for(ll i = 0; i < n; i++){
		cycle = path[cycle];
	}
	ll end = cycle;
	do{
		ans.push_back(cycle+1);	
		cycle = path[cycle];
	} while(cycle != end);
	ans.push_back(cycle+1);
	reverse(ans.begin(), ans.end());
	print(ans);
}





























