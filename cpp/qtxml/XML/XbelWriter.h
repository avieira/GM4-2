#ifndef XBELWRITER_H
#define XBELWRITER_H

#include <QXmlStreamWriter>

class QTreeWidget;
class QTreeWidgetItem;

class XbelWriter
{
public:
    XbelWriter(QTreeWidget *treeWidget);
    bool writeFile(QIODevice *device);

private:
    void writeItem(QTreeWidgetItem *item);
    QXmlStreamWriter xml;
    QTreeWidget *treeWidget;
};

#endif
