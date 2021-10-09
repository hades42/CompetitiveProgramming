const ll maxSize = 100100;
bool primes[maxSize];
vector<ll> primes_list;
void precompute() {
  fill(primes, primes + maxSize, true);
  primes[0] = false;
  primes[1] = false;
  for (ll i = 2; i * i < maxSize; i++) {
    if (primes[i]) {
      for (ll j = i + i; j < maxSize; j += i) {
        primes[j] = false;
      }
    }
  }
}

vector<ll> factors(ll n) {
  vector<ll> ans;
  for (ll i = 0; primes_list[i] * primes_list[i] <= n && i < primes_list.size();
       i++) {
    if (n % primes_list[i] == 0) {
      while (n % primes_list[i] == 0) {
        n = n / primes_list[i];
        ans.push_back(primes_list[i]);
      }
    }
  }
  if (n > 1) {
    ans.push_back(n);
  }
  sort(ans.begin(), ans.end());
  return ans;
}
