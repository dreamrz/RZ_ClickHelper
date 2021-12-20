
// RZ_ClickHelperDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RZ_ClickHelper.h"
#include "RZ_ClickHelperDlg.h"
#include "afxdialogex.h"
#include "Thread.h"

ClickThread CT;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRZClickHelperDlg 对话框


CRZClickHelperDlg::CRZClickHelperDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RZ_CLICKHELPER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRZClickHelperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRZClickHelperDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRZClickHelperDlg::OnClickedButton1)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_BUTTON2, &CRZClickHelperDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRZClickHelperDlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRZClickHelperDlg::OnClickedButton4)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CRZClickHelperDlg 消息处理程序

BOOL CRZClickHelperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	SetTimer(1, 200, 0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRZClickHelperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRZClickHelperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CRZClickHelperDlg::OnHelpInfo(HELPINFO* pHelpInfo)
{
	return true;

	return CDialogEx::OnHelpInfo(pHelpInfo);
}

BOOL CRZClickHelperDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_F1)
		{
			return true;
		}
		if (pMsg->wParam == VK_F8)
		{
			switch (setMode)
			{
			case 1:
				GetCursorPos(&addpoint);
				break;
			case 2:
				GetCursorPos(&outpoint);
				break;
			case 3:
				GetCursorPos(&numberpoint);
				break;
			case 4:
				GetCursorPos(&testpoint);
				break;
			}
			setMode = 0;
			CString str;
			CString addtext;

			if (setStat[0])
			{
				str.Format(L"%ld", addpoint.x);
				addtext = L"X: " + str + L"Y: ";
				str.Format(L"%ld", addpoint.y);
				addtext += str;
				GetDlgItem(IDC_STATIC1)->SetWindowText(addtext);
			}

			if (setStat[1])
			{
				str.Format(L"%ld", outpoint.x);
				addtext = L"X: " + str + L"Y: ";
				str.Format(L"%ld", outpoint.y);
				addtext += str;
				GetDlgItem(IDC_STATIC2)->SetWindowText(addtext);
			}

			if (setStat[2])
			{
				str.Format(L"%ld", numberpoint.x);
				addtext = L"X: " + str + L"Y: ";
				str.Format(L"%ld", numberpoint.y);
				addtext += str;
				GetDlgItem(IDC_STATIC3)->SetWindowText(addtext);
			}

			if (setStat[3])
			{
				str.Format(L"%ld", testpoint.x);
				addtext = L"X: " + str + L"Y: ";
				str.Format(L"%ld", testpoint.y);
				addtext += str;
				GetDlgItem(IDC_STATIC4)->SetWindowText(addtext);
			}
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CRZClickHelperDlg::OnClickedButton1()
{
	GetDlgItem(IDC_STATIC1)->SetWindowText(L"设置中 F8 确认");
	setMode = 1;
	setStat[0] = true;
}

void CRZClickHelperDlg::OnClickedButton2()
{
	GetDlgItem(IDC_STATIC2)->SetWindowText(L"设置中 F8 确认");
	setMode = 2;
	setStat[1] = true;
}


void CRZClickHelperDlg::OnClickedButton3()
{
	GetDlgItem(IDC_STATIC3)->SetWindowText(L"设置中 F8 确认");
	setMode = 3;
	setStat[2] = true;
}


void CRZClickHelperDlg::OnClickedButton4()
{
	GetDlgItem(IDC_STATIC4)->SetWindowText(L"设置中 F8 确认");
	setMode = 4;
	setStat[3] = true;
}


void CRZClickHelperDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(continuousclick);
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
