#include "momsduplicatedeleter.h"
#include "ui_momsduplicatedeleter.h"

MomsDuplicateDeleter::MomsDuplicateDeleter(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MomsDuplicateDeleter) {
  ui->setupUi(this);
  //Remove tags not implemented yet
  ui->tabWidget->removeTab(1);
  ui->tabWidget->removeTab(2);
  ui->pbExportFilesList2CSV->hide();
  ui->pbViewMovie->hide();
  //Default database name.  Need to add feature to all the user to choose a name or existing db.
  databaseFilename = "duplicateFileList.db";
  ui->pbSearch->setEnabled(false);
  ui->progressBar->hide();
  ui->progressBar->setAlignment(Qt::AlignCenter);
  ui->pbSimDelete->hide();
//  ui->leUserSubPath->hide();
  ui->tableDuplicateResultsList->setColumnCount(5);
  ui->tableDuplicateResultsList->verticalHeader()->setVisible(false);
  ui->tabWidget->removeTab(1);
  //    ui->tableDuplicateResultsList->horizontalHeader()->setVisible(true);
  QStringList m_TableHeader;
  m_TableHeader << "ID"
                << "File Name"
                << "Directory/Folder"
                << "File Size"
                << "CRC";
  ui->tableDuplicateResultsList->setHorizontalHeaderLabels(m_TableHeader);
  //    ui->tableDuplicateResultsList->horizontalHeader()->setDefaultAlignment(
  //        Qt::AlignLeft);
  //    QString headerStyleSheet = "::section {" // "QHeaderView::section {"
  //                               "background-color: black;"
  //                               "color: white;"
  //                               "border: 2px solid black;"
  //                               "margin: 1px;"
  //                               "text-align: left;"
  //                               "font-family: Source Sans Pro;"
  //                               "font-size: 40px; "
  //                               "font-weight: 400;}";
  //    ui->tableDuplicateResultsList->horizontalHeader()->setStyleSheet(
  //        headerStyleSheet);
}

MomsDuplicateDeleter::~MomsDuplicateDeleter() { delete ui; }

void MomsDuplicateDeleter::on_pbSelectDirectory_clicked() {
  ui->lePathToSearch->setText(QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), ".",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
  ui->pbSearch->setEnabled(true);
}

