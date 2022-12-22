// MyClient.cpp: 구현 파일
//

#include "pch.h"
#include "ValueClient.h"
#include "MyClient.h"
#include "ValueClientDlg.h"


// MyClient

MyClient::MyClient()
{
}

MyClient::~MyClient()
{
}


// MyClient 멤버 함수


void MyClient::OnReceive(int nErrorCode)
{
	DWORD temp_size;
	if (IOCtl(FIONREAD, &temp_size))
	{
		if (m_is_header)
		{
			if (temp_size >= sizeof(unsigned int))
			{
				Receive(&m_data_size, sizeof(unsigned int));
				m_is_header = !m_is_header;
			}
		}
		else
		{
			if (temp_size >= m_data_size)
			{
				char* pString = new char[m_data_size];
				Receive(pString, m_data_size);

				((CValueClientDlg*)AfxGetMainWnd())->AddEventString((wchar_t*)pString);
				delete[] pString;
				m_is_header = !m_is_header;
			}
		}
	}
	else
	{
		((CValueClientDlg*)AfxGetMainWnd())->AddEventString(L"수신에 문제가 있습니다.");
	}
	CSocket::OnReceive(nErrorCode);
}
