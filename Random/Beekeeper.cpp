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

set<char> vowel;

ll get_cnt(string s){
    ll cnt = 0;
    for(ll i = 0; i < s.size() - 1; i++){
        if(vowel.count(s[i])){
            if(s[i] == s[i+1]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n;
    vowel.insert('u');
    vowel.insert('e');
    vowel.insert('o');
    vowel.insert('a');
    vowel.insert('i');
    vowel.insert('y');
    while(cin >> n && n != 0){
        ll cnt = 0;
        string ans = "";
        for(ll i = 0; i < n; i++){
            string s; cin >> s;
            ll getCnt = get_cnt(s);
            if(getCnt > cnt){
                cnt = getCnt;
                ans = s;
            }
        }
        cout << ans << endl;
    }
}
