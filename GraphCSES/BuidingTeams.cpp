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

vector<vector<ll>> graph;
vector<ll> color;
ll n, m;
bool check = true;

void bfs(ll i){
	queue<ll> q;
	q.push(i);
	color[i] = 1;
	while(!q.empty()){
		ll temp = q.front();
		q.pop();
		for(ll num : graph[temp]){
			if(color[num] == -1){
				color[num] = 1 - color[temp];
				q.push(num);
			}
			else if(color[num] == color[temp]){
				check = false;
				return;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	graph.resize(n);
	color.resize(n);
	for(ll i = 0; i < n; i++) color[i] = -1; 	
	for(ll i = 0; i < m; i++){
		ll a, b; cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);	
	}
	for(ll i = 0; i < n; i++){
		if(color[i] == - 1){
			bfs(i);
		}
	}
	if(!check){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(ll &num : color){
		if(num == 0) num = 2;
	}
	print(color);
}





























