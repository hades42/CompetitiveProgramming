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

vector<ll> pyra;
vector<ll> testCase;

void preCompute(){
    pyra.push_back(0);
    pyra.push_back(1);
    ll step = 2;
    while(pyra.back() < 3000005){
        ll temp = 2*pyra[step - 1] + step - pyra[step - 2];
        pyra.push_back(temp);
        step++;
    }
}

void solve(){
    ll need = *max_element(testCase.begin(), testCase.end());
    vector<ll> dp(need + 1, INF);
    dp[0] = 0;

    for(ll j = 1; j <= need; j++){
        for(ll i = 1; need >= pyra[i]; i++){
            if(j - pyra[i] >= 0){
                dp[j] = min(dp[j], dp[j - pyra[i]] + 1);
            }
        }
    }
    
    for(auto el : testCase){
        cout << dp[el] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    preCompute();
    while(t--){
        ll num; cin >> num;
        testCase.push_back(num);
    }
    solve();
}
