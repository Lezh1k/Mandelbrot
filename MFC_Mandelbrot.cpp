// MFC_Mandelbrot.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_Mandelbrot.h"
#include "MandelbrotDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMandelbrotApp

BEGIN_MESSAGE_MAP(CMandelbrotApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMandelbrotApp construction

CMandelbrotApp::CMandelbrotApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMandelbrotApp object

CMandelbrotApp theApp;


// CMandelbrotApp initialization

BOOL CMandelbrotApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();	

	CMandelbrotDlg dlg;
	m_pMainWnd = &dlg;
  
	INT_PTR nResponse = dlg.DoModal();
	
  // Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
