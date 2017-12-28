//end of templates

mt19937_64 gen__(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(gen__); }

int main(int argc, char* argv[]) {
	if(argc != 2)
		cout << "invalid argc\n";
	int xd = atoi(argv[1]);
	cout << rd(0, xd);
	return 0;
}
