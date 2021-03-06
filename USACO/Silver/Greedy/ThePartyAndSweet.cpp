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
    ll n, m; cin >> n >> m;
    vector<ll> boy(n);
    vector<ll> girl(m);
    
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> boy[i];
        sum += boy[i];
    }

    for(ll i = 0; i < m; i++){
        cin >> girl[i];
    }
    
    sum *= m;
    sort(boy.begin(), boy.end()); 
    sort(girl.begin(), girl.end());

    if(boy[n-1] > girl[0]){
        cout << -1 << endl;
        return 0;
    }

    for(ll i = 1; i < m; i++){
        sum += girl[i] - boy[n-1];
    }
    if(girl[0] != boy[n-1]){
        sum += girl[0] - boy[n-2];
    }
    
    cout << sum << endl;
}
