//// MandelbrotDlg.cpp : implementation file
////

//#include "MFC_Mandelbrot.h"
//#include "MandelbrotDlg.h"
//#include "MandelbrotController.h"
//#include <math.h>
//#include "Commons.h"
//#include "NewtonController.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


////////////////////////////////////////////////////////////////////////////

//CMandelbrotDlg::CMandelbrotDlg(CWnd* pParent /*=NULL*/)
//	: CDialog(CMandelbrotDlg::IDD, pParent)
//{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//  m_currentFractal = FRACTALS::NOTHING;
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialog::DoDataExchange(pDX);
//  DDX_Control(pDX, IDC_CANVAS, m_canvas);
//  DDX_Control(pDX, IDC_RBTN_GROW, m_rbtnGrow);
//  DDX_Control(pDX, IDC_RDBTN_REDUCE, m_rbtnReduce);
//  DDX_Control(pDX, IDC_FRACTAL_PROGRESS, m_fractalProgressCtrl);
//}
////////////////////////////////////////////////////////////////////////////

//BEGIN_MESSAGE_MAP(CMandelbrotDlg, CDialog)
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
//  ON_WM_LBUTTONUP()

//	//}}AFX_MSG_MAP
//  ON_COMMAND(ID_METHODS_MANDELBROT, &CMandelbrotDlg::OnMethodsMandelbrot)
//  ON_COMMAND(ID_FILE_EXIT, &CMandelbrotDlg::OnFileExit)
//  ON_COMMAND(ID_FILE_SAVE32773, &CMandelbrotDlg::OnMiSave_Clicked)
//  ON_COMMAND(ID_METHODS_NEWTON, &CMandelbrotDlg::OnMethodsNewton)
//END_MESSAGE_MAP()
////////////////////////////////////////////////////////////////////////////

//#include <WinSock2.h>
//#pragma comment(lib, "ws2_32.lib")
//#include <iostream>
//BOOL CMandelbrotDlg::OnInitDialog()
//{
//	CDialog::OnInitDialog();

//	SetIcon(m_hIcon, TRUE);			// Set big icon
//	SetIcon(m_hIcon, FALSE);		// Set small icon

//  m_canvasDC = m_canvas.GetDC();
//  m_canvas.GetClientRect(&m_canvasRect);

//  m_rbtnGrow.SetCheck(1);
  
//  m_virtualDC.CreateCompatibleDC(m_canvasDC);
//  m_virtualCBM.CreateCompatibleBitmap(m_canvasDC, m_canvasRect.Width(), m_canvasRect.Height());
//  m_virtualDC.SelectObject(m_virtualCBM);

//  m_fractalProgressCtrl.SetPos(0);
//  m_fractalProgressCtrl.SetRange(0, m_canvasRect.Width() - 1);
  
//  PaintFractalOnVirtualDC();

//  WORD wVersionRequested;
//  WSADATA wsaData;
//  int err;

//  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
//  wVersionRequested = MAKEWORD(2, 2);

//  err = WSAStartup(wVersionRequested, &wsaData);
//  if (err != 0) {
//    return TRUE;
//  }

//  SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
//  if (sock == INVALID_SOCKET)
//    return TRUE;

//  sockaddr addr;
//  DWORD ret;
//  int res = WSAIoctl(sock, SIO_GET_BROADCAST_ADDRESS, NULL, 0, &addr, sizeof(sockaddr), &ret, NULL, NULL);
//  if (res != 0) {
//    std::cout << "bee" << std::endl;
//    int le = WSAGetLastError();
//    std::cout << le;
//  }
//  else
//    std::cout << "Hoho" << std::endl;

//  return TRUE;  // return TRUE  unless you set the focus to a control
//}
////////////////////////////////////////////////////////////////////////////

////todo : use m_virtualBM for drawing.
//void CMandelbrotDlg::PaintFractalOnVirtualDC( void )
//{
//  if (m_currentFractal == FRACTALS::NOTHING) return;

//  m_fractalProgressCtrl.SetPos(0);

//  long double xScale = DISTANCE(m_rx, m_lx) / m_canvasRect.Width();
//  long double yScale = DISTANCE(m_uy, m_dy) / m_canvasRect.Height();
//  long double lcx, rcx, ucy, dcy;
//  lcx = m_lx; rcx = m_rx; ucy = m_uy; dcy = m_dy;

//  int x, y;
//  x=0;
  
//  while (x < m_canvasRect.Width()) /*lcx <= rcx*/
//  {
//    ucy = m_uy;
//    y = 0;
//    while (y < m_canvasRect.Height()) /*ucy >= dcy*/
//    {
//      m_virtualDC.SetPixel(x, y, m_pfGetColor(lcx, ucy));
//      ucy-=yScale;
//      y++;
//    }
//    lcx+=xScale;
//    m_fractalProgressCtrl.SetPos(x++);
//  }

