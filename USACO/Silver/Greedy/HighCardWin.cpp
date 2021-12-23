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
    setIO("highcard");
    ll N; cin >> N;
    vector<ll> arr(N);
    set<ll> st;
    for(ll i = 0; i < N; i++){
        cin >> arr[i];
        st.insert(arr[i]);
    }
    sort(arr.begin(), arr.end());
    set<ll> Bessie;
    for(ll i = 1; i <= 2*N; i++){
        if(st.count(i)) continue;
        Bessie.insert(i);
    }
    //for(auto val : Bessie){
        //cout << val << endl;
    //}
    ll ans = 0;
    for(ll i = 0 ; i < N; i++){
        auto it = Bessie.upper_bound(arr[i]);
        if(it == Bessie.end()){
            break;
        }
        ans++;
        Bessie.erase(it);
    }
    cout << ans << endl;
}