void MomsDuplicateDeleter::deleteDuplicateFiles(bool simulatedFlag) {
  unsigned int j = 0;
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QApplication::processEvents();
  const QString DRIVER("QSQLITE");
  if (QSqlDatabase::isDriverAvailable(DRIVER))
    qDebug() << "database driver is installed";
  QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
  //     db.setDatabaseName(":memory:");
  db.setDatabaseName(databaseFilename);
  if (!db.open())
    qWarning() << "ERROR: " << db.lastError();
  unsigned int uniqueFileCount = 0;
  qint64 totalSize = 0;
  ui->progressBar->show();
  ui->progressBar->setFormat("Starting delete operation ");
  ui->progressBar->setValue(0);
  QApplication::processEvents();
  QSqlQuery query4;
  query4.prepare(qryCountOfUniqueChecksums);
  do {
    db.transaction();
    if (!query4.exec())
      qWarning() << "ERROR: " << query4.lastError().text();
    while (query4.next()) {
      uniqueFileCount = query4.value("unique_count").toUInt();
    }
    if (uniqueFileCount > 0) {
      QSqlQuery query2;
      query2.prepare(qryIDRandomDuplicate);
      if (!query2.exec())
        qWarning() << "ERROR: " << query2.lastError().text();
      //    qDebug() << "size returned by query is " << query2.value(0).toInt();
      unsigned int uniqueFileID = 0;

      while (query2.next()) {
        uniqueFileID = query2.value("id").toUInt();
        totalSize += query2.value("size").toUInt();
      }
      QSqlQuery query6;
      query6.prepare(qryFilePath + QString::number(uniqueFileID));
      if (!query6.exec())
        qWarning() << "ERROR: " << query6.lastError().text();
      QString fileToBeDeleted;
      while (query6.next()) {
        fileToBeDeleted.append(query6.value("path").toString());
        fileToBeDeleted.append("/");
        fileToBeDeleted.append(query6.value("name").toString());
        if (!simulatedFlag) {
          QFile removeFile(fileToBeDeleted);
          if (!removeFile.setPermissions(QFile::ReadOther |
                                         QFile::WriteOther)) {
            qWarning() << "ERROR: setting permissions  " << fileToBeDeleted;
            qWarning() << "ERROR:  " << removeFile.errorString();
          }
          if (!removeFile.remove()) {
            qWarning() << "ERROR: Removing file  " << fileToBeDeleted;
            qWarning() << "ERROR:  " << removeFile.errorString();
          }
          //          else  qDebug() << "fileToBeDeleted is " <<
          //          fileToBeDeleted;
        }
        //    qDebug() << "random file id result value " << query2.value("id");
        QSqlQuery query5;
        query5.prepare(qryDeleteFileByID + QString::number(uniqueFileID));
        if (!query5.exec())
          qWarning() << "ERROR: " << query5.lastError().text();
        //        qDebug() << "rows affected is  " << query5.numRowsAffected();
        j++;
        if (j % 100 == 0) {
          unsigned int progressFraction = j % 99;
          if ((numberOfDupFiles - numberOfUniqueFiles) != 0)
            progressFraction =
                ((j * 100) / (numberOfDupFiles - numberOfUniqueFiles));
          ui->progressBar->setValue(int(progressFraction));
          ui->progressBar->setFormat("Delete progress  -   " +
                                     QString::number(progressFraction) + " % ");
          QApplication::processEvents();
        }
      }
    }
  } while (uniqueFileCount > 0);
  if (!simulatedFlag) {
    db.commit();
    db.exec("VACUUM");
    qDebug() << "number of files that were deleted " << j;
  } else {
    db.rollback();
    qDebug() << "number of files that would be deleted " << j;
  }
  db.exec("VACUUM");
  db.close();
  QApplication::restoreOverrideCursor();
  ui->progressBar->hide();
  QApplication::processEvents();
  if (!simulatedFlag) {
    QMessageBox::information(
        0, "Delete Operation Stats",
        QString::number(j) + " File(s) - Total number of file(s) deleted\n" +
            QString::number(totalSize / 1000000) +
            " MB - Total Space Reclaimed ");
  } else {
    QMessageBox::information(
        0, "Simulated Delete Operation Stats",
        QString::number(j) +
            " File(s) - Total number of file(s) that would be deleted\n" +
            QString::number(totalSize / 1000000) +
            " MB - Total Space that would be Reclaimed ");
  }
}
void MomsDuplicateDeleter::fillFilesTable() {
  const QString DRIVER("QSQLITE");
  if (QSqlDatabase::isDriverAvailable(DRIVER))
    qDebug() << "database driver is installed";
  QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
  //     db.setDatabaseName(":memory:");
  db.setDatabaseName(databaseFilename);
  if (!db.open())
    qWarning() << "ERROR: " << db.lastError();
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QApplication::processEvents();
  QSqlQuery query2;
  QString sFileType(ui->cbFileType->currentText());
  sFileType.replace("*.", "%");
  QString tempQuery(qrySelectDuplicates);
  tempQuery.replace(":fileType", sFileType);
  query2.prepare(tempQuery);
  //  query2.bindValue(":fileType", sFileType);
  if (!query2.exec())
    qWarning() << "ERROR: " << query2.lastError().text();
  qWarning() << "Last Query was " << sFileType;
  query2.first();
  int j = 0;
  ui->tableDuplicateResultsList->setRowCount(0);
  ui->tableDuplicateResultsList->setSortingEnabled(false);
  do {
    j++;
    ui->tableDuplicateResultsList->insertRow(
        ui->tableDuplicateResultsList->rowCount());
    ui->tableDuplicateResultsList->setItem(
        ui->tableDuplicateResultsList->rowCount() - 1, 0,
        new QTableWidgetItem(query2.value("id").toString()));
    ui->tableDuplicateResultsList->setItem(
        ui->tableDuplicateResultsList->rowCount() - 1, 1,
        new QTableWidgetItem(query2.value("name").toString()));
    ui->tableDuplicateResultsList->setItem(
        ui->tableDuplicateResultsList->rowCount() - 1, 2,
        new QTableWidgetItem(query2.value("path").toString()));
    ui->tableDuplicateResultsList->setItem(
        ui->tableDuplicateResultsList->rowCount() - 1, 3,
        new QTableWidgetItem(query2.value("size").toString()));
    ui->tableDuplicateResultsList->setItem(
        ui->tableDuplicateResultsList->rowCount() - 1, 4,
        new QTableWidgetItem(query2.value("checksum").toString()));
  } while (query2.next());
  //  ui->tableDuplicateResultsList->sortByColumn(3, Qt::DescendingOrder);
  ui->tableDuplicateResultsList->setSortingEnabled(true);
  ui->tableDuplicateResultsList->resizeColumnsToContents();
  ui->tableDuplicateResultsList->setColumnWidth(0, 90);
  ui->tableDuplicateResultsList->setColumnWidth(1, 350);
  ui->tableDuplicateResultsList->setColumnWidth(2, 700);
  ui->tableDuplicateResultsList->setColumnWidth(3, 150);
  ui->tableDuplicateResultsList->setColumnWidth(4, 100);

  qDebug() << "number of duplicate files processed is " << j;
  QSqlQuery query4;
  query4.prepare(qryCountOfUniqueChecksums);
  if (!query4.exec())
    qWarning() << "ERROR: " << query4.lastError().text();
  while (query4.next()) {
    ui->lbNumberOfUniqueDuplicateFiles->setText(
        query4.value("unique_count").toString() +
        "    Unique Files that are duplicates");
    numberOfUniqueFiles = query4.value("unique_count").toUInt();
  }
  qDebug() << ui->lbNumberOfUniqueDuplicateFiles->text();
  qDebug() << numberOfUniqueFiles;
  QSqlQuery query5;
  query5.prepare(qryCountDuplicates);
  if (!query5.exec())
    qWarning() << "ERROR: " << query5.lastError().text();
  while (query5.next()) {
    ui->lbNumberOfDuplicateFiles->setText(
        query5.value("count_duplicates").toString() +
        "    Files that are duplicates");
    numberOfDupFiles = query5.value("count_duplicates").toUInt();
  }
  qDebug() << ui->lbNumberOfDuplicateFiles->text();
  qDebug() << numberOfDupFiles;

  QSqlQuery query6;
  query6.prepare(qryCountFiles);
  if (!query6.exec())
    qWarning() << "ERROR: " << query6.lastError().text();
  while (query6.next()) {
    ui->lbNumberOfFiles->setText(query6.value("count_files").toString() +
                                 "   Total files in catalog   ");
    numberOfFiles = query6.value("count_files").toUInt();
  }
  qDebug() << ui->lbNumberOfFiles->text();
  qDebug() << numberOfFiles;

  db.exec("VACUUM");

  db.close();
  QApplication::restoreOverrideCursor();
  QApplication::processEvents();
}