//  for (x = 0; x < m_canvasRect.Width(); x++)
//  {
//    unsigned int pc = m_virtualDC.GetPixel(x, m_canvasRect.Height() / 2);
//    pc ^= 0x00ffffff;
//    m_virtualDC.SetPixel(x, m_canvasRect.Height() / 2, pc);
//  }

//  for (y = 0; y < m_canvasRect.Height(); y++)
//  {
//    unsigned int pc = m_virtualDC.GetPixel(m_canvasRect.Width() / 2, y);
//    pc ^= 0x00ffffff;
//    m_virtualDC.SetPixel(m_canvasRect.Width() / 2, y, pc);
//  }

//  this->PostMessage(WM_PAINT);
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnLButtonUp( unsigned int flags, CPoint point )
//{
//  if (point.x <= m_canvasRect.left || point.x >= m_canvasRect.right
//    || point.y <= m_canvasRect.top || point.y >= m_canvasRect.bottom)
//    return; //point not into canvas

//  long double xScale = DISTANCE(m_rx, m_lx) / m_canvasRect.Width();
//  long double yScale = DISTANCE(m_uy, m_dy) / m_canvasRect.Height();

//  int x = point.x - m_canvasRect.left;
//  int y = point.y - m_canvasRect.top;

//  long double coef = m_rbtnGrow.GetCheck() ? 4.0 : 0.95;

//  long double cx0, cy0;

//  cx0 = m_lx + x*xScale;
//  cy0 = m_uy - y*yScale;

//  m_rx = cx0 + (m_canvasRect.Width() / coef)*xScale;
//  m_lx = cx0 - (m_canvasRect.Width() / coef)*xScale;

//  m_uy = cy0 + (m_canvasRect.Height() / coef)*yScale;
//  m_dy = cy0 - (m_canvasRect.Height() / coef)*yScale;

//  PaintFractalOnVirtualDC();
//  this->PostMessage(WM_PAINT);
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnPaint()
//{
//  if (!IsIconic())
//  {
//    BitBlt(m_canvasDC->m_hDC, 0, 0, m_canvasRect.Width(), m_canvasRect.Height(), m_virtualDC.m_hDC, 0, 0, SRCCOPY);
//    CDialog::OnPaint();
//    return;
//  }

//  CPaintDC dc(this); // device context for painting

//  SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

//  int cxIcon = GetSystemMetrics(SM_CXICON);
//  int cyIcon = GetSystemMetrics(SM_CYICON);

//  CRect rect;
//  GetClientRect(&rect);

//  int x = (rect.Width() - cxIcon + 1) / 2;
//  int y = (rect.Height() - cyIcon + 1) / 2;

//  dc.DrawIcon(x, y, m_hIcon);
//}
////////////////////////////////////////////////////////////////////////////

//HCURSOR CMandelbrotDlg::OnQueryDragIcon()
//{
//  return static_cast<HCURSOR>(m_hIcon);
//}
/////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnMethodsMandelbrot()
//{
//  m_lx = -2.5L;
//  m_dy = -1.0L;
//  m_rx = m_uy = 1.0L;
//  m_currentFractal = FRACTALS::MANDELBROT;
//  m_pfGetColor = CMandelbrotController::GetMandelbrotColor;
//  PaintFractalOnVirtualDC();
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnMethodsNewton()
//{
//  m_lx = -4.15L;
//  m_dy = -1.0L;
//  m_rx = m_uy = 1.0L;
//  m_currentFractal = FRACTALS::NEWTON;
//  m_pfGetColor = CNewtonController::GetNewtonFractalsColor;
//  PaintFractalOnVirtualDC();
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnFileExit()
//{
//  AfxGetMainWnd()->SendMessage(WM_CLOSE);
//}
////////////////////////////////////////////////////////////////////////////

//void CMandelbrotDlg::OnMiSave_Clicked()
//{
//  if (m_currentFractal == FRACTALS::NOTHING) return;
  
//  CFileDialog dlg(FALSE, L"bmp", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, L"*.bmp|bmp");
//  INT_PTR res = dlg.DoModal();

//  if (res != IDOK) return;

//  CImage img;
//  img.Create(m_canvasRect.Width(), m_canvasRect.Height(), 32);
//  BitBlt(img.GetDC(), 0, 0, m_canvasRect.Width(), m_canvasRect.Height(), m_canvasDC->m_hDC, 0, 0, SRCCOPY);
//  img.Save(dlg.GetFileName());
//  img.ReleaseDC();
//  img.Destroy();
//}
////////////////////////////////////////////////////////////////////////////
