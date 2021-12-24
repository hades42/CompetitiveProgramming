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
    //setIO("berries");
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    multiset<ll> essie;
    multiset<ll> bessie;
    for(ll i = 0; i < k/2; i++){
        essie.insert(arr[i]);
    }
    ll i = k/2;
    while(true){
        ll big = *prev(essie.end());
        if(big/2 >= arr[i]){
            essie.erase(essie.find(big));
            if(big % 2 == 0){
                essie.insert(big/2);
                bessie.insert(big/2);
            } else{
                essie.insert(big/2+1);
                bessie.insert(big/2);
            }
        } else{
            bessie.insert(arr[i]);
            i++;
        }
        if(bessie.size() == k/2) break;
    }
    ll ans = 0;
    for(auto val : essie){
        cout << val << endl;
    }
    for(auto val : bessie){
        cout << val << endl;
        ans += val;
    }
    cout << ans << endl;
}
