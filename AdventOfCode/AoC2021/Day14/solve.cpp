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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n; 
    string init; cin >> init;
    map<string ,string> mp;
    for(ll i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        mp[a] = b;
    }
    
    map<string, ll> trackPair;
    for(ll i = 0; i < init.size() -1; i++){
        string curr = init.substr(i, 2);
        trackPair[curr]++;
    }
    //for(auto pi : trackPair){
        //cout << pi.first << " " << pi.second << endl;
    //}
    for(ll step = 1; step <= 40; step++){
        map<string, ll> temp;
        for(auto pi : trackPair){
            if(mp.find(pi.first) != mp.end()){
                temp[pi.first[0] + mp[pi.first]] += trackPair[pi.first];
                temp[mp[pi.first] + pi.first[1]] += trackPair[pi.first];
            }
        }
        trackPair = temp;
        cout << step << endl;
        for(auto pi : trackPair){
            cout << pi.first << " " << pi.second << endl;
            //res[pi.first[0]]++;
            //res[pi.first[1]]++;
        }
        cout << endl;
    }
   
    map<char, ll> res;
    for(auto pi : trackPair){
        cout << pi.first << " " << pi.second << endl;
        res[pi.first[0]] += trackPair[pi.first];
        res[pi.first[1]] += trackPair[pi.first];
    }
   
    res[init[0]]++;
    res[init[init.size()-1]]++;
    ll mx = (*res.begin()).second;
    ll mn = (*res.begin()).second; 
    cout << mx << " " << mn << endl;
    for(auto pi : res){
        cout << pi.first << " " << pi.second << endl;
        mx = max(pi.second, mx);
        mn = min(pi.second, mn);
    }
    cout << mx/2 - mn/2 << endl;
}