void MomsDuplicateDeleter::on_pbSearch_clicked() {
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QApplication::processEvents();
  int totalFilesProcessedInThisSearch = 0;
  if (ui->cbFileType->currentIndex() == 0) {
    for (int i = 1; i < ui->cbFileType->count(); i++) {
      ui->cbFileType->setCurrentIndex(i);
      if (ui->cbFileType->currentText() != "*.*")
        totalFilesProcessedInThisSearch += searchForAndInsertFileType();
    }
    ui->cbFileType->setCurrentIndex(0);
  } else {
    totalFilesProcessedInThisSearch = searchForAndInsertFileType();
  }
  ui->lbNumberOfFiles->setText(
      "Total number of files processed (for this search) is " +
      QString::number(totalFilesProcessedInThisSearch));

  fillFilesTable();
  //  fillDirectoriesTable();
  QApplication::restoreOverrideCursor();
  QApplication::processEvents();
}
void MomsDuplicateDeleter::exportFiles2CSV() {
  const QString downloadsFolder =
      QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
  QString filters("CSV files (*.csv);;All files (*.*)");
  QString defaultFilter("CSV files (*.csv)");
  QString fileName =
      QFileDialog::getSaveFileName(0, "Save Plan List to CVS file",
                                   downloadsFolder, filters, &defaultFilter);
  if (fileName.isEmpty())
    return;
  QFile file(fileName);

  QAbstractItemModel *model = ui->tableDuplicateResultsList->model();
  if (file.open(QFile::WriteOnly | QFile::Truncate)) {
    QTextStream data(&file);
    QStringList strList;
    for (int i = 0; i < model->columnCount(); i++) {
      if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole)
              .toString()
              .length() > 0)
        strList.append(
            "\"" +
            model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() +
            "\"");
      else
        strList.append("");
    }
    data << strList.join(",") << "\n";
    for (int i = 0; i < model->rowCount(); i++) {
      strList.clear();
      for (int j = 0; j < model->columnCount(); j++) {

        if (model->data(model->index(i, j)).toString().length() > 0)
          strList.append("\"" + model->data(model->index(i, j)).toString() +
                         "\"");
        else
          strList.append("");
      }
      data << strList.join(",") + "\n";
    }
    file.close();
  }
}

