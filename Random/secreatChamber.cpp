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
vector<bool> seen;

void dfs(ll c){
    seen[c] = true;
    for(auto v : G[c]){
        if(!seen[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll m, n; cin >> m >> n;
    G.resize(26);
    for(ll i = 0; i < m; i++){
        char a, b; cin >> a >> b;
        G[a - 'a'].push_back(b - 'a');
    }
    //print2d(G);
    for(ll i = 0; i < n; i++){
        string s1, s2; cin >> s1 >> s2;
        if(s1.length() != s2.length()){
            cout << "no" << endl;
            continue;
        } 
        
        bool flash1 = true;
        for(ll i = 0; i < s1.length(); i++){
            vector<bool> temp(26);
            seen = temp;
            dfs(s1[i] - 'a');
            if(!seen[s2[i] - 'a']){
                flash1 = false; 
                break;
            }
        }

        if(flash1){
            cout << "yes" << endl;
        } else{
            cout << "no" << endl;
        }
    }
}
