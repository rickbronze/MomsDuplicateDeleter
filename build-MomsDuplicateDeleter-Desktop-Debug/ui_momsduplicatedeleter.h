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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QProgressBar *progressBar;
    QLineEdit *leUserSubPath;
    QCheckBox *cbSimulateFlag;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MomsDuplicateDeleter)
    {
        if (MomsDuplicateDeleter->objectName().isEmpty())
            MomsDuplicateDeleter->setObjectName(QString::fromUtf8("MomsDuplicateDeleter"));
        MomsDuplicateDeleter->resize(1516, 600);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("MDD");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Normal, QIcon::On);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Disabled, QIcon::Off);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Disabled, QIcon::On);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Active, QIcon::Off);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Active, QIcon::On);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Selected, QIcon::Off);
            icon.addFile(QString::fromUtf8(":/MomsDuplicateDeleterIcon.png"), QSize(), QIcon::Selected, QIcon::On);
        }
        MomsDuplicateDeleter->setWindowIcon(icon);
        centralwidget = new QWidget(MomsDuplicateDeleter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pbExportFilesList2CSV = new QPushButton(centralwidget);
        pbExportFilesList2CSV->setObjectName(QString::fromUtf8("pbExportFilesList2CSV"));
        pbExportFilesList2CSV->setGeometry(QRect(1220, 140, 141, 21));
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
        pbDeleteFromPath->setGeometry(QRect(290, 90, 251, 51));
        pbDeleteFromPath->setFont(font);
        pbKeepInPath = new QPushButton(centralwidget);
        pbKeepInPath->setObjectName(QString::fromUtf8("pbKeepInPath"));
        pbKeepInPath->setGeometry(QRect(30, 90, 221, 51));
        pbKeepInPath->setFont(font);
        pbSimDelete = new QPushButton(centralwidget);
        pbSimDelete->setObjectName(QString::fromUtf8("pbSimDelete"));
        pbSimDelete->setGeometry(QRect(1360, 520, 151, 28));
        pbSimDelete->setFont(font);
        lbNumberOfUniqueDuplicateFiles = new QLabel(centralwidget);
        lbNumberOfUniqueDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfUniqueDuplicateFiles"));
        lbNumberOfUniqueDuplicateFiles->setGeometry(QRect(820, 150, 391, 16));
        lbNumberOfUniqueDuplicateFiles->setFont(font);
        lbNumberOfFiles = new QLabel(centralwidget);
        lbNumberOfFiles->setObjectName(QString::fromUtf8("lbNumberOfFiles"));
        lbNumberOfFiles->setGeometry(QRect(30, 150, 401, 16));
        lbNumberOfFiles->setFont(font);
        pbSelectDirectory = new QPushButton(centralwidget);
        pbSelectDirectory->setObjectName(QString::fromUtf8("pbSelectDirectory"));
        pbSelectDirectory->setGeometry(QRect(340, 40, 31, 31));
        pbSelectDirectory->setFont(font);
        pbSearch = new QPushButton(centralwidget);
        pbSearch->setObjectName(QString::fromUtf8("pbSearch"));
        pbSearch->setGeometry(QRect(470, 40, 101, 23));
        pbSearch->setFont(font);
        pbRemoveDB = new QPushButton(centralwidget);
        pbRemoveDB->setObjectName(QString::fromUtf8("pbRemoveDB"));
        pbRemoveDB->setGeometry(QRect(30, 0, 93, 28));
        pbRemoveDB->setFont(font);
        pbActualDelete = new QPushButton(centralwidget);
        pbActualDelete->setObjectName(QString::fromUtf8("pbActualDelete"));
        pbActualDelete->setGeometry(QRect(590, 90, 201, 51));
        pbActualDelete->setFont(font);
        lbNumberOfDuplicateFiles = new QLabel(centralwidget);
        lbNumberOfDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfDuplicateFiles"));
        lbNumberOfDuplicateFiles->setGeometry(QRect(430, 150, 281, 16));
        lbNumberOfDuplicateFiles->setFont(font);
        lePathToSearch = new QLineEdit(centralwidget);
        lePathToSearch->setObjectName(QString::fromUtf8("lePathToSearch"));
        lePathToSearch->setEnabled(true);
        lePathToSearch->setGeometry(QRect(30, 40, 301, 31));
        lePathToSearch->setFont(font);
        tableDuplicateResultsList = new QTableWidget(centralwidget);
        tableDuplicateResultsList->setObjectName(QString::fromUtf8("tableDuplicateResultsList"));
        tableDuplicateResultsList->setGeometry(QRect(30, 170, 1381, 471));
        tableDuplicateResultsList->setFont(font);
        tableDuplicateResultsList->setSortingEnabled(true);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(430, 230, 621, 81));
        progressBar->setValue(0);
        leUserSubPath = new QLineEdit(centralwidget);
        leUserSubPath->setObjectName(QString::fromUtf8("leUserSubPath"));
        leUserSubPath->setGeometry(QRect(1170, 70, 113, 25));
        cbSimulateFlag = new QCheckBox(centralwidget);
        cbSimulateFlag->setObjectName(QString::fromUtf8("cbSimulateFlag"));
        cbSimulateFlag->setGeometry(QRect(850, 100, 231, 23));
        cbSimulateFlag->setChecked(true);
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
        pbExportFilesList2CSV->setText(QApplication::translate("MomsDuplicateDeleter", "Export File List", nullptr));
        cbFileType->setItemText(0, QApplication::translate("MomsDuplicateDeleter", "*.", nullptr));
        cbFileType->setItemText(1, QApplication::translate("MomsDuplicateDeleter", "*.jpg", nullptr));
        cbFileType->setItemText(2, QApplication::translate("MomsDuplicateDeleter", "*.mpg", nullptr));
        cbFileType->setItemText(3, QApplication::translate("MomsDuplicateDeleter", "*.mp4", nullptr));
        cbFileType->setItemText(4, QApplication::translate("MomsDuplicateDeleter", "*.mpeg", nullptr));
        cbFileType->setItemText(5, QApplication::translate("MomsDuplicateDeleter", "*.avi", nullptr));
        cbFileType->setItemText(6, QApplication::translate("MomsDuplicateDeleter", "*.jpeg", nullptr));
        cbFileType->setItemText(7, QApplication::translate("MomsDuplicateDeleter", "*.mov", nullptr));
        cbFileType->setItemText(8, QApplication::translate("MomsDuplicateDeleter", "*.bmp", nullptr));
        cbFileType->setItemText(9, QApplication::translate("MomsDuplicateDeleter", "*.*", nullptr));

