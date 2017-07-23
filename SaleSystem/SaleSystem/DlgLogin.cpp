// DlgLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SaleSystem.h"
#include "DlgLogin.h"
#include "afxdialogex.h"
#include "InfoFile.h"

// CDlgLogin �Ի���

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgLogin::IDD, pParent)
	, m_name(_T(""))
	, m_pwd(_T(""))
{

}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CDlgLogin::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_Login, &CDlgLogin::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// CDlgLogin ��Ϣ�������


void CDlgLogin::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	exit(1);
	CDialogEx::OnClose();
}


void CDlgLogin::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CDlgLogin::OnBnClickedButtonCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	exit(1);
}


BOOL CDlgLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//��ʼ���������ڲ���
	m_name = TEXT("hhn");
	m_pwd = TEXT("666");
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgLogin::OnBnClickedButtonLogin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	if (m_name.IsEmpty() || m_pwd.IsEmpty())
	{
		MessageBox(TEXT("�û����������벻����Ϊ��"));
		return;
	}

	CInfoFile file;
	CString name, pwd;

	file.ReadLogin(name, pwd);


	if (name != m_name)
	{
		MessageBox(TEXT("�û���������"));
		return;
	}
	
	if (pwd != m_pwd)
	{
		MessageBox(TEXT("�������"));
		return;
	}

	CDialogEx::OnOK();

}
