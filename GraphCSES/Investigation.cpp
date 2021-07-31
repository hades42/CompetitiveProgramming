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
typedef pair<ll, ll> pi;
vector<vector<pair<ll, ll>>> edge;
vector<ll> dist;
vector<ll> num;
vector<ll> minf;
vector<ll> maxf;
vector<bool> visited;
int main() {
	ll n, m; cin >> n >> m;
	edge = vector<vector<pair<ll, ll>>>(n);
	dist = vector<ll>(n, INF);
	minf = vector<ll>(n);
	maxf = vector<ll>(n);
	num = vector<ll>(n);
	visited = vector<bool>(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		edge[a].push_back({b, c});
	}
	num[0] = 1;
	dist[0] = 0;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		ll a = pq.top().second;
		pq.pop();
		if(!visited[a]){
			visited[a] = true;
			for(auto v : edge[a]){
				ll b = v.first, w = v.second;
				ll temp = dist[a] + w;
				if(dist[b] > temp){
					dist[b] = temp;
					num[b] = num[a];
					minf[b] = minf[a] + 1;
					maxf[b] = maxf[a] + 1;
					pq.push({dist[b], b});
				} else if(dist[b] == temp){
					num[b] = (num[b] + num[a]) % MOD;
					minf[b] = min(minf[b], minf[a] + 1);
					maxf[b] = max(maxf[b], maxf[a] + 1);
				}
			}
		}
	}
	cout << dist[n-1] << " " << num[n-1] << " " << minf[n-1] << " " << maxf[n-1] << endl;
}






























