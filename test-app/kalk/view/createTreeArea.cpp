#include "createTreeArea.h"

const QString CreateTreeArea::valueLabel = "set value : ";
const QString CreateTreeArea::rootLabel = "root";
const QString CreateTreeArea::leftLabel = "left";
const QString CreateTreeArea::rightLabel = "right";
const QString CreateTreeArea::middleLabel = "middle";

CreateTreeArea::CreateTreeArea(QValidator* Validator , const QString& header , QWidget* parent) :
    QScrollArea(parent),
	lineEditList(0),
        validator(Validator) {
    setMinimumSize(parent->width() , parent->height());
    treeWidget = new QTreeWidget(this);
    treeWidget->setMinimumSize(width() , height());
    treeWidget->setSortingEnabled(false);
    root = new QTreeWidgetItem(treeWidget);
    QTreeWidgetItem* rootValue = new QTreeWidgetItem(root);
    QTreeWidgetItem* rootValueLabel = new QTreeWidgetItem(rootValue);
    QLineEdit* rootValueEdit = new QLineEdit(this);
    setStyleSheet("QLineEdit:focus{border: 2px solid red; color: black; background: yellow;}");
    lineEditList.append(rootValueEdit);
    addValidator(rootValueEdit);
    rootValueEdit->setMaxLength(20);
    rootValueEdit->setMaximumWidth(200);
    root->setText(0 , rootLabel);
    rootValue->setText(0 , valueLabel);
    root = treeWidget->topLevelItem(0);
    root->insertChild(0 , rootValue);
    rootValue->addChild(rootValueLabel);
    treeWidget->setItemWidget(rootValueLabel , 0 , rootValueEdit);
    treeWidget->setHeaderLabel(header);
}

QString CreateTreeArea::getRootLabel() { return rootLabel; }

int CreateTreeAreaFun::getHeight(QTreeWidgetItem* node) {
    if(node->parent())
        return 1 + getHeight(node->parent());
    else
        return 1;
}

QTreeWidgetItem* CreateTreeArea::createNode(const QString& nodeLabel ,
                                            QTreeWidgetItem* parent) {
    QTreeWidgetItem* node = new QTreeWidgetItem(parent);
    QTreeWidgetItem* nodeValue = new QTreeWidgetItem(node);
    QTreeWidgetItem* nodeValueLabel = new QTreeWidgetItem(nodeValue);
    QLineEdit* nodeValueEdit = new QLineEdit(this);
    lineEditList.append(nodeValueEdit);
    addValidator(nodeValueEdit);
    nodeValueEdit->setMaxLength(20);
    nodeValueEdit->setMaximumWidth(200);
    node->setText(0 , nodeLabel);
    nodeValue->setText(0 , valueLabel);
    node->insertChild(0 , nodeValue);
    nodeValue->addChild(nodeValueLabel);
    getTreeWidget()->setItemWidget(nodeValueLabel , 0 , nodeValueEdit);
    return node;
}

void CreateTreeArea::addValidator(QLineEdit* line) { line->setValidator(validator); }

void CreateTreeArea::setTreeHeaderLabel(const QString& val) { treeWidget->setHeaderLabel(val); }

QString CreateTreeArea::getTreeHeaderLabel() const { return treeWidget->headerItem()->text(0); }

QTreeWidget* CreateTreeArea::getTreeWidget() const { return treeWidget; }

QTreeWidgetItem* CreateTreeArea::getRootTreeWidget() const { return root; }

const QVector<const QLineEdit*> CreateTreeArea::getLineEditList() const { return lineEditList; }

CreateTreeArea::~CreateTreeArea() {}
