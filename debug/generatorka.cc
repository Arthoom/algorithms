//end of templates

mt19937_64 gen__(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(gen__); }

int main() {
	cout << rd(0, 100);
	return 0;
}