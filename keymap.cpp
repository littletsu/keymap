#include <iostream>
#include <windows.h>

int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    while(true) {
        Sleep(20);
        if(GetAsyncKeyState(VK_PAUSE)) {
            INPUT ip = {0};
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0x01;
            ip.ki.dwFlags = KEYEVENTF_SCANCODE;
            SendInput(1, &ip, sizeof(INPUT));
            Sleep(200);
            ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
    }
}
