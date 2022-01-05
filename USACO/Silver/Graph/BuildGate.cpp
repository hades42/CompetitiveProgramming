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
ll n;
string step;
vector<vector<bool>> G(4005, vector<bool>(4005));
vector<vector<bool>> visited(4005, vector<bool>(4005));
ll maxR = 2001, minR = 2001, maxC = 2001, minC = 2001;
ll startR = 2001;
ll startC = 2001;

void floodfill(ll r, ll c){
    if(r > maxR || r < minR || c > maxC || c < minC){
        return;
    }
    if(visited[r][c] || G[r][c]){
        return;
    }
    visited[r][c] = true;
    vector<ll> dR{1, 0, 0, -1};
    vector<ll> dC{0, 1, -1, 0};

    for(ll i =  0; i < dR.size(); i++){
            floodfill(r + dR[i], c + dC[i]);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("gates");
    cin >> n >> step;
    map<char, pair<ll ,ll>> mp{
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'W', {0, -1}},
        {'E', {0, 1}}
    };

    for(ll i = 0; i < n; i++){
        G[startR + mp[step[i]].first][startC + mp[step[i]].second] = true; 
        G[startR + 2*mp[step[i]].first][startC + 2*mp[step[i]].second] = true; 
        startR += 2*mp[step[i]].first;
        startC += 2*mp[step[i]].second;
        maxR = max(maxR, startR);
        minR = min(minR, startR);
        maxC = max(maxC, startC);
        minC = min(minC, startC);
    }

    maxR++;
    minR--;
    maxC++;
    minC--;
    
    ll ans = 0;
    for(ll i = minR; i <= maxR ; i++){
        for(ll j = minC; j <= maxC; j++){
            if(!visited[i][j] && !G[i][j]){
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans - 1 << endl;
}
