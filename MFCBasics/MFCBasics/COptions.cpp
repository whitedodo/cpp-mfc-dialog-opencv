// COptions.cpp: 구현 파일
//

#include "pch.h"
#include "MFCBasics.h"
#include "COptions.h"
#include "afxdialogex.h"


// COptions 대화 상자

IMPLEMENT_DYNAMIC(COptions, CDialog)

COptions::COptions(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_OPTIONS, pParent)
	, m_text(_T("Enter text"))
{

}

COptions::~COptions()
{
}

void COptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(COptions, CDialog)
END_MESSAGE_MAP()


// COptions 메시지 처리기
