// DlgAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DlgAdd.h"
#include "InfoFile.h"

// CDlgAdd

IMPLEMENT_DYNCREATE(CDlgAdd, CFormView)

CDlgAdd::CDlgAdd()
	: CFormView(CDlgAdd::IDD)
	, m_editSp(_T(""))
	, m_price3(0)
	, m_price2(0)
	, m_num3(0)
	, m_num2(0)
{

}

CDlgAdd::~CDlgAdd()
{
}

void CDlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THING, m_editSp);
	DDX_Text(pDX, IDC_EDIT_PRICE3, m_price3);
	DDX_Text(pDX, IDC_EDIT_PRICE2, m_price2);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_num3);
	DDX_Text(pDX, IDC_EDIT_NU, m_num2);
	DDX_Control(pDX, IDC_COMBO2, m_comb2);
}

BEGIN_MESSAGE_MAP(CDlgAdd, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDlgAdd::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON_ADD1, &CDlgAdd::OnBnClickedButtonAdd1)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL1, &CDlgAdd::OnBnClickedButtonCancel1)
	ON_BN_CLICKED(IDC_BUTTON_ADD2, &CDlgAdd::OnBnClickedButtonAdd2)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL2, &CDlgAdd::OnBnClickedButtonCancel2)
END_MESSAGE_MAP()


// CDlgAdd ���

#ifdef _DEBUG
void CDlgAdd::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgAdd::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgAdd ��Ϣ�������


void CDlgAdd::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���


	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//����Ʒ����ӵ�combox
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		m_comb2.AddString(CString(it->name.c_str()));

	}
	//�����ͷ�
	info.ls.clear();

	//Ĭ��ѡ�е�һ����Ʒ
	m_comb2.SetCurSel(0);
	OnCbnSelchangeCombo2();

	m_price3 = 0;
	m_num2 = 0;
	m_num3 = 0;
	m_editSp.Empty();
	UpdateData(FALSE);
}


void CDlgAdd::OnCbnSelchangeCombo2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = m_comb2.GetCurSel();
	CString str;
	m_comb2.GetLBText(index, str);

	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//����Ʒ����ӵ�combox
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		if (str == (CString(it->name.c_str())))
		{
			m_price2 = it->price;
			break;
		}

	}
	//�����ͷ�
	info.ls.clear();

	//������ʾ
	UpdateData(FALSE);

}


void CDlgAdd::OnBnClickedButtonAdd1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if (m_num2 <= 0)
	{
		MessageBox(_T("��������Ϊ��"));
		return;
	}

	//���������Ϣ
	int index = m_comb2.GetCurSel();
	CString str;
	m_comb2.GetLBText(index, str);

	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//������Ʒ�޸�ʣ������
	for (list<msg>::iterator it = info.ls.begin(); it != info.ls.end(); it++)
	{
		if (str == (CString(it->name.c_str())))
		{
			if (m_num2 > it->num)
			{
				CString err;
				err.Format(TEXT("��治�㣬ֻʣ����%d"), it->num);
				MessageBox(err);
				info.ls.clear();
				return;
			}
			it->num = it->num + m_num2;

			//��д����
			info.WirteDocline();
			break;
		}

	}
	//�����ͷ�
	info.ls.clear();

	CString infostr;
	infostr.Format(TEXT("������Ʒ\r\n��Ʒ����%s\r\n���ۣ�%d\r\n������%d\r\n"), str, m_price2, m_num2);
	
	MessageBox(infostr);

	m_num2 = 0;
	UpdateData(FALSE);
}


void CDlgAdd::OnBnClickedButtonCancel1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_num2 = 0;
	UpdateData(FALSE);
}

//����²�Ʒ
void CDlgAdd::OnBnClickedButtonAdd2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if (m_num3 <= 0 || m_price3 <= 0 || m_editSp.IsEmpty())
	{
		MessageBox(_T("����Ϊ��"));
		return;
	}
	//��ȡ��Ʒ��Ϣ
	CInfoFile info;
	info.ReadDocline();
	//������Ʒ
	info.Addline(m_editSp, m_num3, m_price3);

	info.WirteDocline();

	CString infostr;
	infostr.Format(TEXT("�ɹ�������Ʒ\r\n��Ʒ����%s\r\n���ۣ�%d\r\n������%d\r\n"), m_editSp, m_price3, m_num3);

	MessageBox(infostr);

	m_editSp.Empty();
	m_price3 = 0;
	m_num3 = 0;

	UpdateData(FALSE);
}


void CDlgAdd::OnBnClickedButtonCancel2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_editSp.Empty();
	m_price3 = 0;
	m_num3 = 0;

	UpdateData(FALSE);
}
