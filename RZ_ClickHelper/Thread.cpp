#include "pch.h"
#include "Thread.h"

ClickThread::ClickThread()
{
	APP = true;
	_beginthreadex(nullptr, 0, this->Thread, this, 0, nullptr);
}

ClickThread::~ClickThread()
{
	APP = false;
}

unsigned int __stdcall ClickThread::Thread(void* pM)
{
	ClickThread* Self = (ClickThread*)pM;
	while (Self->APP)
	{
		Sleep(1);
		if (continuousclick)
		{
			SetCursorPos(addpoint.x, addpoint.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(1);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
        if (GetAsyncKeyState(VK_F1) && 0x8000)
        {
            continuousclick = true;
            //SetCursorPos(addpoint.x, addpoint.y);
            //mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            //Sleep(1);
            //mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (GetAsyncKeyState(VK_F2) && 0x8000)
        {
            continuousclick = false;
            SetCursorPos(outpoint.x, outpoint.y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(1);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(10);//不知道反应时间
            SetCursorPos(numberpoint.x, numberpoint.y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(1);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (GetAsyncKeyState(VK_F3) && 0x8000)
        {
            continuousclick = false;
            SetCursorPos(testpoint.x, testpoint.y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(1);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (GetAsyncKeyState(VK_F4) && 0x8000)
        {
            continuousclick = false;
        }
	}
	return 0;
}
