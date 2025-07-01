#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(hInput, &mode);
    SetConsoleMode(hInput, (mode | ENABLE_MOUSE_INPUT) & ~ENABLE_QUICK_EDIT_MODE); 

    printf("Click anywhere inside the console...\nPress 'q' to quit.\n");

    INPUT_RECORD input;
    DWORD events;
    COORD pos;

    while (1) {
        ReadConsoleInput(hInput, &input, 1, &events);

        if (input.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mer = input.Event.MouseEvent;

            if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) { 
                pos = mer.dwMousePosition;
                printf("Clicked at: X=%d, Y=%d\n", pos.X, pos.Y);
            }
        }
        else if (input.EventType == KEY_EVENT) {
            if (input.Event.KeyEvent.bKeyDown && input.Event.KeyEvent.wVirtualKeyCode == 'Q') {
                break; 
            }
        }
    }

    return 0;
}

