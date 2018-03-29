#ifndef CREATE_TERNARY_TREE_AREA_H
#define CREATE_TERNARY_TREE_AREA_H

#include"createTreeArea.h"
#include"createBinaryTreeArea.h"

class CreateTernaryTreeArea : public CreateTreeArea {
    Q_OBJECT

    private:
        void build(const int& height , QTreeWidgetItem* node = 0);
public:
        CreateTernaryTreeArea(QValidator* Validator = 0 , QString val = "" , int height = 1 , QWidget* parent = 0);
        virtual ~CreateTernaryTreeArea();
};

#endif
