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

struct Rect{
    ll h;
    ll w;
    ll pos;
};

bool case1(Rect &a, Rect &b){
    if(a.h == b.h){
       return a.w < b.w; 
    }
    return a.h < b.h;
}

bool case2 (Rect &a, Rect &b){
    if(a.w == b.h){
        return a.h < b.w;
    } 
    return a.w < b.h;
}

void solve(){
    ll n; cin >> n;
    vector<Rect> arr;
    for(ll i = 0; i < n; i++){
        ll h, w; cin >> h >> w;
        arr.push_back({h, w, i+1});
    }
    vector<ll> front(n, -1);
    sort(arr.begin(), arr.end(), case1);
    //for(ll i = 0; i < n; i++){
        //cout << arr[i].h << " " << arr[i].w << endl;
    //}
    //cout << endl;
    ll i = 1; ll j = 0;
    while(i < n){
        cout << arr[i].h << " " << arr[i].w << " " << arr[j].h << " " << arr[j].w << endl;
        if(arr[i].h > arr[j].h && arr[i].w > arr[j].w){
            front[arr[i].pos] = arr[j].pos;
            i++;
        } else{
            j++;
        }
        if(j == i){
            break;
        }
    }
    sort(arr.begin(), arr.end(), case2);

    //for(ll i = 0; i < n; i++){
        //cout << arr[i].h << " " << arr[i].w << endl;
    //}
    //cout << endl;
    i = 1; j = 0;
    while(i < n){
        if(arr[i].h > arr[j].w && arr[i].w > arr[j].h){
            front[arr[i].pos] = arr[j].pos;
            i++;
        } else{
            j++;
        }
        if(i == j){
            break;
        }
    }
    //for(ll i = 0; i < n; i++){
        //for(ll j = 0; j < n; j++){
            //if(i == j) continue;
            //if((arr[j].h > arr[i].h && arr[j].w > arr[i].w) || (arr[j].h > arr[i].w && arr[j].w > arr[i].h)){
                //front[j] = i + 1;
            //}
        //}
    //}
    print(front);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
