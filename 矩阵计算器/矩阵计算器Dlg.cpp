
// ���������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���������.h"
#include "���������Dlg.h"
#include "afxdialogex.h"
#include"Matrix.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

Matrix<int> Matrix1(4,4);
Matrix<int> Matrix2(4,4);
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C���������Dlg �Ի���




C���������Dlg::C���������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���������Dlg::IDD, pParent)
	, Matrix1_out(_T(""))
	, Matrix2_out(_T(""))
	, Matrix_result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, Combo_box_Matrix1, CB_Matrix1);
	DDX_Control(pDX, IDC_Combo_box_Matrix2, CB_Matirx2);
}

BEGIN_MESSAGE_MAP(C���������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_EN_CHANGE(IDC_Edit_Matrix1, &C���������Dlg::OnEnChangeEditMatrix1)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1, &C���������Dlg::OnBnClickedButtonMatrix1)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1_Transpose, &C���������Dlg::OnBnClickedButtonMatrix1Transpose)
	ON_BN_CLICKED(IDC_BUTTON_Matrix1_Multiply, &C���������Dlg::OnBnClickedButtonMatrix1Multiply)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2, &C���������Dlg::OnBnClickedButtonMatrix2)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2_Transpose, &C���������Dlg::OnBnClickedButtonMatrix2Transpose)
	ON_BN_CLICKED(IDC_BUTTON_Matrix2_Multiply, &C���������Dlg::OnBnClickedButtonMatrix2Multiply)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &C���������Dlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &C���������Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &C���������Dlg::OnBnClickedButtonSubtract)
END_MESSAGE_MAP()


// C���������Dlg ��Ϣ�������

BOOL C���������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}







void C���������Dlg::OnEnChangeEditMatrix1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix1()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix1Transpose()
{
	Matrix1.Transpose();
	Matrix1.intoCString(Matrix1_out);
	GetDlgItem(IDC_Edit_Matrix1)->SetWindowText(Matrix1_out);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix1Multiply()
{
	CString tem;
	GetDlgItem(IDC_Edit_Matrix1_Multiply)->GetWindowText(tem);
	int number1=_ttoi(tem);
	Matrix1.Multiply(number1);
	Matrix1.intoCString(Matrix1_out);
	GetDlgItem(IDC_Edit_Matrix1)->SetWindowText(Matrix1_out);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix2()
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix2Transpose()
{
	Matrix2.Transpose();
	Matrix2.intoCString(Matrix2_out);
	GetDlgItem(IDC_Edit_Matrix2)->SetWindowText(Matrix2_out);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMatrix2Multiply()
{
	CString tem;
	GetDlgItem(IDC_Edit_Matrix3_Multiply)->GetWindowText(tem);
	int number2=_ttoi(tem);
	Matrix2.Multiply(number2);
	Matrix2.intoCString(Matrix2_out);
	GetDlgItem(IDC_Edit_Matrix2)->SetWindowText(Matrix2_out);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonMultiply()
{
	Matrix<int> result=Matrix1.MULTIPLY(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



void C���������Dlg::OnBnClickedButtonAdd()
{
	Matrix<int> result=Matrix1.add(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C���������Dlg::OnBnClickedButtonSubtract()
{
	Matrix<int> result=Matrix1.subtrct(Matrix2);
	result.intoCString(Matrix_result);
	GetDlgItem(IDC_Edit_Matrix3)->SetWindowText(Matrix_result);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
