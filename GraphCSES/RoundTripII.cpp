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
void precompute() {
	fill(primes, primes + maxSize, true);
	primes[0] = false;
	primes[1] = false;
	for (ll i = 2; i * i < maxSize; i++) {
		if (primes[i]) {
			for (ll j = i + i; j < maxSize; j += i) {
				primes[j] = false;
			}
		}
	}
}

vector<ll> factors(ll n) {
	vector<ll> ans;
	for (ll i = 0; primes_list[i]*primes_list[i] <= n && i < primes_list.size(); i++) {
		if (n % primes_list[i] == 0) {
			while (n % primes_list[i] == 0) {
				n = n / primes_list[i];
				ans.push_back(primes_list[i]);
			}
		}
	}
	if (n > 1) {
		ans.push_back(n);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
ll highestOneBit(ll i) {
	i |= (i >>  1);
	i |= (i >>  2);
	i |= (i >>  4);
	i |= (i >>  8);
	i |= (i >> 16);
	return i - (i >> 1);
}
ll pow(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return ans;
}

ll n, m;
vector<bool> visited;
vector<bool> finish;
vector<ll> ans;
vector<vector<ll>> graph;
vector<ll> parent;

void dfs(ll u) {
	if (ans.size() > 0) return;
	for (auto v : graph[u]) {
		if (ans.size() == 0 && visited[v] && !finish[v]) {
			ll u2 = u;
			while(u != v){
				ans.push_back(u);
				u = parent[u];
			}
			ans.push_back(v);
			ans.push_back(u2);
			return;
		} else if(!visited[v]){
			parent[v] = u;
			visited[v] = true;
			dfs(v);
			finish[v] = true;
		}
	}
}

int main() {
	cin >> n >> m;
	visited.resize(n);
	graph.resize(n);
	parent.resize(n);
	finish.resize(n);
	for (ll i = 0; i < n; i++) {
		parent[i] = -1;
		visited[i] = false;
		finish[i] = false;
	}
	for (ll i = 0; i < m; i++) {
		ll a , b; cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
	}
	for (ll i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
			finish[i] = true;
		}
	}
	if(ans.size() == 0){ 
		cout << "IMPOSSIBLE" << endl;
	} else{
		cout << ans.size() << endl;
		reverse(ans.begin(), ans.end());
		for(ll num : ans) cout << num + 1 << " ";
	}
}





























