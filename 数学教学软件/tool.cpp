#include "tool.h"

bool AlarmCheck() {
	SynchroShortConnection ssc;
	ssc.Connect("47.94.219.135", "8001");
	ssc.SetTimeOut(5000);
	ssc.Send(GetMac());
	string s = ssc.Recv(7);
	if (s.length() == 0) return false;
	else if (s == "SUCCESS") {
		return true;
	}
	else if (s == "FAILED_") {
		return false;
	}
	else {
		return false;
	}
}


CControl g_c("六年级教学软件");
CControl::CControl(char *Name)
{
	hMutex1 = NULL;
	hMutex1 = CreateSemaphoreA(NULL, 0, 20, Name);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "信号量 " << Name << " 已经创建" << endl;
		exit(-1);
	}
	if (NULL == OpenSemaphoreA(SEMAPHORE_MODIFY_STATE, FALSE, Name))
	{
		printf("打开信号量对象失败 ， 错误ID：%u\n", GetLastError());
		exit(-1);
	}

}

void CControl::Stop()
{
	WaitForSingleObject(hMutex1, INFINITE);
}
void CControl::Start()
{
	long dwSem = 0;
	ReleaseSemaphore(hMutex1, 1, &dwSem);
}
CControl::~CControl()
{
	CloseHandle(hMutex1);
	hMutex1 = NULL;
	cout << "信号量销毁" << endl;
}
