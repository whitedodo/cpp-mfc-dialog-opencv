// CNora.cpp: 구현 파일
//

#include "pch.h"
#include "MFCBasics.h"
#include "CNora.h"


// CNora

IMPLEMENT_DYNCREATE(CNora, CFormView)

CNora::CNora()
	: CFormView(IDD_FORM_NORA)
{

}

CNora::~CNora()
{
}

void CNora::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNora, CFormView)
END_MESSAGE_MAP()


// CNora 진단

#ifdef _DEBUG
void CNora::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CNora::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNora 메시지 처리기
