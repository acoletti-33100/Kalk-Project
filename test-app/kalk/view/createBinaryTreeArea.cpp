#include"createBinaryTreeArea.h"

CreateBinaryTreeArea::CreateBinaryTreeArea(QValidator* Validator , QString val , int height , QWidget* parent) : 
    CreateTreeArea(Validator , val , parent) {
	build(height , getRootTreeWidget());
}

void CreateBinaryTreeArea::build(const int& height , QTreeWidgetItem* node) {
    if(CreateTreeAreaFun::getHeight(node) == height)
        return;
    QTreeWidgetItem* nodeL = createNode(leftLabel , node);
    QTreeWidgetItem* nodeR = createNode(rightLabel , node);
    build(height , nodeR);
    build(height , nodeL);
}

CreateBinaryTreeArea::~CreateBinaryTreeArea() {}
