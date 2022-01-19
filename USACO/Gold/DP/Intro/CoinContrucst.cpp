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
    ll n; ll target;
    cin >> n >> target;
    vector<ll> coin(n);
    vector<ll> value(target+1, INF);
    vector<ll> first(target+1);

    for(ll i = 0; i < n; i++){
        cin >> coin[i];
    }

    value[0] = 0;
    for(ll i = 1; i <= target; i++){
        for(ll c : coin){
            if(i - c >= 0 && value[i - c] + 1 < value[i]){
                value[i] = value[i - c] + 1;
                first[i] = c;
            }
        }
    }

    print(value);
    print(first);
    while(target > 0){
        cout << first[target] << " ";
        target -= first[target];
    }
}
