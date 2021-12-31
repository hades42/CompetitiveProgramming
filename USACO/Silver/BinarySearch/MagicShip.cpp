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

ll startX, startY, x2, y2;
ll n;
string s;
vector<pr> winds; 

bool check(ll days){
    ll windsX = 0;
    ll windsY = 0;
    for(char c : s){
        if(c == 'U'){
            windsY++;
        } else if(c == 'D'){
            windsY--; 
        } else if(c == 'L'){
            windsX--;
        } else if(c == 'R'){
            windsX++;
        }
    }
    ll takeWind = days / n;
    ll remainWind = days % n;
    windsX *= takeWind;
    windsY *= takeWind;
    for(ll i = 0; i < remainWind; i++){
        if(s[i] == 'U'){
            windsY++;
        } else if(s[i] == 'D'){
            windsY--;
        } else if(s[i] == 'L'){
            windsX--;
        } else if(s[i] == 'R'){
            windsX++;
        }
    }

    ll oriX = startX + windsX;
    ll oriY = startY + windsY;
    ll need = abs(oriX - x2) + abs(oriY - y2);
    return need <= days;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> startX >> startY >> x2 >> y2;
    cin >> n;
    cin >> s;
    ll left = 0;
    ll right = 1e18;
    ll ans = -1;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(check(mid)){
            ans = mid;
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
}
