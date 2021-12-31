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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n;
    cin >> n;
    vector<ll> pos(n);
    vector<ll> vel(n);
    for(ll i = 0; i < n; i++){
        cin >> pos[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> vel[i];
    }
    double left = 0; double right = 1e11; double ans = 1e11;
    // Binary search based on the distance 
    //for(ll i = 0; i < 200 && left < right; i++){
        //double mid = left + (right - left)/2;
        //double timeLeft = 0;
        //double timeRight = 0;
        //for(ll i = 0; i < n; i++){
            //double time = abs(mid - pos[i]) / vel[i]; 
            //if(pos[i] < mid){
                //timeLeft = max(timeLeft, time);
            //} else{
                //timeRight = max(timeRight, time);
            //}
        //}
        //ans = min(ans, max(timeLeft, timeRight));
        //// The position is leaned toward the rightside or the rightside just move wait faster
        //// so we should make that position smaller
        //if(timeLeft > timeRight){
            //right = mid;
        //} else{
            //left = mid;
        //}
    //}
    //cout << fixed << setprecision(12) << ans << endl;
    //cout << 1e-8 << endl;
    //
    // Binary search based on the time 
    for(ll i = 0; i < 200; i++){
        double mid = left + (right - left)/2; 
        double leftDis = 0;
        double rightDis = 1e11;
        for(ll i = 0; i < n; i++){
            double goLeft = pos[i] - mid * vel[i];
            double goRight = pos[i] + mid * vel[i];
            rightDis = min(rightDis, goRight);
            leftDis = max(leftDis, goLeft);
        }
        if(leftDis <= rightDis){
            ans = min(ans, mid);
            right = mid;
        } else{
            left = mid;
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}
