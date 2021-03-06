////////////////////////////////////////////////////////////////////////////////////
// Purpose: Demonstrates a Windows 10 (build 16299 and later) cursor behavior 
//          anomaly. In short, using SetCursorPos() seems to be failing to notify
//          the underlying application of motion when the cursor is overhead. 
//
//          The behaviour is exhibited in multiple applications, when the cursor 
//          motion is being driven by SetCursorPos(). 
//
//          Examples:
//          1) Click + Drag of a card in Spider Solitaire
//          2) Click + Drag to highlight text in the Edge Browser
//          3) Simple cursor motion above start menu items: The tiles 
//             and icons fail to light up, or only do so with a long delay.
//
// Of Note: Running the application with administrative rights makes no difference
//          so the issue is unlikely related to security or access rights.
//
// Tested Versions: 
//          [Bug NOT present]   Windows 10 build 15063
//          [Bug first present] Windows 10 build 16299
//          [Bug still present] Windows 10 build 17133
//          [Bug still present] Windows 10 build 17134
//          [Bug NOT present] Windows 7 
//          [Bug NOT present] Windows 8.1 
// Target:  Release - x86
// Contact: Benjamin Gottemoller
// Date:    April 21st, 2018
//  
// Video Demonstration of the bug:
// https://youtu.be/zEXPD18zE1s
// 
// Bug reported to: https://developer.microsoft.com/en-us/microsoft-edge/platform/issues/17124228/
//
////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

/* Added simply to see if running the message pump helps. It makes no difference. */
void run_message_pump(void)
{
    MSG message;
    if (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}

int main()
{
    bool  key_esc;
    bool  key_left;
    bool  key_right;
    bool  key_up;
    bool  key_down;
    bool  key_capslock;

    bool  needs_update;
    POINT cursor_pos;
    POINT cursor_pos_prev;

    GetCursorPos(&cursor_pos);
    cursor_pos_prev = cursor_pos;

    printf_s("This programs moves the cursor via SetCursorPos() to demonstrate a problem in Windows 10.\n\n");
    printf_s("Starting the cursor at (%d,%d)\n"
             "  -->Use the arrow keys to move the cursor.\n"
             "  -->Use CAPSLOCK to toggle the Windows message pump.\n"
             "  -->Press ESC to quit.\n\n", 
             (int)cursor_pos.x, 
             (int)cursor_pos.y);
    printf_s("On Windows 10 starting with build 16299 and still present in build 17134, "
             "moving the cursor around over certain items, such as the start menu tiles, "
             "will lack hover effects. The items underneath will not light-up, or if they "
             "do it will be after a long delay.\n\n");
    printf_s("Another example of this bug: \nOpen Spider Solitaire. Position the cursor over a card. "
             "Hold down the left mouse button, and begin moving the cursor using the arrow keys. "
             "This should simulate click+drag and begin moving the card. Instead it seems to "
             "stutter, only moving in skips and hops sometimes.\n\n");

    printf_s("Press Enter to start!\n");
    while (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
    {
        /* Wait to start */
    }

    while (true)
    {
        key_esc         = ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) > 0);
        key_capslock    = ((GetKeyState(VK_CAPITAL) & 0x0001) > 0);
        key_left        = ((GetAsyncKeyState(VK_LEFT) & 0x8000) > 0);
        key_right       = ((GetAsyncKeyState(VK_RIGHT) & 0x8000) > 0);
        key_up          = ((GetAsyncKeyState(VK_UP) & 0x8000) > 0);
        key_down        = ((GetAsyncKeyState(VK_DOWN) & 0x8000) > 0);
        needs_update    = false;

        if (key_esc)
        {
            break;
        }

        if (key_capslock)
        {
            printf_s(".");
            run_message_pump();
        }

        if (key_left)
        {
            cursor_pos.x -= 3;
            needs_update = true;
        }

        if (key_right)
        {
            cursor_pos.x += 3;
            needs_update = true;
        }

        if (key_up)
        {
            cursor_pos.y -= 3;
            needs_update = true;
        }

        if (key_down)
        {
            cursor_pos.y += 3;
            needs_update = true;
        }

        if (needs_update)
        {
            /* This is the heart of it: We are driving the cursor using this function to show
               that underlying windows do not seem to be responding to cursor hover consistently.
               It is almost like WM_MOUSEMOVE is not being received by whatever has the focus 
               (for certain apps like solitaire, or the start ment or Edge). */
            SetCursorPos(cursor_pos.x, cursor_pos.y);
            printf_s("Moving via arrow keys + WINAPI SetCursorPos(%d, %d)\n", cursor_pos.x, cursor_pos.y);
        }
        else
        {
            cursor_pos_prev = cursor_pos;
            GetCursorPos(&cursor_pos);
            /* Only print if the cursor is moving */
            if ((cursor_pos.x != cursor_pos_prev.x) &&
                (cursor_pos.y != cursor_pos_prev.y))
            {
                printf_s("Moving via physical mouse (%d,%d)\n", cursor_pos.x, cursor_pos.y);
            }
        }

        Sleep(5);
    }

    return 0;
}
