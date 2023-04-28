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

bool check(int n, int cRow, int cColumn){
    return cRow >= 0 && cRow < n && cColumn >= 0 && cColumn < n;
}

int countOperations(int num1, int num2) {
    int temp1 = num1;
    int temp2 = num2;
    int cnt = 0;
    while(temp1 != 0 && temp2 != 0){
        while(temp1 >= temp2){
            temp1 -= temp2;
            cnt++;
            if(temp1 == 0) break;
        }    

        if(temp1 == 0 || temp2 == 0) break;

        while(temp2 > temp1){
            temp2 -= temp1;
            cnt++;
            if(temp2 == 0) break;
        }
        if(temp1 == 0 || temp2 == 0) break;
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << countOperations(2, 3) << endl;
}
