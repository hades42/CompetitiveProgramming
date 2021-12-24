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

// Kill every thing and take the remain
ll case1(vector<ll> atk, vector<ll> def, multiset<ll> ceil){
    sort(def.begin(), def.end());
    for(ll i = 0; i < def.size(); i++){
        auto it = ceil.upper_bound(def[i]);
        if(it != ceil.end()){
            ceil.erase(it);
        } else{
            return 0;
        }
    }
    sort(atk.begin(), atk.end());
    ll ans = 0;
    for(ll i = 0; i < atk.size(); i++){
        auto it = ceil.lower_bound(atk[i]);
        if(it != ceil.end()){
            ans += *it - atk[i];
            ceil.erase(it);
        } else{
            return 0;
        }
    }
    for(auto val : ceil){
        ans += val;
    }
    return ans;
}

// Kill the attack card 
ll case2(vector<ll> atk, vector<ll> def, multiset<ll> ceil){
    sort(atk.begin(), atk.end());
    ll ans = 0;
    for(ll i = 0; i < atk.size(); i++){
        if(!ceil.size()) break;
        auto it = prev(ceil.end());
        if(*it >= atk[i]){
            ans += *it - atk[i];
            ceil.erase(it);
        } else{
            break;
        }
    }
    return ans;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m; cin >> n >> m;
    vector<ll> atk;
    vector<ll> def;
    multiset<ll> ceil;
    for(ll i = 0; i < n; i++){
        string pos; ll val;
        cin >> pos >> val;
        if(pos == "ATK"){
            atk.push_back(val);
        } else{
            def.push_back(val);
        }
    }
    for(ll i = 0; i < m; i++){
        ll num; cin >> num;
        ceil.insert(num);
    }

    ll ans = max(case1(atk, def, ceil), case2(atk, def, ceil));
    cout << ans << endl;
}