int MomsDuplicateDeleter::searchForAndInsertFileType() {
  Crc32 crc;
  const QString DRIVER("QSQLITE");
  if (QSqlDatabase::isDriverAvailable(DRIVER))
    qDebug() << "database driver is installed";
  QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
  //     db.setDatabaseName(":memory:");
  db.setDatabaseName(databaseFilename);
  if (!db.open())
    qWarning() << "ERROR: " << db.lastError();
  QSqlQuery query(qryCreateFileTable);
  if (!query.isActive())
    qWarning() << "ERROR: " << query.lastError().text();
  if (!query.exec(qryCreateIndexes))
    qWarning() << "ERROR: " << query.lastError().text();
  QDirIterator it2(ui->lePathToSearch->text(),
                   QStringList() << ui->cbFileType->currentText(), QDir::Files,
                   QDirIterator::Subdirectories);
  int totalFilesToProcess = 0;
  while (it2.hasNext()) {
    totalFilesToProcess++;
    it2.next();
  }
  qDebug() << "number of files to process is " << totalFilesToProcess;
  QDirIterator it(ui->lePathToSearch->text(),
                  QStringList() << ui->cbFileType->currentText(), QDir::Files,
                  QDirIterator::Subdirectories);
  ui->progressBar->show();
  ui->progressBar->setFormat("Search progress for " +
                             ui->cbFileType->currentText() + " Start");
  ui->progressBar->setValue(0);
  QApplication::processEvents();

  int i = 1;
  while (it.hasNext()) {
    fileList.push_back(it.next());
    QFile file(it.filePath());
    if (file.open(QIODevice::ReadOnly)) {
      //      QByteArray data = file.readAll();
      //      easyexif::EXIFInfo info;
      //      if (int code =
      //              info.parseFrom((unsigned char *)data.data(), data.size()))
      //              {
      //        qDebug() << "Error parsing EXIF: code " << code << " for file "
      //                 << it.filePath();
      //        continue;
      //      }
      //      qDebug() << "Camera model         : " << info.Model.c_str();
      //      qDebug() << "Original date/time   : " <<
      //      info.DateTimeOriginal.c_str();

      //      qDebug() << "Camera make       :  " << info.Make.c_str();
      //      qDebug() << "Camera model      :  " << info.Model.c_str();
      //      qDebug() << "Software          :  " << info.Software.c_str();
      //      qDebug() << "Bits per sample   :  " << info.BitsPerSample;
      //      qDebug() << "Image width       :  " << info.ImageWidth;
      //      qDebug() << "Image height      :  " << info.ImageHeight;
      //      qDebug() << "Image description :  " <<
      //      info.ImageDescription.c_str(); qDebug() << "Image orientation :  "
      //      << info.Orientation; qDebug() << "Image copyright   :  " <<
      //      info.Copyright.c_str(); qDebug() << "Image date/time   :  " <<
      //      info.DateTime.c_str(); qDebug() << "Original date/time:  " <<
      //      info.DateTimeOriginal.c_str(); qDebug() << "Digitize date/time:  "
      //      << info.DateTimeDigitized.c_str(); qDebug() << "Subsecond time :
      //      " << info.SubSecTimeOriginal.c_str(); qDebug() << "Exposure time
      //      : " << (unsigned)(1.0 / info.ExposureTime); qDebug() << "F-stop :
      //      " << info.FNumber; qDebug() << "ISO speed         :  " <<
      //      info.ISOSpeedRatings; qDebug() << "Subject distance  : " <<
      //      info.SubjectDistance; qDebug() << "Exposure bias     : " <<
      //      info.ExposureBiasValue; qDebug() << "Flash used?       :  " <<
      //      info.Flash; qDebug() << "Metering mode     :  " <<
      //      info.MeteringMode; qDebug() << "Lens focal length : " <<
      //      info.FocalLength; qDebug() << "35mm focal length : " <<
      //      info.FocalLengthIn35mm; qDebug() << "GPS Latitude      : " <<
      //      info.GeoLocation.Latitude; qDebug() << "GPS Longitude     : " <<
      //      info.GeoLocation.Longitude; qDebug() << "GPS Altitude      : " <<
      //      info.GeoLocation.Altitude;
    } else
      qDebug() << "Can't open file:" << it.filePath();

    QString insertQuery(
        "INSERT INTO files(name, path, size, checksum) VALUES('");
    insertQuery.append(it.fileName().replace("'", "''"));
    insertQuery.append("', '");
    insertQuery.append(
        it.fileInfo().absoluteDir().absolutePath().replace("'", "''"));
    insertQuery.append("', ");
    insertQuery.append(QString::number(it.fileInfo().size()));
    insertQuery.append(", ");

    //         insertQuery.append(QString::number(ba.length()));
    insertQuery.append(QString::number(crc.calculateFromFile(it.filePath())));
    insertQuery.append(")");
    //    qDebug() << insertQuery;
    if (!query.exec(insertQuery))
      qWarning() << "ERROR: " << query.lastError().text();
    //        qDebug() << it.next();
    //      if (i % 200 == 0){
    //        qDebug() << "file processed is " << i;
    float progressFraction = ((i * 100) / totalFilesToProcess);
    //        qDebug() << "file progressFraction is " << progressFraction;
    ui->progressBar->setValue(int(progressFraction));
    ui->progressBar->setFormat("Search progress for " +
                               ui->cbFileType->currentText() + " is " +
                               QString::number(progressFraction) + "%");
    QApplication::processEvents();
    //      }
    i++;
  }
  qDebug() << "number of files processed is " << fileList.size();
  db.close();
  ui->progressBar->hide();
  return fileList.size();
}

void MomsDuplicateDeleter::on_pbRemoveDB_clicked() {
  QFile file(databaseFilename);
  file.remove();
  ui->lbNumberOfDuplicateFiles->setText("Database is empty");
  ui->lbNumberOfUniqueDuplicateFiles->setText("Database is empty");
  ui->lbNumberOfFiles->setText("Database is empty");
}

void MomsDuplicateDeleter::on_pbFillTablesFromDB_clicked() { fillFilesTable(); }

void MomsDuplicateDeleter::on_pbSimDelete_clicked() {
  deleteDuplicateFiles(true);
}

void MomsDuplicateDeleter::on_pbActualDelete_clicked() {
  if (ui->cbSimulateFlag->isChecked()) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this, "Simulating File Delete Operation",
        "Simulating Deleting duplicate files randomly.\nAre you sure you?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      deleteDuplicateFiles(true);
      fillFilesTable();
    } else {
      qDebug() << "Operation Cancelled";
    }
  }

  else {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this, "File Delete Operation",
        "Deleting duplicate files randomly.\nAre you sure you?",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      deleteDuplicateFiles(false);
      fillFilesTable();
    } else {
      qDebug() << "Operation Cancelled";
    }
  }
}

