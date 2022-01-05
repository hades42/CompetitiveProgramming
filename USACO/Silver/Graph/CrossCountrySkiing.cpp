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
vector<pair<ll ,ll>> wayPoint;
vector<vector<bool>> visited;
vector<vector<ll>> G;
vector<ll> dR{1, 0, 0, -1};
vector<ll> dC{0, 1, -1, 0};

bool canGo(ll r, ll c, ll point, ll oldR, ll oldC){
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    if(visited[r][c]) return false;
    if(abs(G[oldR][oldC] - G[r][c]) > point) return false;

    return true;
}

void floodfill(ll r, ll c, ll dis){
    visited[r][c] = true; 
    for(ll i = 0; i < dR.size(); i++){
        ll newR = r + dR[i];
        ll newC = c + dC[i];
        if(canGo(newR, newC, dis, r, c)){
            floodfill(newR, newC, dis);
        }
    }
}

bool check(ll dis){

    for(ll i = 0; i < wayPoint.size(); i++){
        for(ll r = 0; r < n; r++){
            for(ll c = 0; c < m; c++) visited[r][c] = false;
        } 

        floodfill(wayPoint[i].first, wayPoint[i].second, dis);

        for(ll j = 0; j < wayPoint.size(); j++){
            if(!visited[wayPoint[j].first][wayPoint[j].second]){
                return false;
            }
        }
        return true;
    } 
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("ccski");
    cin >> n >> m;
    G.resize(n, vector<ll>(m));
    visited.resize(n, vector<bool>(m, false));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> G[i][j];
        }
    }
    for(ll i =  0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll num; cin >> num;
            if(num){
                wayPoint.push_back({i, j});
            }
        }
    }
    
    ll left = 0; ll right = 1e10;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(check(mid)){
            right = mid;
        } else{
            left = mid + 1;
        }
    }

    cout << left << endl;
}
