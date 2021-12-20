
// RZ_ClickHelperDlg.h: 头文件
//

#pragma once


// CRZClickHelperDlg 对话框
class CRZClickHelperDlg : public CDialogEx
{
// 构造
public:
	CRZClickHelperDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RZ_CLICKHELPER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	int setMode = 0;
	bool setStat[4] = { false,false,false,false };
	afx_msg void OnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
