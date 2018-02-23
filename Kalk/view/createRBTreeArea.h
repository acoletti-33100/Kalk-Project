#ifndef CREATE_RBTREE_AREA_H
#define CREATE_RBTREE_AREA_H

#include"createBinaryTreeArea.h"

class CreateRBTreeArea : public CreateBinaryTreeArea {
    private:
        static const QString colorLabel;
        static const QString colorFixedLabel;
	static const QString colorBlack;
	static const QString colorRed;
    QVector<const QComboBox*> comboBoxList;
        QTreeWidgetItem* createColoredNodeLeaf();
        void createChildrenInfo(const int&);
        QTreeWidgetItem* createNode(const QString& nodelLabel = "" ,
                                    QTreeWidgetItem* parent = 0);
	public:
        CreateRBTreeArea(QValidator* Validator = 0 , QString val = "" , int height = 1 , QWidget* parent = 0);
        const QVector<const QComboBox*> getComboBoxList() const;
	~CreateRBTreeArea();
};

#endif