#ifndef QT_NO_TOOLTIP
        cbFileType->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This pull-down allows you to select particular file extensions to use in the search.  This relates to the type of file, mainly pictures and movies of different common formats.</p><p>If you leave it alone, it will search for each extension in the list, except for the *.*.   If you want to scan more that one, but not the whole list, then choose one, then hit search, after it completes, choose another one, then hit search, ....repeat until all desired extentions have been searched for.</p><p>If you want to scan all files regardless of extention, then select the *.* entry of the list.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbFillTablesFromDB->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Load Current Duplicates List button will load the list from the database.   This is a way to come back to where you left off and the program ASSUMES  that you din't change any files on your own.  This is very important if you have changed the files, on your own, but still have stale information in the list and you may lose you only copy of a file...  When in doubt, use the Start Over button instead.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbFillTablesFromDB->setText(QApplication::translate("MomsDuplicateDeleter", "Load Current Duplicates List", nullptr));
#ifndef QT_NO_TOOLTIP
        pbDeleteFromPath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder column, of the item selected in the list, and delete those files.</p><p>For instance, I have copies of my phone pictures several times over the years and they are duplicates of ones that I have already brought over before and sorted through.  Using this button, it will remove all the duplicates in that directory/folder, and then I can sort through what it left, knowing they are not duplicated elsewhere.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbDeleteFromPath->setText(QApplication::translate("MomsDuplicateDeleter", "Delete Duplicate files \n"
"from Directory/Folder Chosen", nullptr));
#ifndef QT_NO_TOOLTIP
        pbKeepInPath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder column, of the item selected in the list,  and delete the duplicates of those files found in any other Directory/Folder.</p><p>For instance, I put all my Sand Art Festival pictures, over the years, into one Directory/Folder called SandArt. In the meantime, there are duplicates of those in many other places. I want to keep the ones that I gathered, so I use this buton. First, I select/click a file, from the list, that has SandArt in the Directory/Folder column. Then click this button.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbKeepInPath->setText(QApplication::translate("MomsDuplicateDeleter", "Keep Duplicate files \n"
"in Directory/Folder Chosen", nullptr));
        pbSimDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Simulate Delete", nullptr));
        lbNumberOfUniqueDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of Unique Files that are duplicates", nullptr));
        lbNumberOfFiles->setText(QApplication::translate("MomsDuplicateDeleter", "No Search Performed...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSelectDirectory->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button allows you to select a directory/folder to search for duplicates in. This will also search in it's subdirectories./subfolder.  </p><p> Once the search is complete, you can choose and search another directory/folder to build up a complete list of places that duplicates could be hiding in before starting to use the delete operations.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSelectDirectory->setText(QApplication::translate("MomsDuplicateDeleter", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSearch->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Search button is used to scan all the files, that meet the criteria in the drop-down to the left and are in the Directory/Folder choosen or it's subdirectories/folders.  This builds a database of information that the program uses to determine if files are duplicates.  </p><p>Those duplicates are then presented in the table below.  </p><p>From there, you can start cleaning up based on directory/folder using the Keep Duplicate files in Directoy/Folder Chosen or the Delete Duplicate files from Directory/Folder Chosen buttons.</p><p>Or, if you are like my mom, just hit the Delete All Dublipcate files Randomly button below and rest easy that you only have one copy left of everything. </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Search", nullptr));
