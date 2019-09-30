//Algo template for fast exponentiation, watch out for integer overflow!: O(log Y)
ll fpow(ll x, ll y){
	ll ret = 1, tmp;
	while(y > 0){
		if(y & 1)
			ret = ret*x;
		y >>= 1;	
		x = x*x;
	}
	return ret;
}
