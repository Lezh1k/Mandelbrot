// MFC_Mandelbrot.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMandelbrotApp:
// See MFC_Mandelbrot.cpp for the implementation of this class
//

class CMandelbrotApp : public CWinApp
{
public:
	CMandelbrotApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMandelbrotApp theApp;