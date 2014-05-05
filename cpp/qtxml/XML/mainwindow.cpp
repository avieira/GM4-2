#include <QtGui>

 #include "mainwindow.h"
 #include "XbelReader.h"
 #include "XbelWriter.h"

 MainWindow::MainWindow()
 {
     QStringList labels;
     labels << tr("Title") << tr("Location");

     treeWidget = new QTreeWidget;
     treeWidget->header()->setResizeMode(QHeaderView::Stretch);
     treeWidget->setHeaderLabels(labels);
     setCentralWidget(treeWidget);

     createActions();
     createMenus();

     statusBar()->showMessage(tr("Ready"));

     setWindowTitle(tr("QXmlStream Bookmarks"));
     resize(480, 320);
 }

 void MainWindow::open()
 {
 #if defined(Q_OS_SYMBIAN)
     // Look for bookmarks on the same drive where the application is installed to,
     // if drive is not read only. QDesktopServices::DataLocation does this check,
     // and returns writable drive.
     QString bookmarksFolder =
             QDesktopServices::storageLocation(QDesktopServices::DataLocation).left(1);
     bookmarksFolder.append(":/Data/qt/saxbookmarks");
     QDir::setCurrent(bookmarksFolder);
 #endif
     QString fileName =
             QFileDialog::getOpenFileName(this, tr("Open Bookmark File"),
                                          QDir::currentPath(),
                                          tr("XBEL Files (*.xbel *.xml)"));
     if (fileName.isEmpty())
         return;

     treeWidget->clear();

     QFile file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("QXmlStream Bookmarks"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     XbelReader reader(treeWidget);
     if (!reader.read(&file)) {
         QMessageBox::warning(this, tr("QXmlStream Bookmarks"),
                              tr("Parse error in file %1:\n\n%2")
                              .arg(fileName)
                              .arg(reader.errorString()));
     } else {
         statusBar()->showMessage(tr("File loaded"), 2000);
     }

 }

 void MainWindow::saveAs()
 {
 #if defined(Q_OS_SYMBIAN)
     // Look for bookmarks on the same drive where the application is installed to,
     // if drive is not read only. QDesktopServices::DataLocation does this check,
     // and returns writable drive.
     QString bookmarksFolder =
             QDesktopServices::storageLocation(QDesktopServices::DataLocation).left(1);
     bookmarksFolder.append(":/Data/qt/saxbookmarks");
     QDir::setCurrent(bookmarksFolder);
 #endif
     QString fileName =
             QFileDialog::getSaveFileName(this, tr("Save Bookmark File"),
                                          QDir::currentPath(),
                                          tr("XBEL Files (*.xbel *.xml)"));
     if (fileName.isEmpty())
         return;

     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("QXmlStream Bookmarks"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     XbelWriter writer(treeWidget);
     if (writer.writeFile(&file))
         statusBar()->showMessage(tr("File saved"), 2000);
 }

 void MainWindow::about()
 {
    QMessageBox::about(this, tr("About QXmlStream Bookmarks"),
             tr("The <b>QXmlStream Bookmarks</b> example demonstrates how to use Qt's "
                "QXmlStream classes to read and write XML documents."));
 }

 void MainWindow::createActions()
 {
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open);
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAsAct = new QAction(tr("&Save As..."), this);
     saveAsAct->setShortcuts(QKeySequence::SaveAs);
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcuts(QKeySequence::Quit);
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     aboutAct = new QAction(tr("&About"), this);
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAsAct);
     fileMenu->addAction(exitAct);

     menuBar()->addSeparator();

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);
 }
