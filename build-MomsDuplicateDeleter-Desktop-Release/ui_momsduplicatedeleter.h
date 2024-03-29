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
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MomsDuplicateDeleter
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabCleanup;
    QPushButton *pbSearch;
    QLabel *lbNumberOfDuplicateFiles;
    QTableWidget *tableDuplicateResultsList;
    QLabel *lbNumberOfUniqueDuplicateFiles;
    QLabel *lbNumberOfFiles;
    QPushButton *pbExportFilesList2CSV;
    QPushButton *pbDeleteFromPath;
    QLineEdit *lePathToSearch;
    QProgressBar *progressBar;
    QComboBox *cbFileType;
    QPushButton *pbRemoveDB;
    QPushButton *pbFillTablesFromDB;
    QLineEdit *leUserSubPath;
    QPushButton *pbKeepInPath;
    QCheckBox *cbSimulateFlag;
    QPushButton *pbSimDelete;
    QPushButton *pbSelectDirectory;
    QPushButton *pbDeleteSingle;
    QPushButton *pbDeleteFromPathBelow;
    QPushButton *pbViewImage;
    QPushButton *pbViewMovie;
    QPushButton *pbVerifyDB;
    QPushButton *pbOpenDirectory;
    QLabel *label_3;
    QWidget *tabGathering;
    QLabel *label;
    QWidget *tabDeleting;
    QLabel *label_2;
    QWidget *tabExclusiveFiles;
    QTableWidget *tableExclusiveResultsList;
    QPushButton *pbFillTablesFromDB_2;
    QPushButton *pbViewImage_2;
    QLabel *lbNumberOfUniqueFiles;
    QPushButton *pbOpenDirectoryExclusive;
    QWidget *tabOperations;
    QPushButton *pbActualDelete;
    QPushButton *pbDeleteCopyFiles;
    QWidget *tabCatalog;
    QPushButton *pbExcludePathAndBelow;
    QLineEdit *leExcludePath;
    QLabel *label_4;
    QLineEdit *leExcludeFilePath;
    QPushButton *pbSelectExcludeFilePath;
    QPushButton *pbExcludePathAndBelow_2;
    QListView *tableExcludeDirectories;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MomsDuplicateDeleter)
    {
        if (MomsDuplicateDeleter->objectName().isEmpty())
            MomsDuplicateDeleter->setObjectName(QString::fromUtf8("MomsDuplicateDeleter"));
        MomsDuplicateDeleter->resize(1025, 713);
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1011, 661));
        tabCleanup = new QWidget();
        tabCleanup->setObjectName(QString::fromUtf8("tabCleanup"));
        pbSearch = new QPushButton(tabCleanup);
        pbSearch->setObjectName(QString::fromUtf8("pbSearch"));
        pbSearch->setGeometry(QRect(450, 32, 141, 41));
        QFont font;
        font.setPointSize(10);
        pbSearch->setFont(font);
        lbNumberOfDuplicateFiles = new QLabel(tabCleanup);
        lbNumberOfDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfDuplicateFiles"));
        lbNumberOfDuplicateFiles->setGeometry(QRect(20, 220, 281, 16));
        lbNumberOfDuplicateFiles->setFont(font);
        tableDuplicateResultsList = new QTableWidget(tabCleanup);
        tableDuplicateResultsList->setObjectName(QString::fromUtf8("tableDuplicateResultsList"));
        tableDuplicateResultsList->setGeometry(QRect(20, 240, 981, 341));
        tableDuplicateResultsList->setFont(font);
        tableDuplicateResultsList->setSortingEnabled(true);
        lbNumberOfUniqueDuplicateFiles = new QLabel(tabCleanup);
        lbNumberOfUniqueDuplicateFiles->setObjectName(QString::fromUtf8("lbNumberOfUniqueDuplicateFiles"));
        lbNumberOfUniqueDuplicateFiles->setGeometry(QRect(400, 220, 391, 16));
        lbNumberOfUniqueDuplicateFiles->setFont(font);
        lbNumberOfFiles = new QLabel(tabCleanup);
        lbNumberOfFiles->setObjectName(QString::fromUtf8("lbNumberOfFiles"));
        lbNumberOfFiles->setGeometry(QRect(870, 220, 401, 16));
        lbNumberOfFiles->setFont(font);
        pbExportFilesList2CSV = new QPushButton(tabCleanup);
        pbExportFilesList2CSV->setObjectName(QString::fromUtf8("pbExportFilesList2CSV"));
        pbExportFilesList2CSV->setGeometry(QRect(1100, 10, 141, 21));
        pbExportFilesList2CSV->setFont(font);
        pbDeleteFromPath = new QPushButton(tabCleanup);
        pbDeleteFromPath->setObjectName(QString::fromUtf8("pbDeleteFromPath"));
        pbDeleteFromPath->setGeometry(QRect(10, 100, 271, 51));
        pbDeleteFromPath->setFont(font);
        lePathToSearch = new QLineEdit(tabCleanup);
        lePathToSearch->setObjectName(QString::fromUtf8("lePathToSearch"));
        lePathToSearch->setEnabled(true);
        lePathToSearch->setGeometry(QRect(10, 50, 301, 31));
        lePathToSearch->setFont(font);
        progressBar = new QProgressBar(tabCleanup);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(260, 240, 591, 81));
        progressBar->setValue(0);
        cbFileType = new QComboBox(tabCleanup);
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
        cbFileType->addItem(QString());
        cbFileType->addItem(QString());
        cbFileType->setObjectName(QString::fromUtf8("cbFileType"));
        cbFileType->setGeometry(QRect(360, 50, 73, 22));
        cbFileType->setFont(font);
        pbRemoveDB = new QPushButton(tabCleanup);
        pbRemoveDB->setObjectName(QString::fromUtf8("pbRemoveDB"));
        pbRemoveDB->setGeometry(QRect(10, 10, 93, 28));
        pbRemoveDB->setFont(font);
        pbFillTablesFromDB = new QPushButton(tabCleanup);
        pbFillTablesFromDB->setObjectName(QString::fromUtf8("pbFillTablesFromDB"));
        pbFillTablesFromDB->setGeometry(QRect(110, 10, 141, 28));
        pbFillTablesFromDB->setFont(font);
        leUserSubPath = new QLineEdit(tabCleanup);
        leUserSubPath->setObjectName(QString::fromUtf8("leUserSubPath"));
        leUserSubPath->setGeometry(QRect(710, 180, 191, 25));
        pbKeepInPath = new QPushButton(tabCleanup);
        pbKeepInPath->setObjectName(QString::fromUtf8("pbKeepInPath"));
        pbKeepInPath->setGeometry(QRect(10, 160, 271, 51));
        pbKeepInPath->setFont(font);
        cbSimulateFlag = new QCheckBox(tabCleanup);
        cbSimulateFlag->setObjectName(QString::fromUtf8("cbSimulateFlag"));
        cbSimulateFlag->setGeometry(QRect(620, 20, 291, 23));
        cbSimulateFlag->setChecked(true);
        pbSimDelete = new QPushButton(tabCleanup);
        pbSimDelete->setObjectName(QString::fromUtf8("pbSimDelete"));
        pbSimDelete->setGeometry(QRect(1340, 680, 151, 28));
        pbSimDelete->setFont(font);
        pbSelectDirectory = new QPushButton(tabCleanup);
        pbSelectDirectory->setObjectName(QString::fromUtf8("pbSelectDirectory"));
        pbSelectDirectory->setGeometry(QRect(320, 50, 31, 31));
        pbSelectDirectory->setFont(font);
        pbDeleteSingle = new QPushButton(tabCleanup);
        pbDeleteSingle->setObjectName(QString::fromUtf8("pbDeleteSingle"));
        pbDeleteSingle->setGeometry(QRect(300, 100, 231, 51));
        pbDeleteSingle->setFont(font);
        pbDeleteFromPathBelow = new QPushButton(tabCleanup);
        pbDeleteFromPathBelow->setObjectName(QString::fromUtf8("pbDeleteFromPathBelow"));
        pbDeleteFromPathBelow->setGeometry(QRect(640, 100, 191, 61));
        pbDeleteFromPathBelow->setFont(font);
        pbViewImage = new QPushButton(tabCleanup);
        pbViewImage->setObjectName(QString::fromUtf8("pbViewImage"));
        pbViewImage->setGeometry(QRect(640, 50, 151, 25));
        pbViewMovie = new QPushButton(tabCleanup);
        pbViewMovie->setObjectName(QString::fromUtf8("pbViewMovie"));
        pbViewMovie->setGeometry(QRect(1100, 40, 141, 25));
        pbVerifyDB = new QPushButton(tabCleanup);
        pbVerifyDB->setObjectName(QString::fromUtf8("pbVerifyDB"));
        pbVerifyDB->setGeometry(QRect(260, 10, 111, 28));
        pbVerifyDB->setFont(font);
        pbOpenDirectory = new QPushButton(tabCleanup);
        pbOpenDirectory->setObjectName(QString::fromUtf8("pbOpenDirectory"));
        pbOpenDirectory->setGeometry(QRect(300, 160, 91, 51));
        pbOpenDirectory->setFont(font);
        label_3 = new QLabel(tabCleanup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(570, 180, 131, 20));
        tabWidget->addTab(tabCleanup, QString());
        tabGathering = new QWidget();
        tabGathering->setObjectName(QString::fromUtf8("tabGathering"));
        label = new QLabel(tabGathering);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 140, 511, 201));
        label->setWordWrap(true);
        tabWidget->addTab(tabGathering, QString());
        tabDeleting = new QWidget();
        tabDeleting->setObjectName(QString::fromUtf8("tabDeleting"));
        label_2 = new QLabel(tabDeleting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 260, 651, 201));
        tabWidget->addTab(tabDeleting, QString());
        tabExclusiveFiles = new QWidget();
        tabExclusiveFiles->setObjectName(QString::fromUtf8("tabExclusiveFiles"));
        tableExclusiveResultsList = new QTableWidget(tabExclusiveFiles);
        tableExclusiveResultsList->setObjectName(QString::fromUtf8("tableExclusiveResultsList"));
        tableExclusiveResultsList->setGeometry(QRect(10, 70, 981, 471));
        tableExclusiveResultsList->setFont(font);
        tableExclusiveResultsList->setSortingEnabled(true);
        pbFillTablesFromDB_2 = new QPushButton(tabExclusiveFiles);
        pbFillTablesFromDB_2->setObjectName(QString::fromUtf8("pbFillTablesFromDB_2"));
        pbFillTablesFromDB_2->setGeometry(QRect(20, 10, 141, 28));
        pbFillTablesFromDB_2->setFont(font);
        pbViewImage_2 = new QPushButton(tabExclusiveFiles);
        pbViewImage_2->setObjectName(QString::fromUtf8("pbViewImage_2"));
        pbViewImage_2->setGeometry(QRect(190, 10, 151, 25));
        lbNumberOfUniqueFiles = new QLabel(tabExclusiveFiles);
        lbNumberOfUniqueFiles->setObjectName(QString::fromUtf8("lbNumberOfUniqueFiles"));
        lbNumberOfUniqueFiles->setGeometry(QRect(20, 50, 281, 16));
        lbNumberOfUniqueFiles->setFont(font);
        pbOpenDirectoryExclusive = new QPushButton(tabExclusiveFiles);
        pbOpenDirectoryExclusive->setObjectName(QString::fromUtf8("pbOpenDirectoryExclusive"));
        pbOpenDirectoryExclusive->setGeometry(QRect(370, 10, 91, 51));
        pbOpenDirectoryExclusive->setFont(font);
        tabWidget->addTab(tabExclusiveFiles, QString());
        tabOperations = new QWidget();
        tabOperations->setObjectName(QString::fromUtf8("tabOperations"));
        pbActualDelete = new QPushButton(tabOperations);
        pbActualDelete->setObjectName(QString::fromUtf8("pbActualDelete"));
        pbActualDelete->setGeometry(QRect(20, 30, 231, 51));
        pbActualDelete->setFont(font);
        pbDeleteCopyFiles = new QPushButton(tabOperations);
        pbDeleteCopyFiles->setObjectName(QString::fromUtf8("pbDeleteCopyFiles"));
        pbDeleteCopyFiles->setGeometry(QRect(20, 110, 231, 121));
        pbDeleteCopyFiles->setFont(font);
        tabWidget->addTab(tabOperations, QString());
        tabCatalog = new QWidget();
        tabCatalog->setObjectName(QString::fromUtf8("tabCatalog"));
        pbExcludePathAndBelow = new QPushButton(tabCatalog);
        pbExcludePathAndBelow->setObjectName(QString::fromUtf8("pbExcludePathAndBelow"));
        pbExcludePathAndBelow->setGeometry(QRect(90, 60, 221, 71));
        leExcludePath = new QLineEdit(tabCatalog);
        leExcludePath->setObjectName(QString::fromUtf8("leExcludePath"));
        leExcludePath->setGeometry(QRect(170, 170, 191, 25));
        label_4 = new QLabel(tabCatalog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 131, 20));
        leExcludeFilePath = new QLineEdit(tabCatalog);
        leExcludeFilePath->setObjectName(QString::fromUtf8("leExcludeFilePath"));
        leExcludeFilePath->setEnabled(true);
        leExcludeFilePath->setGeometry(QRect(530, 100, 301, 31));
        leExcludeFilePath->setFont(font);
        pbSelectExcludeFilePath = new QPushButton(tabCatalog);
        pbSelectExcludeFilePath->setObjectName(QString::fromUtf8("pbSelectExcludeFilePath"));
        pbSelectExcludeFilePath->setGeometry(QRect(840, 100, 31, 31));
        pbSelectExcludeFilePath->setFont(font);
        pbExcludePathAndBelow_2 = new QPushButton(tabCatalog);
        pbExcludePathAndBelow_2->setObjectName(QString::fromUtf8("pbExcludePathAndBelow_2"));
        pbExcludePathAndBelow_2->setGeometry(QRect(540, 400, 321, 121));
        tableExcludeDirectories = new QListView(tabCatalog);
        tableExcludeDirectories->setObjectName(QString::fromUtf8("tableExcludeDirectories"));
        tableExcludeDirectories->setGeometry(QRect(480, 170, 451, 181));
        tableExcludeDirectories->setFont(font);
        tabWidget->addTab(tabCatalog, QString());
        pbSelectExcludeFilePath->raise();
        pbExcludePathAndBelow->raise();
        leExcludePath->raise();
        label_4->raise();
        leExcludeFilePath->raise();
        pbExcludePathAndBelow_2->raise();
        tableExcludeDirectories->raise();
        MomsDuplicateDeleter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MomsDuplicateDeleter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1025, 22));
        MomsDuplicateDeleter->setMenuBar(menubar);
        statusbar = new QStatusBar(MomsDuplicateDeleter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MomsDuplicateDeleter->setStatusBar(statusbar);

        retranslateUi(MomsDuplicateDeleter);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MomsDuplicateDeleter);
    } // setupUi

    void retranslateUi(QMainWindow *MomsDuplicateDeleter)
    {
        MomsDuplicateDeleter->setWindowTitle(QApplication::translate("MomsDuplicateDeleter", "Mom's Duplicate Deleter", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSearch->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Search button is used to scan all the files, that meet the criteria in the drop-down to the left and are in the Directory/Folder choosen or it's subdirectories/folders.  This builds a database of information that the program uses to determine if files are duplicates.  </p><p>Those duplicates are then presented in the table below.  </p><p>From there, you can start cleaning up based on directory/folder using the Keep Duplicate files in Directoy/Folder Chosen or the Delete Duplicate files from Directory/Folder Chosen buttons.</p><p>Or, if you are like my mom, just hit the Delete All Dublipcate files Randomly button below and rest easy that you only have one copy left of everything. </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Search and Add\n"
"to calalog", nullptr));
        lbNumberOfDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of files that are duplicate", nullptr));
        lbNumberOfUniqueDuplicateFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of Unique Files that are duplicates", nullptr));
        lbNumberOfFiles->setText(QApplication::translate("MomsDuplicateDeleter", "No Search Performed...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbExportFilesList2CSV->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">Save Plan List to CVS file</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbExportFilesList2CSV->setText(QApplication::translate("MomsDuplicateDeleter", "Export File List", nullptr));
#ifndef QT_NO_TOOLTIP
        pbDeleteFromPath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder column, of the item selected in the list, and delete those files.</p><p>For instance, I have copies of my phone pictures several times over the years and they are duplicates of ones that I have already brought over before and sorted through.  Using this button, it will remove all the duplicates in that directory/folder, and then I can sort through what it left, knowing they are not duplicated elsewhere.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbDeleteFromPath->setText(QApplication::translate("MomsDuplicateDeleter", "Delete Duplicate files \n"
"from Directory/Folder Chosen", nullptr));
#ifndef QT_NO_TOOLTIP
        lePathToSearch->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This area simply shows the Directory/Folder that will be used for the Search operation.  Use the ... button to the right to choose that directory/folder.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        lePathToSearch->setText(QApplication::translate("MomsDuplicateDeleter", "Type in a directory or choose the ... button", nullptr));
        cbFileType->setItemText(0, QApplication::translate("MomsDuplicateDeleter", "*.", nullptr));
        cbFileType->setItemText(1, QApplication::translate("MomsDuplicateDeleter", "*.jpg", nullptr));
        cbFileType->setItemText(2, QApplication::translate("MomsDuplicateDeleter", "*.png", nullptr));
        cbFileType->setItemText(3, QApplication::translate("MomsDuplicateDeleter", "*.mpg", nullptr));
        cbFileType->setItemText(4, QApplication::translate("MomsDuplicateDeleter", "*.mp4", nullptr));
        cbFileType->setItemText(5, QApplication::translate("MomsDuplicateDeleter", "*.mpeg", nullptr));
        cbFileType->setItemText(6, QApplication::translate("MomsDuplicateDeleter", "*.avi", nullptr));
        cbFileType->setItemText(7, QApplication::translate("MomsDuplicateDeleter", "*.jpeg", nullptr));
        cbFileType->setItemText(8, QApplication::translate("MomsDuplicateDeleter", "*.mov", nullptr));
        cbFileType->setItemText(9, QApplication::translate("MomsDuplicateDeleter", "*.bmp", nullptr));
        cbFileType->setItemText(10, QApplication::translate("MomsDuplicateDeleter", "*.3g2", nullptr));
        cbFileType->setItemText(11, QApplication::translate("MomsDuplicateDeleter", "*.*", nullptr));

#ifndef QT_NO_TOOLTIP
        cbFileType->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This pull-down allows you to select particular file extensions to use in the search.  This relates to the type of file, mainly pictures and movies of different common formats.</p><p>If you leave it alone, it will search for each extension in the list, except for the *.*.   If you want to scan more that one, but not the whole list, then choose one, then hit search, after it completes, choose another one, then hit search, ....repeat until all desired extentions have been searched for.</p><p>If you want to scan all files regardless of extention, then select the *.* entry of the list.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbRemoveDB->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Start Over button will clear the database where the list of files is stored.  This is very important if you have changed the files, on your own, but still have stale information in the list.  For instance, if you delete a file that is a duplicate, on your own and now you only have one opy.  Since you deleted a file without the program, then it remains in the list in the database.  Then when the delete process is engaged, using the list from the database, the program will think there is a duplicate, when there actually isn't and may choose to delete the only copy you have left.  </p><p>Bottom line, best practice is to use this Start Over whenever you do things on your own with the files, even moving them...  After hitting the Start Over button, then you will need to scan your files again.  </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbRemoveDB->setText(QApplication::translate("MomsDuplicateDeleter", "Start Over", nullptr));
#ifndef QT_NO_TOOLTIP
        pbFillTablesFromDB->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Load Current Duplicates List button will load the list from the database.   This is a way to come back to where you left off and the program ASSUMES  that you din't change any files on your own.  This is very important if you have changed the files, on your own, but still have stale information in the list and you may lose you only copy of a file...  When in doubt, use the Start Over button instead.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbFillTablesFromDB->setText(QApplication::translate("MomsDuplicateDeleter", "Load Last Catalog", nullptr));
#ifndef QT_NO_TOOLTIP
        pbKeepInPath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder column, of the item selected in the list,  and delete the duplicates of those files found in any other Directory/Folder.</p><p>For instance, I put all my Sand Art Festival pictures, over the years, into one Directory/Folder called SandArt. In the meantime, there are duplicates of those in many other places. I want to keep the ones that I gathered, so I use this buton. First, I select/click a file, from the list, that has SandArt in the Directory/Folder column. Then click this button.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbKeepInPath->setText(QApplication::translate("MomsDuplicateDeleter", "Keep Duplicate files \n"
"in Directory/Folder Chosen", nullptr));
#ifndef QT_NO_TOOLTIP
        cbSimulateFlag->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This checkbox allows for simulating what would happen.  This will prevent removing the files and changing the list in the table, but it gathers stats on how many files would be deleted and how much storage space would be saved.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        cbSimulateFlag->setText(QApplication::translate("MomsDuplicateDeleter", "Simulate Delete Operations", nullptr));
        pbSimDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Simulate Delete", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSelectDirectory->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button allows you to select a directory/folder to search for duplicates in. This will also search in it's subdirectories./subfolder.  </p><p> Once the search is complete, you can choose and search another directory/folder to build up a complete list of places that duplicates could be hiding in before starting to use the delete operations.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSelectDirectory->setText(QApplication::translate("MomsDuplicateDeleter", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        pbDeleteSingle->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder column, of the item selected in the list, and delete those files.</p><p>For instance, I have copies of my phone pictures several times over the years and they are duplicates of ones that I have already brought over before and sorted through.  Using this button, it will remove all the duplicates in that directory/folder, and then I can sort through what it left, knowing they are not duplicated elsewhere.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbDeleteSingle->setText(QApplication::translate("MomsDuplicateDeleter", "Delete Chosen \n"
"Duplicate file", nullptr));
#ifndef QT_NO_TOOLTIP
        pbDeleteFromPathBelow->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will take the duplicate files that are in the Directory/Folder specified and below and delete those files.  Specify the base directory/folder in the text box below the button.</p><p>For instance, I have copies of complete directory/folder structures on two drives.  This will allow me me to delete them all at once instead of having to pick every directory/folder in the list individually.  Specify the base directory/folder in the text box below the button.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbDeleteFromPathBelow->setText(QApplication::translate("MomsDuplicateDeleter", "Delete Duplicate files \n"
"from Directory/Folder\n"
"Entered Below\n"
" (and all sub-folders) ", nullptr));
        pbViewImage->setText(QApplication::translate("MomsDuplicateDeleter", "View Image", nullptr));
        pbViewMovie->setText(QApplication::translate("MomsDuplicateDeleter", "View Movie", nullptr));
#ifndef QT_NO_TOOLTIP
        pbVerifyDB->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Start Over button will clear the database where the list of files is stored.  This is very important if you have changed the files, on your own, but still have stale information in the list.  For instance, if you delete a file that is a duplicate, on your own and now you only have one opy.  Since you deleted a file without the program, then it remains in the list in the database.  Then when the delete process is engaged, using the list from the database, the program will think there is a duplicate, when there actually isn't and may choose to delete the only copy you have left.  </p><p>Bottom line, best practice is to use this Start Over whenever you do things on your own with the files, even moving them...  After hitting the Start Over button, then you will need to scan your files again.  </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbVerifyDB->setText(QApplication::translate("MomsDuplicateDeleter", "Verify Catalog", nullptr));
#ifndef QT_NO_TOOLTIP
        pbOpenDirectory->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will open a window for showing the files in the chosen directory.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbOpenDirectory->setText(QApplication::translate("MomsDuplicateDeleter", "Open \n"
"Selected \n"
"Directory", nullptr));
        label_3->setText(QApplication::translate("MomsDuplicateDeleter", "User Entered Path:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCleanup), QApplication::translate("MomsDuplicateDeleter", "File Cleanup", nullptr));
        label->setText(QApplication::translate("MomsDuplicateDeleter", "This area will eventually be a place that you can gather and view all your files in one place", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGathering), QApplication::translate("MomsDuplicateDeleter", "File Gathering", nullptr));
        label_2->setText(QApplication::translate("MomsDuplicateDeleter", "This tab will be an area for viewing the different files.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDeleting), QApplication::translate("MomsDuplicateDeleter", "File Viewing/Deleting", nullptr));
#ifndef QT_NO_TOOLTIP
        pbFillTablesFromDB_2->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Load Current Duplicates List button will load the list from the database.   This is a way to come back to where you left off and the program ASSUMES  that you din't change any files on your own.  This is very important if you have changed the files, on your own, but still have stale information in the list and you may lose you only copy of a file...  When in doubt, use the Start Over button instead.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbFillTablesFromDB_2->setText(QApplication::translate("MomsDuplicateDeleter", "Load Last Catalog", nullptr));
        pbViewImage_2->setText(QApplication::translate("MomsDuplicateDeleter", "View Image", nullptr));
        lbNumberOfUniqueFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Number of files that are not duplicate", nullptr));
#ifndef QT_NO_TOOLTIP
        pbOpenDirectoryExclusive->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button will open a window for showing the files in the chosen directory.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbOpenDirectoryExclusive->setText(QApplication::translate("MomsDuplicateDeleter", "Open \n"
"Selected \n"
"Directory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExclusiveFiles), QApplication::translate("MomsDuplicateDeleter", "Exclusive File List", nullptr));
#ifndef QT_NO_TOOLTIP
        pbActualDelete->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Delete All Duplicate files is a bruteforce, yet simple, way of getting rid of all the duplicates found from the searches.   The catch is that it will do it randomly, sometimes from one directory/folder, sometimes from a different directory/folder. </p><p>This was my mom's original request.  The idea is to first get rid of the duplicates, then gather everything into one directory/folder and then sort it out from there.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbActualDelete->setText(QApplication::translate("MomsDuplicateDeleter", "Delete  All Duplicate files \n"
"Randomly", nullptr));
#ifndef QT_NO_TOOLTIP
        pbDeleteCopyFiles->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>The Delete All Duplicate files is a bruteforce, yet simple, way of getting rid of all the duplicates found from the searches.   The catch is that it will do it randomly, sometimes from one directory/folder, sometimes from a different directory/folder. </p><p>This was my mom's original request.  The idea is to first get rid of the duplicates, then gather everything into one directory/folder and then sort it out from there.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbDeleteCopyFiles->setText(QApplication::translate("MomsDuplicateDeleter", "Delete  All Duplicate files \n"
"with Copy, copy COPY, or \"(*)\"\n"
"in the filename.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabOperations), QApplication::translate("MomsDuplicateDeleter", "Just Do It", nullptr));
        pbExcludePathAndBelow->setText(QApplication::translate("MomsDuplicateDeleter", "Exclude files \n"
"from Directory/Folder\n"
"Entered Belowfrom catalog\n"
" (and all sub-folders) ", nullptr));
        label_4->setText(QApplication::translate("MomsDuplicateDeleter", "User Entered Path:", nullptr));
#ifndef QT_NO_TOOLTIP
        leExcludeFilePath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This area simply shows the Directory/Folder that will be used for the Search operation.  Use the ... button to the right to choose that directory/folder.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        leExcludeFilePath->setText(QApplication::translate("MomsDuplicateDeleter", "Type in a directory or choose the ... button", nullptr));
#ifndef QT_NO_TOOLTIP
        pbSelectExcludeFilePath->setToolTip(QApplication::translate("MomsDuplicateDeleter", "<html><head/><body><p>This button allows you to select a directory/folder to search for duplicates in. This will also search in it's subdirectories./subfolder.  </p><p> Once the search is complete, you can choose and search another directory/folder to build up a complete list of places that duplicates could be hiding in before starting to use the delete operations.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pbSelectExcludeFilePath->setText(QApplication::translate("MomsDuplicateDeleter", "...", nullptr));
        pbExcludePathAndBelow_2->setText(QApplication::translate("MomsDuplicateDeleter", "Exclude files \n"
"from Directory/Folder\n"
", listed in the table, from catalog\n"
" (and all sub-folders) \n"
"contained in the Exclusion Table.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCatalog), QApplication::translate("MomsDuplicateDeleter", "Catalog Cleanup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MomsDuplicateDeleter: public Ui_MomsDuplicateDeleter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOMSDUPLICATEDELETER_H
