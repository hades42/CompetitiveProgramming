#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
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

// id 1 meant for milking
// id 2 meant for renting
struct Service{
    ll qty;
    ll perMilk;
};

bool comp(Service &a, Service &b){
    return a.perMilk > b.perMilk;
}

vector<ll> produce;
vector<Service> milking; 
vector<ll> renting;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("rental");
    ll N, M, R; cin >> N >> M >> R;
    for(ll i = 0; i < N; i++){
        ll num; cin >> num;
        produce.push_back(num);
    }
    // 1 is for service that need milk
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        milking.push_back({a, b});
    }

    for(ll i = 0; i < R; i++){
        ll num; cin >> num;
        renting.push_back(num);
    }

    sort(milking.begin(), milking.end(), comp);
    sort(renting.rbegin(), renting.rend());
    sort(produce.rbegin(), produce.rend());
    //for(ll i = 0; i < milking.size(); i++){
        //cout << milking[i].qty << " " << milking[i].perMilk << endl;
    //}

    //print(renting);
    
    ll res = 0;
    ll i = 0;
    ll pro = 0;
    ll ren = 0;
    while(i < N){
        ll currLiters = produce[i];
        ll moneyT = 0;
        ll currI = pro;
        ll last = 0;
        while(currI < M){
            ll rest = min(currLiters, milking[currI].qty);
            moneyT += rest * milking[currI].perMilk;
            currLiters -= rest;

            if(currLiters == 0){
                last = rest;
                break;
            } else{
                currI++;
            }
        }
        if(ren >= R || renting[ren] < moneyT){
            res += moneyT;
            pro = currI;
            if(pro < M) milking[pro].qty -= last;
            i++;
        } else{
            res += renting[ren];
            N--;
            ren++;
        }
    }
    cout << res << endl; 
}
