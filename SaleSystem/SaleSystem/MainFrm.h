
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

// �Զ�����Ϣ
#define NM_A (WM_USER + 100)
#define NM_B (WM_USER + 101)
#define NM_C (WM_USER + 102)
#define NM_D (WM_USER + 103)
#define NM_E (WM_USER + 104)

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_splitter;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	//�Զ�����Ϣӳ�亯������
	afx_msg LRESULT OnMyChange(WPARAM, LPARAM);
};


