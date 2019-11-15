#pragma once


// COptions 대화 상자

class COptions : public CDialog
{
	DECLARE_DYNAMIC(COptions)

public:
	COptions(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~COptions();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OPTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_text;
};