void MomsDuplicateDeleter::on_pbDeleteFromPath_clicked() {
  if (ui->tableDuplicateResultsList->currentRow() > -1) {
    if (ui->cbSimulateFlag->isChecked()) {
      QString sFilePath(
          ui->tableDuplicateResultsList
              ->item(ui->tableDuplicateResultsList->currentRow(), 2)
              ->text());
      QMessageBox::StandardButton reply;
      reply =
          QMessageBox::question(this, "Simulating File Delete Operation",
                                "Simulating Deleting duplicate files in\n " +
                                    sFilePath + "\nAre you sure you?",
                                QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        deleteDuplicateFilesFromPath(true);
        fillFilesTable();
      } else {
        qDebug() << "Operation Cancelled";
      }
    }

    else {
      QString sFilePath(
          ui->tableDuplicateResultsList
              ->item(ui->tableDuplicateResultsList->currentRow(), 2)
              ->text());
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "File Delete Operation",
                                    "Deleting duplicate files in\n " +
                                        sFilePath + "\nAre you sure you?",
                                    QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        deleteDuplicateFilesFromPath(false);
        fillFilesTable();
      } else {
        qDebug() << "Operation Cancelled";
      }
    }
  } else
    QMessageBox::information(0, "No Row Selected",
                             "Please select a row with the File Path of the "
                             "duplicates you want to delete. ");
}
void MomsDuplicateDeleter::deleteDuplicateFilesFromPathAndBelow(bool simulatedFlag) {
    if (ui->leUserSubPath->text() != "") {
    unsigned int j = 0;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->progressBar->show();
    ui->progressBar->setFormat("Starting delete operation ");
    ui->progressBar->setValue(0);

    QApplication::processEvents();
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER))
      qDebug() << "database driver is installed";
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    //     db.setDatabaseName(":memory:");
    db.setDatabaseName(databaseFilename);
    if (!db.open())
      qWarning() << "ERROR: " << db.lastError();
    db.transaction();
    unsigned int uniqueFileCount = 0;
    qint64 totalSize = 0;
    QSqlQuery query4;
    QString sFilePath(ui->leUserSubPath->text());
    QString tempQuery(qryCountOfUniqueChecksumsInPathAndBelow);
    tempQuery.replace(":filePath", sFilePath);
    qWarning() << "query used " << tempQuery;
    query4.prepare(tempQuery);
    do {
      if (!query4.exec())
        qWarning() << "ERROR: " << query4.lastError().text();
      while (query4.next()) {
        uniqueFileCount = query4.value("unique_count").toUInt();
      }
      if (uniqueFileCount > 0) {
        QSqlQuery query2;

        QString tempQuery2(qryIDRandomDuplicatesFromPathAndBelow);
        tempQuery2.replace(":filePath", sFilePath);
        //      qWarning() << "query used " << tempQuery2;
        query2.prepare(tempQuery2);
        if (!query2.exec())
          qWarning() << "ERROR: " << query2.lastError().text();
        unsigned int uniqueFileID = 0;
        while (query2.next()) {
          uniqueFileID = query2.value("id").toUInt();
          totalSize += query2.value("size").toUInt();
        }
        QSqlQuery query6;
        query6.prepare(qryFilePath + QString::number(uniqueFileID));
        if (!query6.exec())
          qWarning() << "ERROR: " << query6.lastError().text();
        QString fileToBeDeleted;
        while (query6.next()) {
          fileToBeDeleted.append(query6.value("path").toString());
          fileToBeDeleted.append("/");
          fileToBeDeleted.append(query6.value("name").toString());
          QSqlQuery query5;
          query5.prepare(qryDeleteFileByID + QString::number(uniqueFileID));
          if (!query5.exec())
            qWarning() << "ERROR: " << query5.lastError().text();
          else {
            //       qDebug() << "rows affected is  " <<
            //       query5.numRowsAffected();
            if (!simulatedFlag) {
              QFile removeFile(fileToBeDeleted);
              if (!removeFile.setPermissions(QFile::ReadOther |
                                             QFile::WriteOther)) {
                qWarning() << "ERROR: setting permissions  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();
              }
              if (!removeFile.remove()) {
                qWarning() << "ERROR: Removing file  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();

              } else
                qDebug() << "File deleted is " << fileToBeDeleted;
            }
          }
          if (j % 200 == 0) {
            float progressFraction = (j % 99);
            ui->progressBar->setValue(int(progressFraction));
            ui->progressBar->setFormat("Deleted progress is " +
                                       QString::number(progressFraction) + "%");
            QApplication::processEvents();
          }

          j++;
        }
      }
    } while (uniqueFileCount > 0);
    qDebug() << "number of files that have been deleted " << j;
    if (!simulatedFlag) {
      db.commit();
    } else
      db.rollback();
    db.exec("VACUUM");
    db.close();
    QApplication::restoreOverrideCursor();
    ui->progressBar->hide();
    QApplication::processEvents();
    if (!simulatedFlag) {
      QMessageBox::information(
          0, "Delete Operation Stats",
          QString::number(j) + " File(s) - Total number of file(s) deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space Reclaimed ");
    } else {
      QMessageBox::information(
          0, "Simulated Delete Operation Stats",
          QString::number(j) +
              " File(s) - Total number of file(s) that would be deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space that would be Reclaimed ");
    }
  } else
        QMessageBox::information(0, "No Path Entered",
                                 "Please enter a Directory/Folder Path of the "
                                 "duplicates you want to delete in the line below this button.  \nThis will also delete the duplicates in all Directory/Folders under the specified path. ");
  }

