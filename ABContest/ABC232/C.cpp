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
    map<ll , set<ll>> taka;
    map<ll, set<ll>> aoki;
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        taka[a].insert(b);
        taka[b].insert(a);
    }

    for(ll i = 0; i < m; i++){
        ll c, d;
        cin >> c >> d;
        aoki[c].insert(d);
        aoki[d].insert(c);
    }

    vector<ll> P;
    for(ll i = 1; i <= n; i++){
        P.push_back(i);
    }

    do{
        //print(P);
        bool flag = true; 
        for(ll i = 0; i < n-1; i++){
            for(ll j = i + 1; j < n; j++){
                bool check1 = taka[i+1].count(j+1); 
                bool check2 = aoki[P[i]].count(P[j]);
                //cout << check1 << " " << check2 << endl;
                if(check1 == check2){
                    continue;
                } else{
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            //print(P);
            return 0;
        }
    } while(next_permutation(P.begin(), P.end()));
    
    cout << "No" << endl;
    return 0;
}
