#include "mainwindow.h"

#include <QApplication>
#include "Mandelbrot.h"

int
main(int argc, char *argv[]) {
  MandelbrotInitColorTable();
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