void MomsDuplicateDeleter::deleteDuplicateFilesFromPath(bool simulatedFlag) {
  if (ui->tableDuplicateResultsList->currentRow() > -1) {
    unsigned int j = 0;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->progressBar->show();
    ui->progressBar->setFormat("Starting delete operation ");
    ui->progressBar->setValue(0);

    QApplication::processEvents();
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER))
      qDebug() << "database driver is installed";
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    //     db.setDatabaseName(":memory:");
    db.setDatabaseName(databaseFilename);
    if (!db.open())
      qWarning() << "ERROR: " << db.lastError();
    db.transaction();
    unsigned int uniqueFileCount = 0;
    qint64 totalSize = 0;
    QSqlQuery query4;
    QString sFilePath(ui->tableDuplicateResultsList
                          ->item(ui->tableDuplicateResultsList->currentRow(), 2)
                          ->text());

    QString tempQuery(qryCountOfUniqueChecksumsInPath);
    tempQuery.replace(":filePath", sFilePath);
    //  qWarning() << "query used " << tempQuery;
    query4.prepare(tempQuery);
    do {
      if (!query4.exec())
        qWarning() << "ERROR: " << query4.lastError().text();
      while (query4.next()) {
        uniqueFileCount = query4.value("unique_count").toUInt();
      }
      if (uniqueFileCount > 0) {
        QSqlQuery query2;

        QString tempQuery2(qryIDRandomDuplicatesFromPath);
        tempQuery2.replace(":filePath", sFilePath);
        //      qWarning() << "query used " << tempQuery2;
        query2.prepare(tempQuery2);
        if (!query2.exec())
          qWarning() << "ERROR: " << query2.lastError().text();
        unsigned int uniqueFileID = 0;
        while (query2.next()) {
          uniqueFileID = query2.value("id").toUInt();
          totalSize += query2.value("size").toUInt();
        }
        QSqlQuery query6;
        query6.prepare(qryFilePath + QString::number(uniqueFileID));
        if (!query6.exec())
          qWarning() << "ERROR: " << query6.lastError().text();
        QString fileToBeDeleted;
        while (query6.next()) {
          fileToBeDeleted.append(query6.value("path").toString());
          fileToBeDeleted.append("/");
          fileToBeDeleted.append(query6.value("name").toString());
          QSqlQuery query5;
          query5.prepare(qryDeleteFileByID + QString::number(uniqueFileID));
          if (!query5.exec())
            qWarning() << "ERROR: " << query5.lastError().text();
          else {
            //       qDebug() << "rows affected is  " <<
            //       query5.numRowsAffected();
            if (!simulatedFlag) {
              QFile removeFile(fileToBeDeleted);
              if (!removeFile.setPermissions(QFile::ReadOther |
                                             QFile::WriteOther)) {
                qWarning() << "ERROR: setting permissions  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();
              }
              if (!removeFile.remove()) {
                qWarning() << "ERROR: Removing file  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();

              } else
                qDebug() << "File deleted is " << fileToBeDeleted;
            }
            //       else   qDebug() << "File that would have been deleted is "
            //                   << fileToBeDeleted;
            //            qDebug() << "random file id result value " <<
            //            uniqueFileID;
          }
          if (j % 200 == 0) {
            float progressFraction = (j % 99);
            ui->progressBar->setValue(int(progressFraction));
            ui->progressBar->setFormat("Deleted progress is " +
                                       QString::number(progressFraction) + "%");
            QApplication::processEvents();
          }

          j++;
        }
      }
    } while (uniqueFileCount > 0);
    qDebug() << "number of files that have been deleted " << j;
    if (!simulatedFlag) {
      db.commit();
    } else
      db.rollback();
    db.exec("VACUUM");
    db.close();
    QApplication::restoreOverrideCursor();
    ui->progressBar->hide();
    QApplication::processEvents();
    if (!simulatedFlag) {
      QMessageBox::information(
          0, "Delete Operation Stats",
          QString::number(j) + " File(s) - Total number of file(s) deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space Reclaimed ");
    } else {
      QMessageBox::information(
          0, "Simulated Delete Operation Stats",
          QString::number(j) +
              " File(s) - Total number of file(s) that would be deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space that would be Reclaimed ");
    }
  } else
    QMessageBox::information(0, "No Row Selected",
                             "Please select a row with the File Path of the "
                             "duplicates you want to delete. ");
}


