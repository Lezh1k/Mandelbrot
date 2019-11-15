#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMouseEvent>

static const int CANVAS_W = 800;
static const int CANVAS_H = 600;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_img(CANVAS_W, CANVAS_H, QImage::Format_RGB32),
  m_imgModel(nullptr) {

  ui->setupUi(this);
  m_imgModel = new FractalsModel(CANVAS_W, CANVAS_H);
  m_imgModel->SetFractalType(FT_NEWTON);
  ui->m_lblCanvas->installEventFilter(this);

  DrawImg();
}

MainWindow::~MainWindow() {
  delete ui;
  delete m_imgModel;
}
///////////////////////////////////////////////////////

bool
MainWindow::eventFilter(QObject *watched,
                        QEvent *event) {
  if (watched != ui->m_lblCanvas)
    return false;
  if (event->type() != QEvent::MouseButtonRelease)
    return false;

  QMouseEvent *me = reinterpret_cast<QMouseEvent*>(event);
  m_imgModel->SetPOI(static_cast<uint32_t>(me->x()),
                     static_cast<uint32_t>(me->y()),
                     me->button() == Qt::LeftButton);
  DrawImg();
  return true;
}

void
MainWindow::DrawImg() {
  m_imgModel->Update();
  memcpy(static_cast<void*>(m_img.bits()),
         static_cast<const void*>(m_imgModel->Data()),
         CANVAS_H * CANVAS_W * sizeof(uint32_t));
  ui->m_lblCanvas->setPixmap(QPixmap::fromImage(m_img));
}
///////////////////////////////////////////////////////
