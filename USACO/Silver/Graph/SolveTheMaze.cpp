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
vector<ll> dR{-1, 0, 0, 1};
vector<ll> dC{0, 1, -1, 0};
ll des = 0;

bool checkG(ll r, ll c, vector<vector<bool>> &visited, vector<string> &G){
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    if(G[r][c] == '#' || visited[r][c]) return false;
    return true;
}

void floodFill(ll r, ll c, vector<vector<bool>> &visited, vector<string> &G){
    if(G[r][c] == '#') return;
    visited[r][c] = true;
    for(ll i = 0; i < dR.size(); i++){
        ll newR = r + dR[i];
        ll newC = c + dC[i];
        if(checkG(newR, newC, visited, G)){
            floodFill(newR, newC, visited, G);            
        }
    }
}


void solve(){
    cin >> n >> m;
    vector<string> G(n);
    for(ll i =  0; i < n; i++){
        string input; cin >> input;
        G[i] = input;
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(G[i][j] == 'B'){
                for(ll x = 0; x < dR.size(); x++){
                    ll newR = i + dR[x];
                    ll newC = j + dC[x];
                    if(newR >= 0 && newR < n && newC >= 0 && newC < m){
                        if(G[newR][newC] == 'G'){
                            cout << "No" << endl;
                            return;
                        }
                        if(G[newR][newC] == '.'){
                            G[newR][newC] = '#';
                        }
                    }
                }
            }
        }
    }
    //print2d(G);

    vector<vector<bool>> visited(n, vector<bool>(m));
    floodFill(n-1, m-1, visited, G);
    
    //print2d(visited);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(G[i][j] == 'G' && !visited[i][j]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