void MomsDuplicateDeleter::deleteDuplicateFilesNotInPath(bool simulatedFlag) {
  if (ui->tableDuplicateResultsList->currentRow() > -1) {
    unsigned int j = 0;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->progressBar->show();
    ui->progressBar->setFormat("Starting delete operation ");
    ui->progressBar->setValue(0);

    QApplication::processEvents();
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER))
      qDebug() << "database driver is installed";
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    //     db.setDatabaseName(":memory:");
    db.setDatabaseName(databaseFilename);
    if (!db.open())
      qWarning() << "ERROR: " << db.lastError();
    db.transaction();
    unsigned int uniqueFileCount = 0;
    qint64 totalSize = 0;
    QSqlQuery query4;
    QString sFilePath(ui->tableDuplicateResultsList
                          ->item(ui->tableDuplicateResultsList->currentRow(), 2)
                          ->text());

    QString tempQuery(qryCountOfUniqueChecksumsNotInPath);
    tempQuery.replace(":filePath", sFilePath);
    query4.prepare(tempQuery);
    do {
      if (!query4.exec())
        qWarning() << "ERROR: " << query4.lastError().text();
      while (query4.next()) {
        uniqueFileCount = query4.value("unique_count").toUInt();
      }
      if (uniqueFileCount > 0) {
        QSqlQuery query2;

        QString tempQuery2(qryIDRandomDuplicatesNotInPath);
        tempQuery2.replace(":filePath", sFilePath);
        //        qWarning() << "query used " << tempQuery2;
        query2.prepare(tempQuery2);
        if (!query2.exec())
          qWarning() << "ERROR: " << query2.lastError().text();
        unsigned int uniqueFileID = 0;
        while (query2.next()) {
          uniqueFileID = query2.value("id").toUInt();
          totalSize += query2.value("size").toUInt();
        }
        query2.clear();
        QSqlQuery query6;
        query6.prepare(qryFilePath + QString::number(uniqueFileID));
        if (!query6.exec())
          qWarning() << "ERROR: " << query6.lastError().text();
        QString fileToBeDeleted;
        while (query6.next()) {
          fileToBeDeleted.append(query6.value("path").toString());
          fileToBeDeleted.append("/");
          fileToBeDeleted.append(query6.value("name").toString());
          QSqlQuery query5;
          query5.prepare(qryDeleteFileByID + QString::number(uniqueFileID));
          if (!query5.exec())
            qWarning() << "ERROR: " << query5.lastError().text();
          else {
            //       qDebug() << "rows affected is  " <<
            //       query5.numRowsAffected();
            if (!simulatedFlag) {
              QFile removeFile(fileToBeDeleted);
              if (!removeFile.setPermissions(QFile::ReadOther |
                                             QFile::WriteOther)) {
                qWarning() << "ERROR: setting permissions  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();
              }
              if (!removeFile.remove()) {
                qWarning() << "ERROR: Removing file  " << fileToBeDeleted;
                qWarning() << "ERROR:  " << removeFile.errorString();
              }
              //       else     qDebug() << "File deleted is " <<
              //       fileToBeDeleted;
            }
            //        else  qDebug() << "File that would have been deleted is "
            //                   << fileToBeDeleted;
            //            qDebug() << "random file id result value " <<
            //            uniqueFileID;
          }
          if (j % 200 == 0) {
            float progressFraction = (j % 99);
            ui->progressBar->setValue(int(progressFraction));
            ui->progressBar->setFormat("Deleted progress is " +
                                       QString::number(progressFraction) + "%");
            QApplication::processEvents();
          }

          j++;
        }
      }
    } while (uniqueFileCount > 0);
    qDebug() << "number of files that have been deleted " << j;
    if (!simulatedFlag) {
      db.commit();
    } else
      db.rollback();
    db.exec("VACUUM");
    db.close();
    QApplication::restoreOverrideCursor();
    ui->progressBar->hide();
    QApplication::processEvents();
    if (!simulatedFlag) {
      QMessageBox::information(
          0, "Delete Operation Stats",
          QString::number(j) + " File(s) - Total number of file(s) deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space Reclaimed ");
    } else {
      QMessageBox::information(
          0, "Simulated Delete Operation Stats",
          QString::number(j) +
              " File(s) - Total number of file(s) that would be deleted\n" +
              QString::number(totalSize / 1000000) +
              " MB - Total Space that would be Reclaimed ");
    }

  } else
    QMessageBox::information(
        0, "No Row Selected",
        "Please select a row with the File Path of the duplicates you want to "
        "keep. \nThis will delete the duplicates from all other File Paths "
        "that contain duplicated in this path.");
}

void MomsDuplicateDeleter::on_pbKeepInPath_clicked() {
  if (ui->tableDuplicateResultsList->currentRow() > -1) {
    if (ui->cbSimulateFlag->isChecked()) {
      QString sFilePath(
          ui->tableDuplicateResultsList
              ->item(ui->tableDuplicateResultsList->currentRow(), 2)
              ->text());
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(
          this, "Simulating File Delete Operation",
          "Simulating deleting duplicate files not in\n " + sFilePath +
              "\nAre you sure you?",
          QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        deleteDuplicateFilesNotInPath(true);
        fillFilesTable();
      } else {
        qDebug() << "Operation Cancelled";
      }
    } else {
      QString sFilePath(
          ui->tableDuplicateResultsList
              ->item(ui->tableDuplicateResultsList->currentRow(), 2)
              ->text());
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "File Delete Operation",
                                    "Deleting duplicate files not in\n " +
                                        sFilePath + "\nAre you sure you?",
                                    QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        deleteDuplicateFilesNotInPath(false);
        fillFilesTable();
      } else {
        qDebug() << "Operation Cancelled";
      }
    }
  } else
    QMessageBox::information(
        0, "No Row Selected",
        "Please select a row with the File Path of the duplicates you want to "
        "keep. \nThis will delete the duplicates from all other File Paths "
        "that contain duplicated in this path.");
}

// void MomsDuplicateDeleter::DBConnect(){

//}

void MomsDuplicateDeleter::on_pbDeleteSingle_clicked()
{
    if (ui->tableDuplicateResultsList->currentRow() > -1) {
        QString sFilePath(
            ui->tableDuplicateResultsList
                ->item(ui->tableDuplicateResultsList->currentRow(), 2)
                ->text());
        sFilePath.append("/"+ ui->tableDuplicateResultsList
                         ->item(ui->tableDuplicateResultsList->currentRow(),1)
                         ->text() );
         QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "File Delete Operation",
                                      "Deleting duplicate file \n " +
                                          sFilePath + "\nAre you sure you?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            deleteSingleFile(ui->cbSimulateFlag->isChecked());
           fillFilesTable();
        } else {
          qDebug() << "Operation Cancelled";
        }

    } else
      QMessageBox::information(0, "No Row Selected",
                               "Please select a row with the "
                               "duplicate you want to delete. ");
}

