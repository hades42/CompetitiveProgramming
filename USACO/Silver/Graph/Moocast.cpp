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

vector<vector<ll>> G;
vector<bool> visited;

struct Cow{
    ll x;
    ll y;
    ll p;
};

void dfs(ll u){
    visited[u] = true;
    for(ll v : G[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("moocast");
    ll n; cin >> n;
    vector<Cow> arr(n);
    G.resize(n);
    visited.resize(n);
    for(ll i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == j) continue;
            ll distance = (arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y);
            ll hops = arr[i].p * arr[i].p;
            if(distance <= hops){
                //cout << i << " " << j << endl;
                //cout << distance << " " << hops << endl;
                G[i].push_back(j);
            }
        }
        //cout << endl;
    }
    //print2d(G);
    ll res = 0;
    for(ll i = 0; i < n; i++){
        for(ll i = 0; i < n; i++) visited[i] = false;
        dfs(i);
        ll temp = 0;
        for(ll i = 0; i < n; i++){
            if(visited[i]) temp++;
        }
        res = max(res, temp);
    }

    cout << res << endl;
}
