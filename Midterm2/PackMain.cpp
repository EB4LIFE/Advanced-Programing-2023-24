#include "Pack.h"
int main() {
	Pack pack1(3);
	Pack pack2(8);
	Pack pack3(0);
	cin >> pack1;
	cin >> pack2;
	try {
		pack3 = pack1 + pack2;
	}
	catch (const char* message) {
		cout << message << endl;
	}
	cout << pack3;
	return 0;
}
