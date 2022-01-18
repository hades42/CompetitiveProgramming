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

ll n, k;

vector<pr> factor(ll num){
    map<ll ,ll> fac;
    for(ll i = 2; i * i <= num; i++){
        while(num % i == 0){
            fac[i]++;
            num /= i;
        }
    }
    if(num > 1) fac[num]++;
    vector<pr> prime_fac;
    for(auto pi : fac){
        if(pi.second % k > 0){
            prime_fac.push_back({pi.first, pi.second % k});
        }
    }
    return prime_fac;
}

vector<pr> inverse_prime(vector<pr> prime_fac){
    vector<pr> inverse(prime_fac.size());
    for(ll i = 0; i < prime_fac.size(); i++){
        inverse[i].first = prime_fac[i].first;
        inverse[i].second = k - prime_fac[i].second;
    }
    return inverse; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;

    map<vector<pr>, ll> mp;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        mp[factor(arr[i])]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(factor(arr[i]) == inverse_prime(factor(arr[i]))){
            ans += (mp[factor(arr[i])] - 1);
        } else{
            ans += mp[inverse_prime(factor(arr[i]))];
        }
    }
    
    cout << ans / 2 << endl;
}
