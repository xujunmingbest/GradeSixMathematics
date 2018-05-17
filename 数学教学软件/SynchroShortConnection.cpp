
#include "tool.h"


/*******
同步短连接
********/

	string SynchroShortConnection::R(int rl) {
		char *buff = new char[rl];
		int lena = 0;
		while (lena < rl) {
			int templ = recv(sockClient, buff + lena, rl - lena, 0);
			if (templ == 0 || templ == -1) {
				delete[]buff;
				return "";
			}
			lena += templ;
		}
		string r(buff, rl);
		delete[]buff;
		return r;
	};

	bool SynchroShortConnection::Start(string Ip, string port) {
		//加载套接字  
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		{
			printf("Failed to load Winsock");
			return false;
		}

		SOCKADDR_IN addrSrv;
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(atoi(port.c_str()));
		addrSrv.sin_addr.S_un.S_addr = inet_addr(Ip.c_str());

		//创建套接字  
		sockClient = socket(AF_INET, SOCK_STREAM, 0);
		if (SOCKET_ERROR == sockClient) {
			printf("Socket() error: %d", WSAGetLastError());
			return false;
		}
		//向服务器发出连接请求  
		if (connect(sockClient, (struct  sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET) {
			printf("Connect failed %d", WSAGetLastError());
			return false;
		}
		return true;
	};

	void SynchroShortConnection::Destroy() {
		closesocket(sockClient);
		WSACleanup();
	}

	bool SynchroShortConnection::Connect(string Ip, string port) {
		int count = 0;
		while (!Start(Ip, port) && count <= 10)
		{
			Destroy();
			Sleep(1000);
			count++;
			if (count > 10)
			{
				return false;
			}
		}
		return true;
	};

	void SynchroShortConnection::SetTimeOut(int nNetTimeout) {
		setsockopt(sockClient, SOL_SOCKET, SO_RCVTIMEO, (char *)&nNetTimeout, sizeof(int));
	}

	bool SynchroShortConnection::Send(string &buff) {
		if (send(sockClient, buff.c_str(), buff.length(), 0) <= 0) {
			return false;
		}
		else {
			return true;
		}
	}
	string SynchroShortConnection::Recv(int recvLen) {
		return R(recvLen);
	}