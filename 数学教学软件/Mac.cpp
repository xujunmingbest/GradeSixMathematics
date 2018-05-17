
#include "tool.h"
#include <Iphlpapi.h>  
#include <iostream>  
#pragma comment(lib,"iphlpapi.lib")
using namespace std;
// 函数声明  
string output(PIP_ADAPTER_INFO pIpAdapterInfo);

// 程序入口  
string GetMac()
{
	//PIP_ADAPTER_INFO结构体指针存储本机网卡信息  
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();

	//得到结构体大小,用于GetAdaptersInfo参数  
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);

	//调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量;其中stSize参数既是一个输入量也是一个输出量  
	int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);

	if (ERROR_BUFFER_OVERFLOW == nRel)
	{
		delete pIpAdapterInfo;
		pIpAdapterInfo = NULL;
		pIpAdapterInfo = (PIP_ADAPTER_INFO) new BYTE[stSize];

		nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
	}
	string out;
	if (ERROR_SUCCESS == nRel)
	{
		out = output(pIpAdapterInfo);
	}
	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}

	return out;
}

///函数作用,输出网卡信息  
string output(PIP_ADAPTER_INFO pIpAdapterInfo)
{
	//可能有多网卡,因此通过循环去判断
	char buff[18]; memset(buff, 0x00, sizeof(buff));
	if (pIpAdapterInfo)
	{
		for (UINT i = 0; i < pIpAdapterInfo->AddressLength; i++)
		{
			if (i == pIpAdapterInfo->AddressLength - 1)
			{
				snprintf(buff + i * 3, 3, "%02x\n", pIpAdapterInfo->Address[i]);
			}
			else
			{
				snprintf(buff + i * 3, 4, "%02x-", pIpAdapterInfo->Address[i]);
			}
		}
		//可能网卡有多IP,因此通过循环去判断  
		IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
		do
		{
			pIpAddrString = pIpAddrString->Next;
		} while (pIpAddrString);

		pIpAdapterInfo = pIpAdapterInfo->Next;
	}
	return string(buff, 17);
}
