#pragma once
#include "afxwin.h"



// CDlgAdd ������ͼ

class CDlgAdd : public CFormView
{
	DECLARE_DYNCREATE(CDlgAdd)

protected:
	CDlgAdd();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgAdd();

public:
	enum { IDD = IDD_DIALOG_ADD };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_editSp;
	int m_price3;
	int m_price2;
	int m_num3;
	int m_num2;
	CComboBox m_comb2;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButtonAdd1();
	afx_msg void OnBnClickedButtonCancel1();
	afx_msg void OnBnClickedButtonAdd2();
	afx_msg void OnBnClickedButtonCancel2();
};


