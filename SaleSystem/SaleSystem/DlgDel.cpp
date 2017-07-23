// DlgDel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DlgDel.h"
#include "InfoFile.h"

// CDlgDel

IMPLEMENT_DYNCREATE(CDlgDel, CFormView)

CDlgDel::CDlgDel()
	: CFormView(CDlgDel::IDD)
	, m_price(0)
	, m_num(0)
{

}

CDlgDel::~CDlgDel()
{
}

void CDlgDel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PRICE3, m_price);
	DDX_Text(pDX, IDC_EDIT_NUM3, m_num);
	DDX_Control(pDX, IDC_COMBO3, m_comb);
}

BEGIN_MESSAGE_MAP(CDlgDel, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_ADD1, &CDlgDel::OnBnClickedButtonAdd1)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL1, &CDlgDel::OnBnClickedButtonCancel1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDlgDel::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// CDlgDel ���

#ifdef _DEBUG
void CDlgDel::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgDel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgDel ��Ϣ�������


void CDlgDel::OnBnClickedButtonAdd1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(_T("��������Ϊ��"));
		return;
	}

	//���������Ϣ
	int index = m_comb.GetCurSel();
	CString str;
	m_comb.GetLBText(index, str);

	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	int lastnum = 0;
	//������Ʒ�޸�ʣ������
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		if (str == (CString(it->name.c_str())))
		{
			if (m_num > it->num)
			{
				m_num = it->num;
				
			}
			it->num = it->num - m_num;

			lastnum = it->num;
			//��д����
			info.WirteDocline();
		}

	}
	//�����ͷ�
	info.ls.clear();

	CString delinfo;
	delinfo.Format(TEXT("�ɹ�ɾ����Ʒ\r\n��Ʒ����%s\r\n���ۣ�%d\r\nʣ��������%d\r\n"), str, m_price, m_num, lastnum);
	MessageBox(delinfo);

	m_num = 0;

	UpdateData(FALSE);
}


void CDlgDel::OnBnClickedButtonCancel1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num = 0;

	UpdateData(FALSE);
}


void CDlgDel::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//����Ʒ����ӵ�combox
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		m_comb.AddString(CString(it->name.c_str()));

	}
	//�����ͷ�
	info.ls.clear();

	//Ĭ��ѡ�е�һ����Ʒ
	m_comb.SetCurSel(0);
	OnCbnSelchangeCombo3();
	m_num = 0;
	UpdateData(FALSE);
}


void CDlgDel::OnCbnSelchangeCombo3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = m_comb.GetCurSel();
	CString str;
	m_comb.GetLBText(index, str);

	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//����Ʒ����ӵ�combox
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		if (str == (CString(it->name.c_str())))
		{
			m_price = it->price;
			break;
		}

	}
	//�����ͷ�
	info.ls.clear();

	//������ʾ
	UpdateData(FALSE);

}
