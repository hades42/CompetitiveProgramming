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
vector<vector<ll>> g;
vector<pair<ll,ll>> mons;
pair<ll ,ll> si, se;
vector<pair<ll,ll>> moves{{1,0}, {-1, 0}, {0,1}, {0,-1}};
map<pair<ll,ll>, pair<ll,ll>> path;
bool gate = false;

bool isValid(ll x, ll y, ll timer){
	if(x < 0 || y < 0 || x >= n || y >= m){
		return false;
	} 
	if(g[x][y] <= timer) {
		return false;
	}
	return true;
}
void bfsMonster(){
	queue<pair<pair<ll,ll>, ll>> q;
	for(auto m : mons){
		q.push({m, 0});
	}
	while(!q.empty()){
		ll tx = q.front().first.first;
		ll ty = q.front().first.second;
		ll timer = q.front().second;
		q.pop();
		timer++;
		for(auto mv : moves){
			ll mvx = mv.first;	
			ll mvy = mv.second;	
			if(isValid(tx + mvx, ty + mvy, timer)){
				g[tx+mvx][ty+mvy] = timer;
				q.push({{tx+mvx, ty+mvy}, timer});
			}
		}
	}
}
void bfsPlayer(){
	queue<pair<pair<ll,ll>, ll>> q;
	q.push({si, 0});
	while(!q.empty()){
		ll tx = q.front().first.first;
		ll ty = q.front().first.second;
		ll timer = q.front().second;
		q.pop();
		timer++;
		for(auto mv : moves){
			ll mvx = mv.first;	
			ll mvy = mv.second;	
			if(isValid(tx + mvx, ty + mvy, timer)){
				g[tx+mvx][ty+mvy] = timer;
				q.push({{tx+mvx, ty+mvy}, timer});
				path[{tx+mvx, ty+ mvy}] = {tx, ty}; 
				ll tempx = tx+mvx;
				ll tempy = ty+ mvy;
				if(tempx == 0 || tempy == 0 || tempy == m-1 || tempx == n-1){
					gate = true;	
					se = {tempx, tempy};
					return;
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	g.resize(n);
	for(ll i = 0; i < n; i++){
		g[i].resize(m);
		for(ll j = 0; j < m; j++){
			char c; cin >> c;
			if(c== '#') g[i][j] = 0;
			else if(c == 'A'){
				g[i][j] = 0;	
				si = {i,j};
			} else if(c == 'M'){
				mons.push_back({i,j});
				g[i][j] = 0;
			} else{
				g[i][j] = INF;
			}
		}
	}
	if(si.first == 0 || si.first == n || si.second == m || si.second == 0){
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	bfsMonster();
	bfsPlayer();
	if(!gate){
		cout << "NO" << endl;
		return 0;
	}
	cout <<"YES" << endl;
	vector<pair<ll,ll>> ans;
	pair<ll,ll> temp = path[se];
	while(temp.first != si.first || temp.second != si.second){
		ll x = se.first - temp.first;
		ll y = se.second - temp.second;
		ans.push_back({x, y});
		se = temp;
		temp = path[se];
	}
	ans.push_back({se.first - temp.first, se.second - temp.second});
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto p : ans){
		if(p.first == 1 && p.second == 0) cout << "D";
		if(p.first == -1 && p.second == 0) cout << "U";
		if(p.first == 0 && p.second == -1) cout << "L";
		if(p.first == 0 && p.second == 1) cout << "R";
	}
	return 0;	
} 





























