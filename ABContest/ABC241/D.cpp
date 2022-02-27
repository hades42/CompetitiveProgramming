#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    multiset<ll> st;
    ll q; cin >> q;
    while(q--){
        ll c; cin >> c;
        if(c == 1){
            ll num; cin >> num;
            st.insert(num);
        } else if(c == 2){
            ll num, k; cin >> num >> k;
            auto curr = st.upper_bound(num);
            ll ans = -1;
            while(true){
                if(k == 0){
                    ans = *curr; 
                    break;
                }
                if(curr == st.begin()){
                    break;
                }
                curr--;
                k--;
            }
            cout << ans << endl;
        } else {
            ll num, k; cin >> num >> k;
            auto curr = st.lower_bound(num);
            ll ans = -1;
            while(true){
                if(curr == st.end()){
                    break;
                }
                if(k == 1){
                    ans = *curr;
                    break;
                }
                curr++;
                k--;
            }
            cout << ans << endl;
        }
    }
}
