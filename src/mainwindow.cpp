#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

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
  m_imgModel->Update();

  memcpy(static_cast<void*>(m_img.bits()),
         static_cast<void*>(m_imgModel->Data()),
         m_imgModel->DataLenBytes());
  ui->m_lblCanvas->setPixmap(QPixmap::fromImage(m_img));
}

MainWindow::~MainWindow() {
  delete ui;
  delete m_imgModel;
}
///////////////////////////////////////////////////////
