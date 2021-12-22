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

vector<pair<ll,ll>> ans;
vector<ll> arr;
ll n;

bool check(ll init){
    ans.clear();
    multiset<ll> ms;
    for(ll i = 0; i < 2*n; i++){
        ms.insert(arr[i]);
    }
    while(ms.size()){
        ll curr = *ms.rbegin();
        ms.erase(ms.find(curr));

        if(ms.find(init - curr) == ms.end()){
            return false;
        } else{
           ms.erase(ms.find(init - curr));
           ans.push_back({curr, init - curr}); 
           init = curr;
        }
    }

    //for(auto pi : ans){
        //cout << pi.first << " " << pi.second << endl;
    //}

    return ms.empty();
}

void solve(){
    cin >> n;
    arr.resize(n*2);
    for(ll i = 0; i < 2*n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(ll i = 0; i < arr.size() - 1; i ++){
        ll init_sum = arr[arr.size() - 1] + arr[i];
        if(check(init_sum)){
            cout << "YES" << endl;
            cout << init_sum << endl;
            for(auto pi : ans){
                cout << pi.first << " " << pi.second << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
