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

struct Event{
    ll time;
    ll id;
    ll isActive;
};

bool comp(Event &a, Event &b){
    return a.time < b.time; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("lifeguards");
    ll n; cin >> n;
    vector<Event> arr;
    for(ll i = 0; i < n; i ++){
        ll l, r; cin >> l >> r;
        struct Event start = {l,i,1};
        struct Event end = {r,i,0};
        arr.push_back(start);
        arr.push_back(end);
    }
    sort(arr.begin(), arr.end(), comp);

    ll totalTime = 0;
    ll prevTime = 0;

    vector<ll> aloneTime(n, 0);

    set<ll> currCow;

    for(ll i = 0; i < arr.size(); i++){
        auto curr = arr[i];
        
        if(currCow.size() > 0){
            totalTime += curr.time - prevTime;
        }

        if(currCow.size() == 1){
            aloneTime[*currCow.begin()] += curr.time - prevTime;
        }

        if(curr.isActive){
            currCow.insert(curr.id);
        } else{
            currCow.erase(curr.id);
        }

        prevTime = curr.time;
    }
    ll minAlone = INF;
    for(ll i = 0; i < n; i++){
        minAlone = min(minAlone, aloneTime[i]);
    }
    cout << totalTime  - minAlone << endl;
}
