#ifndef CREATE_BINARY_TREE_AREA_H
#define CREATE_BINARY_TREE_AREA_H

#include"createTreeArea.h"

class CreateBinaryTreeArea : public CreateTreeArea {
    Q_OBJECT

    private:
        void build(const int& height , QTreeWidgetItem* node = 0);

public:
        CreateBinaryTreeArea(QValidator* Validator = 0 , QString val = "" , int height = 1 , QWidget* parent = 0);
        virtual ~CreateBinaryTreeArea();
};

#endif
