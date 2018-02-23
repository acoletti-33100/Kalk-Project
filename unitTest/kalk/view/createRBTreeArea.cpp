#include"createRBTreeArea.h"

const QString CreateRBTreeArea::colorLabel = "set color : ";
const QString CreateRBTreeArea::colorFixedLabel = "color : Black";
const QString CreateRBTreeArea::colorBlack = "Black";
const QString CreateRBTreeArea::colorRed = "Red";

CreateRBTreeArea::CreateRBTreeArea(QValidator* Validator , QString val , int height , QWidget* parent) :
	CreateBinaryTreeArea(Validator , val , height , parent) {
    createChildrenInfo(height + 2);
}

QTreeWidgetItem* CreateRBTreeArea::createNode(const QString& nodelLabel , QTreeWidgetItem* parent){
    QTreeWidgetItem* ColorLabel = new QTreeWidgetItem();
    QTreeWidgetItem* Color = new QTreeWidgetItem(ColorLabel);
    QComboBox* colorBox = new QComboBox(this);
    colorBox->setMaximumWidth(200);
    comboBoxList.append(colorBox);
    colorBox->addItem(colorBlack);
    colorBox->addItem(colorRed);
    getTreeWidget()->setItemWidget(Color , 0 , colorBox);
    ColorLabel->setText(0 , nodelLabel);
    parent->addChild(ColorLabel);
    return ColorLabel;
}

QTreeWidgetItem* CreateRBTreeArea::createColoredNodeLeaf() {
    QTreeWidgetItem* Color = new QTreeWidgetItem();
    Color->setText(0 , colorFixedLabel);
    return Color;
}

void CreateRBTreeArea::createChildrenInfo(const int& height) {
    QTreeWidgetItem* aux = 0;
    QTreeWidgetItemIterator it(getTreeWidget());
    QString text = "";
    while(*it && CreateTreeAreaFun::getHeight(*it) <= height) {
        text = (*it)->text(0);
        if(text == leftLabel || text == rightLabel) {
            if((*it)->childCount() == 1 || !(*it)->parent()) {
                aux = createColoredNodeLeaf();
                (*it)->addChild(aux);
            }
            else { aux = createNode(colorLabel , *it); }
        }
    ++it;
    }
}

const QVector<const QComboBox*> CreateRBTreeArea::getComboBoxList() const {
    return comboBoxList;
}

CreateRBTreeArea::~CreateRBTreeArea() {}
