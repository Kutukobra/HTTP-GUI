#include <windows.h>

extern HWND hTextField;
extern HWND hTextArea;
extern HWND hChangeButton;

extern char buffer[256];

void onClick()
{
    GetWindowText(hTextField, buffer, sizeof(buffer));
    SetWindowText(hTextArea, buffer);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_COMMAND:
        if (LOWORD(wParam) == BN_CLICKED && (HWND)lParam == hChangeButton)
        {
            onClick();
        }
        break;

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
}