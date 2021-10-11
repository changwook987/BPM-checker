#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

float milisec() {
	static clock_t s[2] = { 0, };
	static int boool = 0;
	boool = !boool;
	if (!boool) {
		s[0] = clock();
	return (float)(s[0] - s[1]) / CLOCKS_PER_SEC;
	}
	s[1] = clock();
		return (float)(s[1] - s[0]) / CLOCKS_PER_SEC;
}

int main() {
	float arr[10] = { 0, };
	int top = -1;
	while (1) {
		if (_getch()) {
			top = ++top % 10;
			arr[top] = milisec();
			float tmp = 0;
			for (int i = 0; i < 10; i++)
				tmp += arr[i];
			tmp /= 10.0f;
			gotoxy(0, 0);
			printf("%f", 60/tmp);
		}
	}
}