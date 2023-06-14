
#include"Move.h"

const float pi = 3.14159;
void Move:: Move_Camera(float &zAlfa,float &xAlfa)
{
    static int centerX = 0;
    static int centerY = 0;
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    ShowCursor(FALSE);
    if (centerX == 0 && centerY == 0)
    {
        RECT clientRect;
        HWND hWnd = GetActiveWindow();
        GetClientRect(hWnd, &clientRect);
        centerX = clientRect.right / 2;
        centerY = clientRect.bottom / 2;
        SetCursorPos(centerX, centerY);
    }
    else if (cursorPos.x != centerX || cursorPos.y != centerY)
    {
        int deltaX = centerX - cursorPos.x;
        int deltaY = centerY - cursorPos.y;

        zAlfa += static_cast<float>(deltaX) * 0.1;
        xAlfa += static_cast<float>(deltaY) * 0.1;
        // Limit the camera's vertical rotation
        if (xAlfa < 30)
            xAlfa = 30;
        else if (xAlfa > 100)
            xAlfa = 100;

        SetCursorPos(centerX, centerY);
    }

}
void Move:: MoveHero(float& zAlfa, float& xAlfa,FLOAT &x,FLOAT &y)
{

    float ugol = -zAlfa / 180 * pi;
    if (GetAsyncKeyState('W') < 0)
    {
        x += sin(ugol) * 0.005;
       y += cos(ugol) * 0.005;
    }
    if (GetAsyncKeyState('S') < 0)
    {
        x -= sin(ugol) * 0.005;
       y -= cos(ugol) * 0.005;
    }
    if (GetAsyncKeyState('A') < 0)
    {
       x -= cos(ugol) * 0.005;
        y += sin(ugol) * 0.005;
    }
    if (GetAsyncKeyState('D') < 0)
    {
       x += cos(ugol) * 0.005;
       y -= sin(ugol) * 0.005;
    }

    glTranslatef(0, 0, -2.0);
    glRotatef(-xAlfa, 0.1, 0, 0);
    glRotatef(-zAlfa, 0, 0, 0.1);
    glTranslatef(-x, -y, 0);
}