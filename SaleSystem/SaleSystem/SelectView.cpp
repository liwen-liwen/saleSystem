// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "SelectView.h"
#include "MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������


//�������ͼ
void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//����ͼ��
	HICON hicon = AfxGetApp()->LoadIconW(IDI_ICON1);

	//����ͼ���б�
	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);

	//��ͼ����ص�ͼ���б���
	m_imageList.Add(hicon);
	//��ȡ���ؼ�
	m_tree = &GetTreeCtrl();

	//��ͼ���б���ص����ؼ���
	m_tree->SetImageList(&m_imageList, TVSIL_NORMAL);

	//�����ڵ�
	m_tree->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_tree->InsertItem(TEXT("���۹���"), 0, 0, NULL);
	m_tree->InsertItem(TEXT("�����Ϣ"), 0, 0, NULL);
	m_tree->InsertItem(TEXT("�������"), 0, 0, NULL);
	m_tree->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);



}


//ѡ����Ӧ
void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM item = m_tree->GetSelectedItem();

	//��ȡ�ڵ���
	CString str = m_tree->GetItemText(item);

	//������Ϣ
	if (str == TEXT("������Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
		return;
	}
	else if (str == TEXT("���۹���"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
		return;
	}
	else if (str == TEXT("�����Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
		return;
	}
	else if (str == TEXT("�������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
		return;
	}
	else if (str == TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
		return;
	}

	*pResult = 0;


}
