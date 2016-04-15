#include <byte.h>

void on(byte &b, int pos) {
	b |= (0x01 << pos);
}

void off(byte &b, int pos) {
	b &= ~(0x01 << pos);
}

bool getbit(byte b, int pos) {
	return b & (0x01 << pos);
}

string byteToString(byte b) {
	string cadena = "";
	for (byte i = 0x80; i > 0; i >>= 1)
		b & i? cadena += '1' : cadena += '0';
	return cadena;
}

void encender(byte &b) {
	b = 0xFF;
}

void apagar(byte &b) {
	b = 0x00;
}

void asignar(byte &b, const bool v[]) {
	for (int i = 0; i < 8; ++i)
		v[7 - i]? on(b, i) : off(b, i);
}

void volcar(byte b, bool v[]) {
	for (int i = 0; i < 8; ++i)
		v[7 - i] = getbit(b, i);
}

void encendidos(byte b, int posic[], int &cuantos) {
	cuantos = 0;
	for (int i = 0; i < 8; ++i)
		if (getbit(b, i)) posic[cuantos++] = i;
}
