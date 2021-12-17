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
    ll desx1, desx2;
    ll desy1, desy2;
    cin >> desx1 >> desx2 >> desy1 >> desy2;
    set<pr> st;
    ll ans = 0;
    pr test;
    for(ll x = -500; x <= 500; x++){
        for(ll y = -500 ; y <= 500; y++){
            ll goX = x;
            ll goY = y;
            ll currx = 0;
            ll curry = 0;
            ll maxHeight = 0; 
            bool find = false;
            for(ll step = 0; step <= 500; step++){
                currx += goX; 
                curry += goY;
                maxHeight = max(maxHeight, curry);
                if(goX < 0){
                    goX+=1;
                } else if(goX > 0){
                    goX-=1;
                }
                goY -=1;
                if(currx >= desx1 && currx <= desx2 && curry >= desy1 && curry <= desy2){
                    //cout << currx << " " << curry << " " << maxHeight << endl;
                    find = true;
                    st.insert({x,y});
                    break;
                }
            }
            if(find){
                if(maxHeight > ans){
                    ans = maxHeight;
                    test.first = x;
                    test.second = y;
                }
                //ans = max(ans, maxHeight);
            }
        }
    }
    cout << ans << endl;
    cout << st.size() << endl;
    cout << test.first << " " << test.second << endl;
}
