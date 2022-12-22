
// ValueClientDlg.h: 헤더 파일
//

#pragma once
#include "MyClient.h"

// CValueClientDlg 대화 상자
class CValueClientDlg : public CDialogEx
{
private:
	MyClient m_client;

// 생성입니다.
public:
	CValueClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	void AddEventString(const wchar_t* ap_string)
	{
		int index = m_event_list.InsertString(-1, ap_string);
		m_event_list.SetCurSel(index);
	}

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VALUECLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSendBtn();
	CListBox m_event_list;
	afx_msg void OnBnClickedOk();
};
