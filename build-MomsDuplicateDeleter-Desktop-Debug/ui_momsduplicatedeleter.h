/********************************************************************************
** Form generated from reading UI file 'momsduplicatedeleter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOMSDUPLICATEDELETER_H
#define UI_MOMSDUPLICATEDELETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MomsDuplicateDeleter
{
public:
    QWidget *centralwidget;
    QPushButton *pbExportFilesList2CSV;
    QComboBox *cbFileType;
    QPushButton *pbFillTablesFromDB;
    QPushButton *pbDeleteFromPath;
    QPushButton *pbKeepInPath;
    QPushButton *pbSimDelete;
    QLabel *lbNumberOfUniqueDuplicateFiles;
    QLabel *lbNumberOfFiles;
    QPushButton *pbSelectDirectory;
    QPushButton *pbSearch;
    QPushButton *pbRemoveDB;
    QPushButton *pbActualDelete;
    QLabel *lbNumberOfDuplicateFiles;
    QLineEdit *lePathToSearch;
    QTableWidget *tableDuplicateResultsList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MomsDuplicateDeleter)
    {
        if (MomsDuplicateDeleter->objectName().isEmpty())
            MomsDuplicateDeleter->setObjectName(QString::fromUtf8("MomsDuplicateDeleter"));
        MomsDuplicateDeleter->resize(1516, 600);
        centralwidget = new QWidget(MomsDuplicateDeleter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pbExportFilesList2CSV = new QPushButton(centralwidget);
        pbExportFilesList2CSV->setObjectName(QString::fromUtf8("pbExportFilesList2CSV"));
        pbExportFilesList2CSV->setGeometry(QRect(1220, 110, 61, 21));
        QFont font;
        font.setPointSize(10);
        pbExportFilesList2CSV->setFont(font);
        cbFileType = new QComboBox(centralwidget);
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->setObjectName(QString::fromUtf8("cbFileType"));
        cbFileType->setGeometry(QRect(380, 40, 73, 22));
        cbFileType->setFont(font);
        pbFillTablesFromDB = new QPushButton(centralwidget);
        pbFillTablesFromDB->setObjectName(QString::fromUtf8("pbFillTablesFromDB"));
        pbFillTablesFromDB->setGeometry(QRect(180, 0, 231, 28));
        pbFillTablesFromDB->setFont(font);
        pbDeleteFromPath = new QPushButton(centralwidget);
        pbDeleteFromPath->setObjectName(QString::fromUtf8("pbDeleteFromPath"));
        pbDeleteFromPath->setGeometry(QRect(300, 80, 221, 28));
        pbDeleteFromPath->setFont(font);
        pbKeepInPath = new QPushButton(centralwidget);
        pbKeepInPath->setObjectName(QString::fromUtf8("pbKeepInPath"));
        pbKeepInPath->setGeometry(QRect(580, 80, 221, 28));
        pbKeepInPath->setFont(font);
        pbSimDelete = new QPushButton(centralwidget);
        pbSimDelete->setObjectName(QString::fromUtf8("pbSimDelete"));
        pbSimDelete->setGeometry(QRect(600, 10, 151, 28));
        pbSimDelete->setFont(font);
        lbNumberOfUniqueDuplicateFiles = new QLabel(centralwidget);
        lbNumberOfUniqueDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfUniqueDuplicateFiles"));
        lbNumberOfUniqueDuplicateFiles->setGeometry(QRect(820, 120, 391, 16));
        lbNumberOfUniqueDuplicateFiles->setFont(font);
        lbNumberOfFiles = new QLabel(centralwidget);
        lbNumberOfFiles->setObjectName(QString::fromUtf8("lbNumberOfFiles"));
        lbNumberOfFiles->setGeometry(QRect(30, 120, 401, 16));
        lbNumberOfFiles->setFont(font);
        pbSelectDirectory = new QPushButton(centralwidget);
        pbSelectDirectory->setObjectName(QString::fromUtf8("pbSelectDirectory"));
        pbSelectDirectory->setGeometry(QRect(340, 40, 31, 31));
        pbSelectDirectory->setFont(font);
        pbSearch = new QPushButton(centralwidget);
        pbSearch->setObjectName(QString::fromUtf8("pbSearch"));
        pbSearch->setGeometry(QRect(460, 40, 101, 23));
        pbSearch->setFont(font);
        pbRemoveDB = new QPushButton(centralwidget);
        pbRemoveDB->setObjectName(QString::fromUtf8("pbRemoveDB"));
        pbRemoveDB->setGeometry(QRect(30, 0, 93, 28));
        pbRemoveDB->setFont(font);
        pbActualDelete = new QPushButton(centralwidget);
        pbActualDelete->setObjectName(QString::fromUtf8("pbActualDelete"));
        pbActualDelete->setGeometry(QRect(30, 80, 141, 28));
        pbActualDelete->setFont(font);
        lbNumberOfDuplicateFiles = new QLabel(centralwidget);
        lbNumberOfDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfDuplicateFiles"));
        lbNumberOfDuplicateFiles->setGeometry(QRect(430, 120, 281, 16));
        lbNumberOfDuplicateFiles->setFont(font);
        lePathToSearch = new QLineEdit(centralwidget);
        lePathToSearch->setObjectName(QString::fromUtf8("lePathToSearch"));
        lePathToSearch->setEnabled(true);
        lePathToSearch->setGeometry(QRect(30, 40, 301, 31));
        lePathToSearch->setFont(font);
        tableDuplicateResultsList = new QTableWidget(centralwidget);
        tableDuplicateResultsList->setObjectName(QString::fromUtf8("tableDuplicateResultsList"));
        tableDuplicateResultsList->setGeometry(QRect(30, 140, 1381, 471));
        tableDuplicateResultsList->setFont(font);
        tableDuplicateResultsList->setSortingEnabled(true);
        MomsDuplicateDeleter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MomsDuplicateDeleter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1516, 22));
        MomsDuplicateDeleter->setMenuBar(menubar);
        statusbar = new QStatusBar(MomsDuplicateDeleter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MomsDuplicateDeleter->setStatusBar(statusbar);

        retranslateUi(MomsDuplicateDeleter);

        QMetaObject::connectSlotsByName(MomsDuplicateDeleter);
    } // setupUi

    void retranslateUi(QMainWindow *MomsDuplicateDeleter)
    {
        MomsDuplicateDeleter->setWindowTitle(QApplication::translate("MomsDuplicateDeleter", "Mom's Duplicate Deleter", nullptr));
#ifndef QT_NO_TOOLTIP
        pbExportFilesList2CSV->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">Save Plan List to CVS file</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbExportFilesList2CSV->setText(QApplication::translate("MomsDuplicateDeleter", "Export", nullptr));
        cbFileType->setItemText(0, QApplication::translate("MomsDuplicateDeleter", "*.", nullptr));
        cbFileType->setItemText(1, QApplication::translate("MomsDuplicateDeleter", "*.jpg", nullptr));
        cbFileType->setItemText(2, QApplication::translate("MomsDuplicateDeleter", "*.mpg", nullptr));
        cbFileType->setItemText(3, QApplication::translate("MomsDuplicateDeleter", "*.mp4", nullptr));
        cbFileType->setItemText(4, QApplication::translate("MomsDuplicateDeleter", "*.mpeg", nullptr));
        cbFileType->setItemText(5, QApplication::translate("MomsDuplicateDeleter", "*.avi", nullptr));
        cbFileType->setItemText(6, QApplication::translate("MomsDuplicateDeleter", "*.jpeg", nullptr));
        cbFileType->setItemText(7, QApplication::translate("MomsDuplicateDeleter", "*.mov", nullptr));
        cbFileType->setItemText(8, QApplication::translate("MomsDuplicateDeleter", "*.bmp", nullptr));

        pbFillTablesFromDB->setText(QApplication::translate("MomsDuplicateDeleter", "Load Current Duplicates List", nullptr));
        pbDeleteFromPath->setText(QApplication::translate("MomsDuplicateDeleter", "Delete from Path Chosen", nullptr));
        pbKeepInPath->setText(QApplication::translate("MomsDuplicateDeleter", "Keep in Path Chosen", nullptr));
        pbSimDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Simulate Delete", nullptr));
        lbNumberOfUniqueDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of Unique Files that are duplicates", nullptr));
        lbNumberOfFiles->setText(QApplication::translate("MomsDuplicateDeleter", "No Search Performed...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSelectDirectory->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button allows you to select a directory to search for duplicates in.  This will also search in it's subdirectories.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSelectDirectory->setText(QApplication::translate("MomsDuplicateDeleter", "...", nullptr));
        pbSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Search", nullptr));
        pbRemoveDB->setText(QApplication::translate("MomsDuplicateDeleter", "Start Over", nullptr));
        pbActualDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Actual Delete", nullptr));
        lbNumberOfDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of files that are duplicate", nullptr));
        lePathToSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Choose a directory to search for duplicates in.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MomsDuplicateDeleter: public Ui_MomsDuplicateDeleter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOMSDUPLICATEDELETER_H
