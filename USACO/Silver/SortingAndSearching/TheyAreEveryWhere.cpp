#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
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
    ll n; cin >> n;
    string input; cin >> input;
    map<char, ll> mp;
    set<char> unique;
    for(char c : input){
        unique.insert(c);
    }
    ll ans = INF;
    ll closet = 0;
    for(ll right = 0 ; right < n; right++){
        mp[input[right]]++;
        // We gonna check in the map to know whether the leftside is already exist in the map and whether we have more than 1.
        // If the first one in our range right now having more than one (mean it also exists in between the range somewhere)
        // there is no need to incude the first one
        while(closet + 1 <= right && mp.count(input[closet]) && mp[input[closet]] > 1){
            mp[input[closet]]--;
            closet++;
        }

        if(unique.size() == mp.size()){
            ans = min(ans, right - closet+ 1);
        }
    }
    cout << ans << endl;
}
