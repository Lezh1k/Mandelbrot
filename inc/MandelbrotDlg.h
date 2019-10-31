//// MandelbrotDlg.h : header file
////

//#pragma once
//typedef unsigned int (*pfFractal)(long double x, long double y);

//// CMandelbrotDlg dialog
//class CMandelbrotDlg : public CDialog
//{
//  //fields
//private:
//  CDC* m_canvasDC;
//  CStatic m_canvas;
//  CRect m_canvasRect;
//  CProgressCtrl m_fractalProgressCtrl;

//  CDC m_virtualDC;
//  CBitmap m_virtualCBM;

//  double m_lx, m_rx, m_uy, m_dy;

//  CButton m_rbtnGrow;
//  CButton m_rbtnReduce;

//  pfFractal m_pfGetColor;

//  enum FRACTALS{
//    NOTHING,
//    MANDELBROT,
//    NEWTON} m_currentFractal;

//protected:
//  HICON m_hIcon;

//public:
//	enum { IDD = IDD_MFC_MANDELBROT_DIALOG };

//  //methods
//private:
//  void PaintFractalOnVirtualDC(void);

//protected:

//  virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
//  virtual BOOL OnInitDialog();

//  afx_msg void OnPaint();
//  afx_msg HCURSOR OnQueryDragIcon();

//  afx_msg void OnLButtonUp(unsigned int flags, CPoint point);

//  DECLARE_MESSAGE_MAP();

//public:

//  CMandelbrotDlg(CWnd* pParent = NULL);	// standard constructor
//  afx_msg void OnMethodsMandelbrot();
//  afx_msg void OnFileExit();
//  afx_msg void OnMiSave_Clicked();
//  afx_msg void OnMethodsNewton();
//};
