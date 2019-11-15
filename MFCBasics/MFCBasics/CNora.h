#pragma once



// CNora 폼 보기

class CNora : public CFormView
{
	DECLARE_DYNCREATE(CNora)

protected:
	CNora();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CNora();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM_NORA };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


