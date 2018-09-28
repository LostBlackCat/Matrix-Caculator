
// 矩阵计算器Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C矩阵计算器Dlg 对话框
class C矩阵计算器Dlg : public CDialogEx
{
// 构造
public:
	C矩阵计算器Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Matrix1_out;
	CString Matrix2_out;
	CString Matrix_result;
	afx_msg void OnEnChangeEditMatrix1();
	afx_msg void OnBnClickedButtonMatrix1();
	afx_msg void OnBnClickedButtonMatrix1Transpose();
	afx_msg void OnBnClickedButtonMatrix1Multiply();
	afx_msg void OnBnClickedButtonMatrix2();
	afx_msg void OnBnClickedButtonMatrix2Transpose();
	afx_msg void OnBnClickedButtonMatrix2Multiply();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSubtract();
	CComboBox CB_Matrix1;
	CComboBox CB_Matirx2;
};
