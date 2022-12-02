#ifndef MOMSDUPLICATEDELETER_H
#define MOMSDUPLICATEDELETER_H

#include "exif.h"
#include "imageviewer.h"
#include "sqlQuery.h"
#include "window.h"
#include <CRC32.h>
#include <QDebug>
#include <QDirIterator>
#include <QFileDialog>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLatin1String>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegExp>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlField>
#include <QSqlQuery>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui {
class MomsDuplicateDeleter;
}
QT_END_NAMESPACE

class MomsDuplicateDeleter : public QMainWindow {
  Q_OBJECT

public:
  MomsDuplicateDeleter(QWidget *parent = nullptr);
  ~MomsDuplicateDeleter();
  void fillDuplicateFilesTable();
  void deleteDuplicateFiles(bool simulatedFlag);
  int searchForAndInsertFileType();
  void exportFiles2CSV();
  void deleteDuplicateFilesFromPath(bool simulatedFlag);
  void deleteDuplicateFilesNotInPath(bool simulatedFlag);

  void deleteSingleFile(bool simulatedFlag);
  void deleteDuplicateFilesFromPathAndBelow(bool simulatedFlag);
  ImageViewer imageViewer;
  Window window;
  bool fileExists(QString path);
  void fillUniqueFilesTable();
  bool removeEmptyDirectory(QString);
  void excludeDuplicateFilesFromPathAndBelow();
private slots:
  void on_pbSelectDirectory_clicked();

  void on_pbSearch_clicked();

  void on_pbRemoveDB_clicked();

  void on_pbFillTablesFromDB_clicked();

  void on_pbSimDelete_clicked();

  void on_pbActualDelete_clicked();

  void on_pbDeleteFromPath_clicked();

  void on_pbKeepInPath_clicked();

  void on_pbDeleteSingle_clicked();

  void on_pbDeleteFromPathBelow_clicked();

  void on_pbViewImage_clicked();

  void on_pbViewMovie_clicked();

  void on_pbVerifyDB_clicked();

  void on_pbViewImage_2_clicked();

  void on_pbFillTablesFromDB_2_clicked();

  void on_pbOpenDirectory_clicked();

  void on_pbOpenDirectoryExclusive_clicked();

  void on_pbExcludePathAndBelow_clicked();

private:
  QVector<QDir> fileList;
  QString databaseFilename;
  Ui::MomsDuplicateDeleter *ui;
  unsigned int numberOfDupFiles = 0;
  unsigned int numberOfUniqueFiles = 0;
  unsigned int numberOfFiles = 0;
};
#endif // MOMSDUPLICATEDELETER_H
