
// ���������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C���������Dlg �Ի���
class C���������Dlg : public CDialogEx
{
// ����
public:
	C���������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
