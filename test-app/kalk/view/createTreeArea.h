#ifndef CREATETREEAREA_H
#define CREATETREEAREA_H

#include <QScrollArea>
#include<QComboBox>
#include<QTreeWidget>
#include<QTreeWidgetItem>
#include<QLineEdit>
#include<QTreeWidgetItemIterator>
#include<QValidator>

namespace CreateTreeAreaFun {
class CreateTreeArea;
    int getHeight(QTreeWidgetItem* node = 0);
}

class CreateTreeArea : public QScrollArea
{
    Q_OBJECT

public:
    CreateTreeArea(QValidator* Validator = 0 , const QString& header = "" , QWidget* parent = 0);
    virtual ~CreateTreeArea() = 0;
    static QString getRootLabel();
    void setTreeHeaderLabel(const QString& val = "");
    QString getTreeHeaderLabel() const;
    const QVector<const QLineEdit*> getLineEditList() const;

protected:
    static const QString leftLabel;
    static const QString rightLabel;
    static const QString middleLabel;
    QTreeWidget* getTreeWidget() const;
    QTreeWidgetItem* getRootTreeWidget() const;
        static const QString valueLabel;
     virtual QTreeWidgetItem* createNode(const QString& nodeLabel = "" ,
                                 QTreeWidgetItem* parent = 0);
private:
    QVector<const QLineEdit*> lineEditList;
    static const QString rootLabel;
    QValidator* validator;
    QTreeWidget* treeWidget;
    QTreeWidgetItem* root;
     void addValidator(QLineEdit* line = 0);
};

#endif 
