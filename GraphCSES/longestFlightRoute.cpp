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

vector<vector<ll>> edge;
vector<vector<ll>> pre_edge;
vector<ll> degree;
vector<ll> parent;
vector<ll> dist;
ll n, m;

void topsort(){
	queue<ll> q;
	for(ll i = 0; i < n; i++){
		if(degree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		ll u = q.front();
		q.pop();

		for(ll v : edge[u]){
			degree[v]--;
			if(degree[v] == 0) q.push(v);
		}

		ll mx = -INF;
		ll mx_node = -1;
		for(ll prev : pre_edge[u]){
			if(dist[prev] + 1 > mx){
				mx = dist[prev] + 1;
				mx_node = prev;
			}
		}
		parent[u] = mx_node;
		dist[u] = mx;
		if(u == 0) dist[u] = 1;
	}
}

int main() {
	cin >> n >> m;
	edge = vector<vector<ll>>(n);
	pre_edge = vector<vector<ll>>(n);
	degree = vector<ll>(n);
	parent= vector<ll>(n,-1);
	dist = vector<ll>(n, -INF);
	for(ll i = 0; i < m; i++){
		ll a, b; cin >> a >> b; a--; b--;
		edge[a].push_back(b);
		pre_edge[b].push_back(a);
		degree[b]++;
	}
	topsort();
	if(dist[n-1] > 0){
		vector<ll> ans;
		ll end = n-1;
		while(end != 0){
			ans.push_back(end);
			end = parent[end];
		}
		ans.push_back(0);
		cout << ans.size() << endl;
		for(ll i = 0; i < ans.size(); i++) cout << ans[ans.size() - i - 1]+1 << " ";
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}





























