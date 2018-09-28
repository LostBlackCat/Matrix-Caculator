
// 矩阵计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "矩阵计算器.h"
#include "矩阵计算器Dlg.h"
#include "afxdialogex.h"
#include"Matrix.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

Matrix<int> Matrix1(4,4);
Matrix<int> Matrix2(4,4);
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C矩阵计算器Dlg 对话框




C矩阵计算器Dlg::C矩阵计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C矩阵计算器Dlg::IDD, pParent)
	, Matrix1_out(_T(""))
	, Matrix2_out(_T(""))
	, Matrix_result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C矩阵计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, Combo_box_Matrix1, CB_Matrix1);
	DDX_Control(pDX, IDC_Combo_box_Matrix2, CB_Matirx2);
}

BEGIN_MESSAGE_MAP(C矩阵计算器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_EN_CHANGE(IDC_Edit_Matrix1, &C矩阵计算器Dlg::OnEnChangeEditMatrix1)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1, &C矩阵计算器Dlg::OnBnClickedButtonMatrix1)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1_Transpose, &C矩阵计算器Dlg::OnBnClickedButtonMatrix1Transpose)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1_Multiply, &C矩阵计算器Dlg::OnBnClickedButtonMatrix1Multiply)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2, &C矩阵计算器Dlg::OnBnClickedButtonMatrix2)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2_Transpose, &C矩阵计算器Dlg::OnBnClickedButtonMatrix2Transpose)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2_Multiply, &C矩阵计算器Dlg::OnBnClickedButtonMatrix2Multiply)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &C矩阵计算器Dlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &C矩阵计算器Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &C矩阵计算器Dlg::OnBnClickedButtonSubtract)
END_MESSAGE_MAP()


// C矩阵计算器Dlg 消息处理程序

BOOL C矩阵计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C矩阵计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C矩阵计算器Dlg::OnPaint()
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
HCURSOR C矩阵计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}







void C矩阵计算器Dlg::OnEnChangeEditMatrix1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix1()
{
	int nIndex=CB_Matrix1.GetCurSel();
	CString CBtext;
	CB_Matrix1.GetLBText(nIndex,CBtext);
	CString hang=CBtext.Left(1);
	int row1=_ttoi(hang);
	CString lie=CBtext.Right(1);
	int column1=_ttoi(lie);
	Matrix1.change(row1,column1);
	Matrix1.intoCString(Matrix1_out);
	GetDlgItem(IDC_Edit_Matrix1)->SetWindowText(Matrix1_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix1Transpose()
{
	Matrix1.Transpose();
	Matrix1.intoCString(Matrix1_out);
	GetDlgItem(IDC_Edit_Matrix1)->SetWindowText(Matrix1_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix1Multiply()
{
	CString tem;
	GetDlgItem(IDC_Edit_Matrix1_Multiply)->GetWindowText(tem);
	int number1=_ttoi(tem);
	Matrix1.Multiply(number1);
	Matrix1.intoCString(Matrix1_out);
	GetDlgItem(IDC_Edit_Matrix1)->SetWindowText(Matrix1_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix2()
{
	int nIndex=CB_Matirx2.GetCurSel();
	CString CBtext;
	CB_Matirx2.GetLBText(nIndex,CBtext);
	CString hang=CBtext.Left(1);
	int row2=_ttoi(hang);
	CString lie=CBtext.Right(1);
	int column2=_ttoi(lie);
	Matrix2.change(row2,column2);
	Matrix2.intoCString(Matrix2_out);
	GetDlgItem(IDC_Edit_Matrix2)->SetWindowText(Matrix2_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix2Transpose()
{
	Matrix2.Transpose();
	Matrix2.intoCString(Matrix2_out);
	GetDlgItem(IDC_Edit_Matrix2)->SetWindowText(Matrix2_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMatrix2Multiply()
{
	CString tem;
	GetDlgItem(IDC_Edit_Matrix3_Multiply)->GetWindowText(tem);
	int number2=_ttoi(tem);
	Matrix2.Multiply(number2);
	Matrix2.intoCString(Matrix2_out);
	GetDlgItem(IDC_Edit_Matrix2)->SetWindowText(Matrix2_out);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonMultiply()
{
	Matrix<int> result=Matrix1.MULTIPLY(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: 在此添加控件通知处理程序代码
}



void C矩阵计算器Dlg::OnBnClickedButtonAdd()
{
	Matrix<int> result=Matrix1.add(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: 在此添加控件通知处理程序代码
}


void C矩阵计算器Dlg::OnBnClickedButtonSubtract()
{
	Matrix<int> result=Matrix1.subtrct(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: 在此添加控件通知处理程序代码
}
