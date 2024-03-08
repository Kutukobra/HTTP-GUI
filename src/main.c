// Muhammad Nadzhif Fikri (2306210102)
// 

#include <windows.h>
#include "extraFunctions.h"

extern HWND hTextField;
extern HWND hTextArea;
extern HWND hChangeButton;

extern char buffer[256];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              
        CLASS_NAME, 
        "Text field and area",              
        WS_OVERLAPPEDWINDOW,            

        CW_USEDEFAULT, CW_USEDEFAULT, 1800, 350,

        NULL,
        NULL,
        hInstance,
        NULL 
    );

    if (hwnd == NULL) {
        return 0;
    }

    hTextField = CreateWindowEx(
        WS_EX_CLIENTEDGE,               
        "EDIT",                         
        "",                             
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
        10, 10, 800, 280,                
        hwnd,                           
        NULL,                           
        hInstance,                      
        NULL
    );

    if (hTextField == NULL) {
        return 0;
    }

    hTextArea = CreateWindowEx(
        WS_EX_CLIENTEDGE,               
        "STATIC",                         
        "",                             
        WS_CHILD | WS_VISIBLE,
        970, 10, 800, 280,                
        hwnd,                           
        NULL,                           
        hInstance,                      
        NULL
    );

    if (hTextArea == NULL) {
        return 0;
    }

    hChangeButton = CreateWindowEx(
        WS_EX_CLIENTEDGE,               
        "BUTTON",                         
        "CHANGE FIELD",                             
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        820, 95, 130, 100,                
        hwnd,                           
        NULL,                           
        hInstance,                      
        NULL
    );


    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

