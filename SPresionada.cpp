#include <conio.h>

bool SPresionada() {
	bool presionada = false;
	while (_kbhit()) {
		char c = _getch();
		if (c == 'S' || c == 's') {
			presionada = true;
		}
	}
	return presionada;
}
