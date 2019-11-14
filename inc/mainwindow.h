#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

#include "FractalsModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QMouseEvent;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  virtual bool eventFilter(QObject *watched, QEvent *event);

private:
  Ui::MainWindow *ui;

  QImage m_img;
  FractalsModel *m_imgModel;

  void DrawImg();

private slots:
};
#endif // MAINWINDOW_H
