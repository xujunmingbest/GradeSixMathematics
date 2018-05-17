
#include "tool.h"
#include <Iphlpapi.h>  
#include <iostream>  
#pragma comment(lib,"iphlpapi.lib")
using namespace std;
// ��������  
string output(PIP_ADAPTER_INFO pIpAdapterInfo);

// �������  
string GetMac()
{
	//PIP_ADAPTER_INFO�ṹ��ָ��洢����������Ϣ  
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();

	//�õ��ṹ���С,����GetAdaptersInfo����  
	unsigned long stSize = sizeof(IP_ADAPTER_INFO);

	//����GetAdaptersInfo����,���pIpAdapterInfoָ�����;����stSize��������һ��������Ҳ��һ�������  
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

///��������,���������Ϣ  
string output(PIP_ADAPTER_INFO pIpAdapterInfo)
{
	//�����ж�����,���ͨ��ѭ��ȥ�ж�
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
		//���������ж�IP,���ͨ��ѭ��ȥ�ж�  
		IP_ADDR_STRING *pIpAddrString = &(pIpAdapterInfo->IpAddressList);
		do
		{
			pIpAddrString = pIpAddrString->Next;
		} while (pIpAddrString);

		pIpAdapterInfo = pIpAdapterInfo->Next;
	}
	return string(buff, 17);
}
