// https://cses.fi/problemset/task/1193
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

vector<vector<pair<ll, ll>>> path;
vector<vector<bool>> visited;
vector<pair<ll, ll>> moves{{1, 0}, { -1, 0}, {0, -1}, {0, 1}};
ll n, m;
ll sx, sy, dx, dy;

bool isValid(ll x, ll y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	if (visited[x][y]) {
		return false;
	}
	return true;
}
void bfs() {
	queue<pair<ll, ll>> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	while (!q.empty()) {
		ll tempx = q.front().first;
		ll tempy = q.front().second;
		q.pop();
		for (auto mv : moves) {
			ll mvx = mv.first;
			ll mvy = mv.second;
			if (isValid(tempx + mvx, tempy + mvy)) {
				q.push({tempx + mvx, tempy + mvy});
				visited[tempx + mvx][tempy + mvy] = true;
				path[tempx + mvx][tempy + mvy] = {mvx, mvy};
			}
		}
	}
}

int main() {
	cin >> n >> m;
	path.resize(n);
	visited.resize(n);
	for (ll i = 0; i < n; i++) {
		path[i].resize(m);
		visited[i].resize(m);
		for (ll j = 0; j < m; j++) {
			path[i][j] = { 0, 0};
			char c; cin >> c;
			if (c == '#') visited[i][j] = true;
			if (c == 'A') sx = i, sy = j;
			if (c == 'B') dx = i, dy = j;
		}
	}
	bfs();
	if (!visited[dx][dy]) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<pair<ll, ll>> ans;
	while (dx != sx || dy != sy) {
		ans.push_back(path[dx][dy]);
		dx -= ans.back().first;
		dy -= ans.back().second;

	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto mv : ans) {
		if (mv.first == 1 && mv.second == 0) cout << "D";
		if (mv.first == -1 && mv.second == 0) cout << "U";
		if (mv.first == 0 && mv.second == 1) cout << "R";
		if (mv.first == 0 && mv.second == -1) cout << "L";
	}
}




























