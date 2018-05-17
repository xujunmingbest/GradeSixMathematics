#pragma once

#include <iostream>
#include <windows.h>
using namespace std;
#pragma comment(lib,"WS2_32.lib")//显示连接套接字库



/*******
同步短连接
********/


class SynchroShortConnection {
private:
	SOCKET sockClient;

	string R(int rl);

	bool Start(string Ip, string port) ;
public:
	void Destroy();
	bool Connect(string Ip, string port);
	void SetTimeOut(int nNetTimeout);
	bool Send(string &buff);
	string Recv(int recvLen);
};

class CControl
{
	HANDLE hMutex1;
public:
	CControl(char *Name);
	void Stop();
	void Start();
	~CControl();

};
extern CControl g_c;

string GetMac();
bool AlarmCheck();
