//Algo template for fast modular exponentiation: O(log Y)
ll mpow(ll x, ll y){
	ll ret = 1;
	x = x%MOD;
	while(y > 0){
		if(y & 1)
			ret = (ret*x) % MOD;
		y >>= 1;
		x = (x*x) % MOD;
	}
	return ret;
}
