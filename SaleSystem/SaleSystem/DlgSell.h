#pragma once
#include "afxwin.h"



// CDlgSell ������ͼ

class CDlgSell : public CFormView
{
	DECLARE_DYNCREATE(CDlgSell)

protected:
	CDlgSell();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgSell();

public:
	enum { IDD = IDD_DIALOG_SELL };
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
	CComboBox m_comb;
	CString m_info;
//	CString m_num;
//	CString m_price;
	int m_num;
	int m_price;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButtonNobuy();
	afx_msg void OnBnClickedButtonBuy();
};


