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
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("cardgame");
    ll N; cin >> N;
    set<ll> bessie;
    vector<ll> essie(N);
    for(ll i = 1; i <= 2*N; i++){
        bessie.insert(i);
    }
    for(ll i = 0; i < N; i++){
        cin >> essie[i];
        bessie.erase(essie[i]);
    }

    set<ll> lower_half;
    set<ll> upper_half;

    ll i = 0;
    for(auto card : bessie){
        if(i < N/2){
            lower_half.insert(card);
        } else if(i < N){
            upper_half.insert(card);
        }
        i++;
    }

    ll ans = 0;
    for(ll i = 0; i < N/2; i++){
        auto it = upper_half.upper_bound(essie[i]);
        if(it != upper_half.end()){
            ans++;
            upper_half.erase(it);
        } else{
            upper_half.erase(upper_half.begin());
        }
    }

    for(ll i = N/2; i < N; i++){
        auto it = lower_half.upper_bound(essie[i]);
        if(it != lower_half.begin()){
            it--;
            lower_half.erase(it);
            ans++;
        } else{
            lower_half.erase(prev(lower_half.end()));
        }
    }
    cout << ans << endl;
}
