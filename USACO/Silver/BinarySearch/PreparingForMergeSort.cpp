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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<vector<ll>> ans;
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        ll left = 0; ll right = ans.size();
        while(left < right){
            ll mid = left + (right - left) / 2;
            ll last = ans[mid].back();
            if(last < num){
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        if(left == ans.size()) ans.push_back({num});
        else ans[left].push_back(num);
    }
    print2d(ans);
}
