// CDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC-SDI-MainFrame.h"
#include "CDlg.h"
#include "afxdialogex.h"


// CDlg 대화 상자

IMPLEMENT_DYNAMIC(CDlg, CDialogEx)

CDlg::CDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIG_CHILD, pParent)
{

}

CDlg::~CDlg()
{
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg, CDialogEx)
END_MESSAGE_MAP()


// CDlg 메시지 처리기
