
// MFCBasicsView.cpp: CMFCBasicsView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCBasics.h"
#endif

#include "MFCBasicsDoc.h"
#include "MFCBasicsView.h"

#include "COptions.h"
#include "CNora.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCBasicsView

IMPLEMENT_DYNCREATE(CMFCBasicsView, CView)

BEGIN_MESSAGE_MAP(CMFCBasicsView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TOOL_OPTIONS, &CMFCBasicsView::OnToolOptions)
	ON_COMMAND(ID_TOOLS_NORA, &CMFCBasicsView::OnToolsNora)
END_MESSAGE_MAP()

// CMFCBasicsView 생성/소멸

CMFCBasicsView::CMFCBasicsView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCBasicsView::~CMFCBasicsView()
{
}

BOOL CMFCBasicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCBasicsView 그리기

void CMFCBasicsView::OnDraw(CDC* /*pDC*/)
{
	CMFCBasicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMFCBasicsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCBasicsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCBasicsView 진단

#ifdef _DEBUG
void CMFCBasicsView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCBasicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCBasicsDoc* CMFCBasicsView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCBasicsDoc)));
	return (CMFCBasicsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCBasicsView 메시지 처리기


void CMFCBasicsView::OnToolOptions()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 모달 있는 상태
	COptions dlgOptions(this);
	dlgOptions.DoModal();		
	
	// 모달 없는 상태
	//COptions dlgOptions = new COptions;
	//dlgOptions.Create(IDD_DIALOG_OPTIONS);
	//dlgOptions.ShowWindow();

}


void CMFCBasicsView::OnToolsNora()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
