
template<typename T>
void CreateTreeArea::buildBinaryResultTree(const BinaryTreeModel<T>* model) {
    const BinaryNode<T>* modelRoot = model->getRoot();
    createRootResultNode(root , QString::number(modelRoot->getInfo()));
    buildBinaryResult(root , modelRoot);
    }

template<typename T>
void CreateTreeArea::buildBinaryResult(QTreeWidgetItem* node , const BinaryNode<T>* model) {
    if(!model)
        return;
    const BinaryNode<T>* l = model->getLeft();
    const BinaryNode<T>* r = model->getRight();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    if(l) {
        nodeL = createResultNode(leftLabel , node , QString::number(l->getInfo()));
    }
    if(r) {
        nodeR = createResultNode(rightLabel , node , QString::number(r->getInfo()));
    }
    buildBinaryResult(nodeL , l);
    buildBinaryResult(nodeR , model->getRight());
}

template<typename T>
void CreateTreeArea::buildTernaryResultTree(const TernaryTreeModel<T>* model) {
    const TernaryNode<T>* modelRoot = model->getRoot();
    createRootResultNode(root , QString::number(modelRoot->getInfo()));
    buildTernaryResult(root , modelRoot);
}

template<typename T>
void CreateTreeArea::buildTernaryResult(QTreeWidgetItem* node , const TernaryNode<T>* model) {
    if(!model)
        return;
    const TernaryNode<T>* l = model->getLeft();
    const TernaryNode<T>* r = model->getRight();
    const TernaryNode<T>* m = model->getMiddle();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    QTreeWidgetItem* nodeM = 0;
    if(l) {
        nodeL = createResultNode(leftLabel , node , QString::number(l->getInfo()));
    }
    if(r) {
        nodeR = createResultNode(rightLabel , node , QString::number(r->getInfo()));
    }
    if(m) {
        nodeM = createResultNode(middleLabel , node , QString::number(m->getInfo()));
    }
    buildTernaryResult(nodeL , l);
    buildTernaryResult(nodeR , model->getRight());
    buildTernaryResult(nodeM , model->getMiddle());
}

template<typename T>
void CreateTreeArea::buildRBTResultTree(const RedBlackTreeModel<T>* model) {
    const BinaryRedBlackNode<T>* modelRoot = model->getRoot();
    createRootResultNode(root , QString::number(modelRoot->getInfo()));
    buildRBTResult(root , modelRoot);
}

template<typename T>
void CreateTreeArea::buildRBTResult(QTreeWidgetItem* node , const BinaryNode<T>* model) {
    if(!model)
        return;
    const BinaryNode<T>* l = model->getLeft();
    const BinaryNode<T>* r = model->getRight();
    QTreeWidgetItem* nodeL = 0;
    QTreeWidgetItem* nodeR = 0;
    createResultSingleNode("color : Black" , node);
    if(l) {
        nodeL = createResultNode(leftLabel , node , QString::number(l->getInfo()));
        createResultSingleNode("color : Black" , nodeL);
    }
    if(r) {
        nodeR = createResultNode(rightLabel , node , QString::number(r->getInfo()));
        createResultSingleNode("color : Black" , nodeR);
    }
    buildBinaryResult(nodeL , l);
    buildBinaryResult(nodeR , model->getRight());
}

#endif // CREATETREEAREA_H
/*
 * ctor view mode1 instantiates the model with default values
 * ctor view mode2 is created with model
 * */
