#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1e18;
using namespace std;

template<typename T>
void print(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}

template<typename T>
void print2d(const T& t) {
    std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

const ll maxSize = 100100;
bool primes[maxSize];
void precompute(){
	fill(primes, primes + maxSize, true);
	primes[0] = false;
	primes[1] = false;
	for(ll i = 2; i*i < maxSize; i++){
		if(primes[i]){
			for(ll j = i + i; j < maxSize; j+= i){
				primes[j] = false;
			}
		}
	}
}

int main() {
	string in; cin >> in;
	ll result = 0;
	set<char> s; 
	for(ll i = 0; i < in.size(); i++){
		for(ll j = i+1; j < in.size(); j++){
			if(in[i] == in[j]) break;
			if(!s.count(in[j])){
				s.insert(in[j]);
				result++;
			}
		}
		s.clear();
	}
	cout << result << endl;
}