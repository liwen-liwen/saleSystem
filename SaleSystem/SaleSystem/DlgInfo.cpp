// DlgInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DlgInfo.h"
#include "InfoFile.h"

// CDlgInfo

IMPLEMENT_DYNCREATE(CDlgInfo, CFormView)

CDlgInfo::CDlgInfo()
	: CFormView(CDlgInfo::IDD)
{

}

CDlgInfo::~CDlgInfo()
{
}

void CDlgInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CDlgInfo, CFormView)
END_MESSAGE_MAP()


// CDlgInfo ���

#ifdef _DEBUG
void CDlgInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgInfo ��Ϣ�������


void CDlgInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	//�����б�ķ��
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//���ñ�ͷ
	CString head[] = { TEXT("��ƷID"), TEXT("��Ʒ����"), TEXT("��Ʒ�۸�"), TEXT("�������") };
	m_list.InsertColumn(0, head[0], LVCFMT_CENTER, 100);
	m_list.InsertColumn(1, head[1], LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, head[2], LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, head[3], LVCFMT_CENTER, 100);

	//�����б�����

	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//����Ʒ����ӵ�combox
	int i = 0;
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		//�����һ���ڵ�ȷ��һ��
		CString sid;
		sid.Format(TEXT("%d"), it->id);
		m_list.InsertItem(i, sid);

		int j = 0;
		//���뱾����������
		m_list.SetItemText(i, ++j, CString(it->name.c_str()));
		sid.Format(TEXT("%d"), it->price);
		m_list.SetItemText(i, ++j, sid);
		sid.Format(TEXT("%d"), it->num);
		m_list.SetItemText(i, ++j, sid);
		i++;
	}
	//�����ͷ�
	info.ls.clear();
}