#ifndef QT_NO_TOOLTIP
        pbRemoveDB->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Start Over button will clear the database where the list of files is stored.  This is very important if you have changed the files, on your own, but still have stale information in the list.  For instance, if you delete a file that is a duplicate, on your own and now you only have one opy.  Since you deleted a file without the program, then it remains in the list in the database.  Then when the delete process is engaged, using the list from the database, the program will think there is a duplicate, when there actually isn't and may choose to delete the only copy you have left.  </p><p>Bottom line, best practice is to use this Start Over whenever you do things on your own with the files, even moving them...  After hitting the Start Over button, then you will need to scan your files again.  </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbRemoveDB->setText(QApplication::translate("MomsDuplicateDeleter", "Start Over", nullptr));
#ifndef QT_NO_TOOLTIP
        pbActualDelete->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Delete All Duplicate files is a bruteforce, yet simple, way of getting rid of all the duplicates found from the searches.   The catch is that it will do it randomly, sometimes from one directory/folder, sometimes from a different directory/folder. </p><p>This was my mom's original request.  The idea is to first get rid of the duplicates, then gather everything into one directory/folder and then sort it out from there.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbActualDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Delete  All Duplicate files \n"
"Rendomly", nullptr));
        lbNumberOfDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of files that are duplicate", nullptr));
#ifndef QT_NO_TOOLTIP
        lePathToSearch->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This area simply shows the Directory/Folder that will be used for the Search operation.  Use the ... button to the right to choose that directory/folder.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        lePathToSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Type in a directory or choose the ... button", nullptr));
#ifndef QT_NO_TOOLTIP
        cbSimulateFlag->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This checkbox allows for simulating what would happen.  This will prevent removing the files and changing the list in the table, but it gathers stats on how many files would be deleted and how much storage space would be saved.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        cbSimulateFlag->setText(QApplication::translate("MomsDuplicateDeleter", "Simulate Delete Operations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MomsDuplicateDeleter: public Ui_MomsDuplicateDeleter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOMSDUPLICATEDELETER_H
