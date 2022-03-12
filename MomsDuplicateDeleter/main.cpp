#include "momsduplicatedeleter.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication::setAttribute(Qt::AA_Use96Dpi);
  QApplication a(argc, argv);
  MomsDuplicateDeleter w;
  w.show();
  return a.exec();
}
