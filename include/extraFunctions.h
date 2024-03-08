#ifndef EXTRA
#define EXTRA
#include <windows.h>

HWND hTextField;
HWND hTextArea;
HWND hChangeButton;

char buffer[256];

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void onClick();
#endif