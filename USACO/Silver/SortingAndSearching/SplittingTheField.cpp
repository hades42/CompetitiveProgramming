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

bool comp(pr &a, pr &b){
    return a.second < b.second;
}

vector<ll> pos(5e4);
vector<ll> X(5e4);
vector<ll> Y(5e4);

bool cmp1(ll a, ll b){
    if(X[a] == X[b]){
        return Y[a] < Y[b];
    }
    return X[a] < X[b];
}

bool cmp2(ll a, ll b){
    if(Y[a] == Y[b]){
        return X[a] < X[b];
    }
    return Y[a] < Y[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("split");
    ll n; cin >> n;

    multiset<ll> allX, allY, rightX, rightY, leftX, leftY;

    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        pos[i] = i; 
        X[i] = a;
        Y[i] = b;
        allX.insert(a);
        allY.insert(b);
    }

    ll smallX = *allX.begin();
    ll smallY = *allY.begin();
    ll bigX  = *allX.rbegin();
    ll bigY = *allY.rbegin();

    ll total = (bigX - smallX) * (bigY - smallY);
    
    ll sol = 0;
    sort(pos.begin(), pos.begin() + n, cmp1);
    for(ll trial = 0; trial <= 1; trial++){
        rightX = allX;
        rightY = allY;
        leftX.clear();
        leftY.clear();

        for(ll i = 0; i < n; i++){
            ll j = pos[i];
            ll areaL = 0;
            ll areaR = 0;

            leftX.insert(X[j]);
            leftY.insert(Y[j]);
            rightX.erase(rightX.find(X[j]));
            rightY.erase(rightY.find(Y[j]));

            smallX = *leftX.begin();
            smallY = *leftY.begin();
            bigX = *leftX.rbegin();
            bigY = *leftY.rbegin();

            areaL = (bigX - smallX) * (bigY - smallY);
    
            if(!rightX.empty()){
                smallX = *rightX.begin();
                smallY = *rightY.begin();
                bigX = *rightX.rbegin();
                bigY = *rightY.rbegin();

                areaR = (bigX - smallX) * (bigY - smallY);
            }
            //cout << sol << endl;
            sol = max(sol, total - (areaL + areaR));
        }

        sort(pos.begin(), pos.begin()+n, cmp2);
    }

    cout << sol << endl;
}
