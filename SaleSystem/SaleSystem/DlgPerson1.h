#pragma once



// CDlgPerson1 ������ͼ

class CDlgPerson1 : public CFormView
{
	DECLARE_DYNCREATE(CDlgPerson1)

protected:
	CDlgPerson1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgPerson1();

public:
	enum { IDD = IDD_DIALOG_PERSON };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CString m_role;
	CString m_name;
	CString m_newpwd;
	CString m_surepwd;
public:
	afx_msg void OnBnClickedButtonSure();
};


