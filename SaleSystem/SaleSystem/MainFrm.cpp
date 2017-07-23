
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "SaleSystem.h"

#include "MainFrm.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "DlgPerson1.h"
#include "DlgSell.h"
#include "DlgInfo.h"
#include "DlgAdd.h"
#include "DlgDel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

//��Ϣӳ����ڶ���
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//����ͼ��
	//GetClassLong(m_hWnd, (LONG)AfxGetApp()->LoadIcon(IDI_ICON1));
	SetClassLong(m_hWnd,GCL_HICON, (LONG)AfxGetApp()->LoadIcon(IDI_ICON2));


	//���ô�����ʾλ�úʹ�С
	MoveWindow(100, 50, 900, 600);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������


//��ִ���
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  �ڴ����ר�ô����/����û���
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	
	//��̬���
	m_splitter.CreateStatic(this, 1, 2);

	//��ִ���
	m_splitter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(240, 600),pContext);
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(660, 600), pContext);


	return TRUE;
}
//�Զ���ӳ����Ϣ��������ʵ��
LRESULT CMainFrame::OnMyChange(WPARAM wparam, LPARAM lparam)
{
	CCreateContext Context;
	switch (wparam)
	{
	case NM_A:
	{
		//CUserDlg����Ҫ����ͷ�ļ�#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgPerson1);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgPerson1), CSize(600, 0), &Context);
		CDlgPerson1 *pNewView = (CDlgPerson1 *)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
		break;
	case NM_B:
	{
		//CUserDlg����Ҫ����ͷ�ļ�#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgSell);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgSell), CSize(600, 0), &Context);
		CDlgSell *pNewView = (CDlgSell *)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
		break;
	case NM_C:
	{
		//CUserDlg����Ҫ����ͷ�ļ�#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgInfo);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgInfo), CSize(600, 0), &Context);
		CDlgInfo *pNewView = (CDlgInfo *)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}		
		break;
	case NM_D:
	{
		//CUserDlg����Ҫ����ͷ�ļ�#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgAdd);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgAdd), CSize(600, 0), &Context);
		CDlgAdd *pNewView = (CDlgAdd *)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}		
		break;
	case NM_E:
	{
		//CUserDlg����Ҫ����ͷ�ļ�#include "UserDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgDel);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_splitter.GetPane(0, 1);
		m_splitter.DeleteView(0, 1);
		m_splitter.CreateView(0, 1, RUNTIME_CLASS(CDlgDel), CSize(600, 0), &Context);
		CDlgDel *pNewView = (CDlgDel *)m_splitter.GetPane(0, 1);
		m_splitter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_splitter.SetActivePane(0, 1);
	}
	break;
	default:
		break;
	}

	return 0;
}

