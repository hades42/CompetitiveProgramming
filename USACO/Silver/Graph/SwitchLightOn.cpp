#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n, m;
vector<vector<bool>> vis;
vector<vector<bool>> ilu;
ll ans = 1;
map<pair<ll,ll>, vector<pair<ll,ll>>> mp;
vector<ll> dR{-1, 0, 0, 1};
vector<ll> dC{0, -1, 1, 0};

void floodfill(ll r, ll c){
    if(r <= 0 || r > n || c <= 0 || c > n) return;
    if(!ilu[r][c]) return;
    if(vis[r][c]) return;
    vis[r][c] = true;
    pr temp = make_pair(r, c);
    for(auto pi : mp[temp]){
        ll tempR = pi.first;
        ll tempC = pi.second;
        if(!ilu[tempR][tempC]){
            ilu[tempR][tempC] = true;
            ans++;
        }
        if(vis[tempR + 1][tempC] || vis[tempR -1][tempC] || vis[tempR][tempC + 1] || vis[tempR][tempC - 1]){
            floodfill(tempR, tempC);
        }
    }

    for(ll i = 0; i < dR.size(); i++){
        floodfill(r + dR[i], c + dC[i]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("lightson");
    cin >> n >> m;
    vis.resize(n+5, vector<bool>(n+5, false));
    ilu.resize(n+5, vector<bool>(n+5, false));
    for(ll i = 0; i < m; i++){
        ll x, y, a, b; cin >> x >> y >> a >> b;
        pr temp = make_pair(x, y);
        mp[temp].push_back({a, b});
    }
    
    ilu[1][1] = true;
    floodfill(1,1);
    cout << ans << endl;
}
