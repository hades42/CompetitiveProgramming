ll pow(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