void MomsDuplicateDeleter::deleteSingleFile(bool simulatedFlag){
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER))
      qDebug() << "database driver is installed";
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    //     db.setDatabaseName(":memory:");
    db.setDatabaseName(databaseFilename);
    if (!db.open())
      qWarning() << "ERROR: " << db.lastError();
    db.transaction();
    QString sFilePath(
        ui->tableDuplicateResultsList
            ->item(ui->tableDuplicateResultsList->currentRow(), 2)
            ->text());
    sFilePath.append("/"+ ui->tableDuplicateResultsList
                     ->item(ui->tableDuplicateResultsList->currentRow(),1)
                     ->text() );
    QSqlQuery query5;
    query5.prepare(qryDeleteFileByID + QString::number(ui->tableDuplicateResultsList->item(ui->tableDuplicateResultsList->currentRow(),0)->text().toInt()));
    if (!query5.exec())
      qWarning() << "ERROR: " << query5.lastError().text();
    //        qDebug() << "rows affected is  " << query5.numRowsAffected();
    else {
             qDebug() << "rows affected is  " <<
             query5.numRowsAffected();
      if (!simulatedFlag) {
        QFile removeFile(sFilePath);
        if (!removeFile.setPermissions(QFile::ReadOther |
                                       QFile::WriteOther)) {
          qWarning() << "ERROR: setting permissions  " << sFilePath;
          qWarning() << "ERROR:  " << removeFile.errorString();
        }
        if (!removeFile.remove()) {
          qWarning() << "ERROR: Removing file  " << sFilePath;
          qWarning() << "ERROR:  " << removeFile.errorString();
        }
        else  qDebug() << "file Deleted was " <<
                  sFilePath;

      }
    }
 if (!simulatedFlag) {
db.commit();
} else db.rollback();
db.exec("VACUUM");
db.close();
if (!simulatedFlag) {
QMessageBox::information(
    0, "Delete Operation Stats", sFilePath + " file deleted");
} else {
QMessageBox::information(
    0, "Simulated Delete Operation Stats",sFilePath + " would have been file deleted");



}
fillFilesTable();
}

void MomsDuplicateDeleter::on_pbDeleteFromPathBelow_clicked()
{
    if (ui->leUserSubPath->text() != "") {
      if (ui->cbSimulateFlag->isChecked()) {
        QString sFilePath(ui->leUserSubPath->text());
        QMessageBox::StandardButton reply;
        reply =
            QMessageBox::question(this, "Simulating File Delete Operation",
                                  "Simulating Deleting duplicate files in\n " +
                                      sFilePath + " and below.\nAre you sure you?",
                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          deleteDuplicateFilesFromPathAndBelow(true);
          fillFilesTable();
        } else {
          qDebug() << "Operation Cancelled";
        }
      }

      else {
        QString sFilePath(ui->leUserSubPath->text());
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "File Delete Operation",
                                      "Deleting duplicate files in\n " +
                                          sFilePath + " and below.\nAre you sure you?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          deleteDuplicateFilesFromPathAndBelow(false);
          fillFilesTable();
        } else {
          qDebug() << "Operation Cancelled";
        }
      }
    } else
      QMessageBox::information(0, "No Path Entered",
                               "Please enter a Directory/Folder Path of the "
                               "duplicates you want to delete in the line below this button.  \nThis will also delete the duplicates in all Directory/Folders under the specified path. ");

}

void MomsDuplicateDeleter::on_pbViewImage_clicked()
{
    if (ui->tableDuplicateResultsList->currentRow() > -1) {
        QString sFilePath(
            ui->tableDuplicateResultsList
                ->item(ui->tableDuplicateResultsList->currentRow(), 2)
                ->text());
        sFilePath.append("/"+ ui->tableDuplicateResultsList
                         ->item(ui->tableDuplicateResultsList->currentRow(),1)
                         ->text() );
        imageViewer.show();
        imageViewer.loadFile(sFilePath);
        imageViewer.setVisible(true);

    } else
      QMessageBox::information(0, "No Row Selected",
                               "Please select a row with the "
                               "image file you want to view. ");

}

void MomsDuplicateDeleter::on_pbViewMovie_clicked()
{
    if (ui->tableDuplicateResultsList->currentRow() > -1) {
        QString sFilePath(
            ui->tableDuplicateResultsList
                ->item(ui->tableDuplicateResultsList->currentRow(), 2)
                ->text());
        sFilePath.append("/"+ ui->tableDuplicateResultsList
                         ->item(ui->tableDuplicateResultsList->currentRow(),1)
                         ->text() );
        QString sMovieCommand("mvp ");
        sMovieCommand.append(sFilePath);
        QProcess::execute(sMovieCommand);

    } else
      QMessageBox::information(0, "No Row Selected",
                               "Please select a row with the "
                               "video file you want to view. ");


}
