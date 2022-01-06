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
vector<vector<ll>> region;
ll n, k; 
vector<ll> dR{-1, 0, 0, 1};
vector<ll> dC{0, -1, 1, 0};

ll floodfill(ll r, ll c, ll re, ll color){
    if(r < 0 || r >= n || c < 0 || c >= 10) return 0;
    if(region[r][c] != 0) return 0;
    if(G[r][c] != color) return 0;

    region[r][c] = re; 
    ll size = 1;
    for(ll i = 0; i < 4; i++){
        size +=floodfill(r + dR[i], c + dC[i], re, color);
    }
    return size;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("mooyomooyo");
    cin >> n >> k;
    G.resize(n, vector<ll>(10));
    region.resize(n, vector<ll>(10));
    for(ll i = 0; i < n; i++){
        string input; cin >> input;
        for(ll j = 0; j < input.size(); j++){
            G[i][j] = input[j] - '0';
        }
    }
    while(true){
        ll re = 1;
        set<ll> currRegion;
    
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 10; j++){
                region[i][j] = 0;
            }
        }
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 10; j++){
                if(G[i][j] != 0 && region[i][j] == 0){
                    ll currSize = floodfill(i, j, re, G[i][j]);
                    if(currSize >= k){
                        currRegion.insert(re);
                    }
                    re++;
                }
            }
        }
    
        if(currRegion.size() == 0) break;
        
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 10; j++){
                if(currRegion.count(region[i][j])){
                    G[i][j] = 0;
                }
            }
        }

        // Gravity
        for(ll j = 0; j < 10; j++){
            ll countZe = n - 1;
            for(ll i = n - 1; i >= 0; i--){
                if(G[i][j] != 0){
                    G[countZe--][j] = G[i][j];
                }
            }

            while(countZe >= 0){
                G[countZe--][j] = 0;
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 10; j++){
            cout << G[i][j];
        }
        cout << endl;
    }
}
