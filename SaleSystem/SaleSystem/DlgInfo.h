#pragma once
#include "afxcmn.h"



// CDlgInfo ������ͼ

class CDlgInfo : public CFormView
{
	DECLARE_DYNCREATE(CDlgInfo)

protected:
	CDlgInfo();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgInfo();

public:
	enum { IDD = IDD_DIALOG_INFO };
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
	CListCtrl m_list;
public:
	virtual void OnInitialUpdate();
};


