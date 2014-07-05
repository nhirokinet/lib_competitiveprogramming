class LargeInt {
	public:
		static void extgcd(long long a, long long b, long long* x, long long* y){
			if(b == 0){
				*x = 1;
				*y = 0;
				return;
			}

			extgcd(b, a%b, y, x);
			(*y) -= (a / b) * (*x);
		}

		/*
Require: extgct
		 */
		static long long mod_inverse (long long in, long long mod){
			long long x, y;
			extgcd(in, mod, &x, &y);
			if(x<0)
				x += mod * ((-x + mod) / mod);

			return x % mod;
		}

		static long long mod_pow (long long x, long long n, long long mod){
			if(n==0)
				return 1;

			if(n==1)
				return x % mod;

			long long tmp = mod_pow(x, n/2, mod);
			return (((tmp * tmp) % mod) * ((n%2) ? x: 1)) % mod;
		}

		/*
Require: mod_inverse
		 */
		static long long mod_nck (long long n, long long k, long long mod){
			long long ret = 1;
			for(long long i=(n-k+1); i<=n; i++){
				ret *= i;
				ret %= mod;
			}

			for(long long i=1; i<=k; i++){
				ret *= mod_inverse(i, mod);
				ret %= mod;
			}

			return ret;
		}

};
