// DlgSell.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DlgSell.h"
#include "InfoFile.h"

// CDlgSell

IMPLEMENT_DYNCREATE(CDlgSell, CFormView)

CDlgSell::CDlgSell()
	: CFormView(CDlgSell::IDD)
	, m_info(_T(""))
	, m_num(0)
	, m_price(0)
{

}

CDlgSell::~CDlgSell()
{
}

void CDlgSell::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comb);
	DDX_Text(pDX, IDC_EDIT_INFO, m_info);
	//  DDX_Text(pDX, IDC_EDIT_NUM, m_num);
	//  DDX_Text(pDX, IDC_EDIT_PRICE, m_price);
	DDX_Text(pDX, IDC_EDIT_NUM, m_num);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_price);
}

BEGIN_MESSAGE_MAP(CDlgSell, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgSell::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_NOBUY, &CDlgSell::OnBnClickedButtonNobuy)
	ON_BN_CLICKED(IDC_BUTTON_BUY, &CDlgSell::OnBnClickedButtonBuy)
END_MESSAGE_MAP()


// CDlgSell ���

#ifdef _DEBUG
void CDlgSell::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgSell::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgSell ��Ϣ�������


void CDlgSell::OnInitialUpdate()
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


}

//��Ʒѡ�������۸ı�
void CDlgSell::OnCbnSelchangeCombo1()
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

	m_num = 0;

	//������ʾ
	UpdateData(FALSE);

}


void CDlgSell::OnBnClickedButtonNobuy()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_num = 0;
	UpdateData(FALSE);

}


void CDlgSell::OnBnClickedButtonBuy()
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
	//������Ʒ�޸�ʣ������
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		if (str == (CString(it->name.c_str())))
		{
			if (m_num > it->num)
			{
				CString err;
				err.Format(TEXT("��治�㣬ֻʣ����%d"), it->num);
				MessageBox(err);
				info.ls.clear();
				return;
			}
			it->num = it->num - m_num;

			//��д����
			info.WirteDocline();
		}

	}
	//�����ͷ�
	info.ls.clear();

	CString sellinfo;
	sellinfo.Format(TEXT("��Ʒ����%s\r\n���ۣ�%d\r\n������%d\r\n�ܼۣ�%d\r\n"), str, m_price, m_num, m_price * m_num);
	m_num = 0;

	m_info = sellinfo;
	//m_info.Empty();
	UpdateData(FALSE);

}
