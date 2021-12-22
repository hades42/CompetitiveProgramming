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
    setIO("measurement");
    ll n, g; cin >> n >> g;
    vector<vector<ll>> arr(n);
    for(ll i = 0; i < n; i++){
        ll day, id, milk;
        cin >> day >> id >> milk;
        arr[i] = vector<ll>{day, id, milk};
    }
    sort(arr.begin(), arr.end());
    ll ans = 0; ll maxMilk = 0; ll cnt = 0;
    multiset<ll> track;
    map<ll,ll> mem;
    for(ll i = 0; i < n; i++){
        mem[i+1] = 0;
        track.insert(0);
    }
    for(ll i = 0; i < n; i++){
        auto mes = arr[i];
        ll oldmilk = mem[mes[1]];
        ll admilk = mes[2];
        track.erase(track.find(oldmilk));
        mem[mes[1]] += admilk;
        track.insert(mem[mes[1]]);
        if(mem[mes[1]] > maxMilk){
            if(cnt != 1 || maxMilk != oldmilk){
                ans++;
            }
            cnt = 1;
            maxMilk = mem[mes[1]];
        } else if(mem[mes[1]] == maxMilk){
            cnt++;
            ans++;
        } else if(oldmilk == maxMilk){
            maxMilk = *track.rbegin();
            ll wascnt = cnt;
            cnt = track.count(maxMilk);
            if(cnt != 1 || wascnt != 1 || mem[mes[1]] != maxMilk){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
