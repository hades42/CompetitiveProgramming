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

ll l, w;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    while(cin >> w >> l){
        if(w == 0 && l == 0){
            return 0;
        }
        ll step; cin >> step;  
        // think;
        ll aW = 0, aL = 0;
        // actual;
        ll cW = 0, cL = 0;
        for(ll i = 0; i < step; i++){
            char c; ll move;
            cin >> c >> move;
            if(c == 'u'){
                aL += move;   
                cL += move;   
                if(cL >= l){
                    cL = l - 1;
                }
            } else if(c == 'd'){
                aL -= move;
                cL -= move;
                if(cL <= 0){
                    cL = 0;
                }
            } else if(c == 'l'){
                aW -= move;
                cW -= move;
                if(cW <= 0){
                    cW = 0;
                }
            } else if(c == 'r'){
                aW += move;
                cW += move;
                if(cW >= w){
                    cW = w-1;
                }
            }
        }
        cout << "Robot thinks " << aW << " " << aL << endl;
        cout << "Actually at " << cW << " " << cL << endl;
        cout  << endl;
    }
}
