#pragma once

class ClickThread
{
public:
	ClickThread();
	~ClickThread();
private:
	bool APP;
	static unsigned int __stdcall Thread(void* pM);
};