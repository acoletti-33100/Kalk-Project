#include"createTernaryTreeArea.h"

CreateTernaryTreeArea::CreateTernaryTreeArea(QValidator* Validator , QString val , int height , QWidget* parent) : 
	CreateTreeArea(Validator , val , parent)
{
    build(height , getRootTreeWidget());
}

void CreateTernaryTreeArea::build(const int& height , QTreeWidgetItem* node) {
    if(CreateTreeAreaFun::getHeight(node) == height)
        return;
    QTreeWidgetItem* nodeL = createNode(leftLabel , node);
    QTreeWidgetItem* nodeR = createNode(rightLabel , node);
    QTreeWidgetItem* nodeM = createNode(middleLabel , node);
    build(height , nodeR);
    build(height , nodeL);
    build(height , nodeM);
}

CreateTernaryTreeArea::~CreateTernaryTreeArea() {}
