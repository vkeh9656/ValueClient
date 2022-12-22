#pragma once

// MyClient 명령 대상

class MyClient : public CSocket
{
private:
	char m_is_header = 1;
	unsigned int m_data_size;

public:
	MyClient();
	virtual ~MyClient();
	virtual void OnReceive(int nErrorCode);
};


