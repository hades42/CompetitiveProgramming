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

ll n, k, ro;
vector<vector<ll>> G;
vector<vector<bool>> visited;
bool road[105][105][105][105];
vector<ll> dR{-1, 0, 0, 1};
vector<ll> dC{0, 1, -1, 0};

bool check(ll r, ll c, ll newR, ll newC){
    if(newR >= 0 && newR < n && newC >= 0 && newC < n && !visited[newR][newC]){
        if(!road[r][c][newR][newC]){
            return true;
        }
    } 
    return false;
}

void floodfill(ll r, ll c){
    
    visited[r][c] = true;
    for(ll i = 0; i < 4; i++){
        ll newR = r + dR[i];
        ll newC = c + dC[i];
        if(check(r, c, newR, newC)){
            floodfill(newR, newC);
        }
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("countcross");

    cin >> n >> k >> ro; 
    G.resize(n, vector<ll>(n));
    visited.resize(n, vector<bool>(n));
    vector<pair<ll,ll>> cow;
    for(ll i = 0; i < ro; i++){
        ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        road[r1][c1][r2][c2] = 1;
        road[r2][c2][r1][c1] = 1;
    } 

    for(ll i = 0; i < k; i++){
        ll r, c; cin >> r >> c;
        r--; c--;
        G[r][c] = 1;
        cow.push_back({r, c});
    }
    //print2d(G);
   
    ll ans = 0;
    for(ll i = 0; i < cow.size(); i++){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        ll toreach = 0;
        floodfill(cow[i].first, cow[i].second);
        for(ll j = 0; j < cow.size(); j++){
            if(i == j) continue;
            if(visited[cow[j].first][cow[j].second]){
                toreach++;
            }
        }
        ans += (k - 1 - toreach);
    }
    cout << ans/2 << endl;
}
