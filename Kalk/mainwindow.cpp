#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::CURR_TREES_NUMBER = 0;// current # of trees
int MainWindow::CURR_TREE_INDEX = 0;// current's tree index

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    validator(new QIntValidator(0,10000,this))
{
    ui->setupUi(this);
    controller = new Controller<int>(ui->ResultArea);
    labelResult = new QLabel(ui->ResultArea);
    labelResult->setMinimumWidth(180);
    labelResult->setStyleSheet("color:black;");
    signalMapperOperand = new QSignalMapper(this);
    signalMapper = new QSignalMapper(this);
    treeList.reserve(MAX_TREES_NUMBER);
    treeSelector.reserve(MAX_TREES_NUMBER);
    treeOperandSelector.reserve(MAX_TREES_NUMBER);
    setFixedSize(width() , height());
    int volume = (MAX_TREES_NUMBER * 2) - 1;
    expressionRegister.reserve(volume);
    expressionTextRegister.reserve(volume);
    ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
}

void MainWindow::closeEvent (QCloseEvent *event) {
    QMessageBox mess;
    mess.setText("You are about to leave the application.");
    mess.setInformativeText("Are you sure?");
    mess.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    mess.setDefaultButton(QMessageBox::Yes);
    int input = mess.exec();
    if (input == QMessageBox::No) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::on_executeButton_clicked() {
    try {
        evaluate();
        controller->updateValuesOnExecute(expressionTextRegister , treeList);
        controller->Calculate(expressionTextRegister);
        labelResult->hide();
        ui->ResultExpression->setText("Result expression : " + textExpressionArea);
        clearAllRegisters();
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
}


void MainWindow::on_BinaryRotationButton_clicked()
{
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    try {
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    controller->BinaryRotation(CURR_TREE_INDEX);
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
    }
}

/*
 * create model based on treeList[CURR_TREE_INDEX]
 * model->SumMiddle()
 * show result
 * */
void MainWindow::on_SumMiddleButton_clicked() {
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    try {
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    labelResult->setText("Result = " + QString::number(controller->SumMiddle(CURR_TREE_INDEX)));
    controller->closeResultView();
    labelResult->show();
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
    }
}

void MainWindow::on_SumRedNodesButton_clicked()
{
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    try {
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    labelResult->setText("Result = " + QString::number(controller->SumRedNodes(CURR_TREE_INDEX)));
    controller->closeResultView();
    labelResult->show();
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
    }
}

void MainWindow::on_SumBlackNodesButton_clicked()
{
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    try {
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    labelResult->setText("Result = " + QString::number(controller->SumBlackNodes(CURR_TREE_INDEX)));
    controller->closeResultView();
    labelResult->show();
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
    }
}

void MainWindow::on_BlackHeightButton_clicked() {
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    try {
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    labelResult->setText("Result = " + QString::number(controller->BlackHeight(CURR_TREE_INDEX)));
    controller->closeResultView();
    labelResult->show();
    } catch(ExceptionHandler ecc) { ui->errorArea->setText(ecc.what()); }
    }
}

void MainWindow::on_SumValuesButton_clicked() {
    if(CURR_TREES_NUMBER > 0) {
        ui->errorArea->setText("");
    controller->updateValuesOnExecute(CURR_TREE_INDEX , treeList);
    labelResult->setText("Result = " + QString::number(controller->SumValues(CURR_TREE_INDEX)));
    controller->closeResultView();
    labelResult->show();
    }
}

void MainWindow::on_SumButton_clicked() {
    updateExpressionRegisters(false , "+ ");
    controller->addSumOperation();
}

void MainWindow::on_IntersectionButton_clicked() {
    updateExpressionRegisters(false , "I ");
    controller->addIntersectionOperation();
}

/*
 * removes last elements in expressionRegister and expressionTextRegister
 * updates textExpressionArea
*/
void MainWindow::on_UndoOperationButton_clicked() {
    int index = expressionRegister.size() - 1;
    if(index >= 0) {
	if(!expressionRegister[index])
        	controller->undoOperation();
	else
		controller->undoOperand();
    	expressionRegister.remove(index);
    	expressionTextRegister.remove(index);
    	updateOnUndoExpressionArea();
    }
}

/*
 * removes all elements from expressionRegister and expressionTextRegister
 * sets textExpressionArea = "" , removes all operations from the controller
 * */
    void MainWindow::clearAllRegisters() {
    textExpressionArea = "";
    ui->errorArea->setText("");
    ui->expressionArea->setText("");
    expressionRegister.clear();
    expressionTextRegister.clear();
    controller->removeAllOperations();
    controller->removeAllOperands();
    }

void MainWindow::on_ClearAllOperationButton_clicked() {
	clearAllRegisters(); 
    controller->removeAllOperations();
    controller->removeAllOperands();
}

/*adds operand to registers update tracking area*/
void MainWindow::addOperand(const int& val) {
    updateExpressionRegisters(true , QString::number(val) + " ");
}

/*
 * hides current shown tree and show the tree with index = val
*/
void MainWindow::hideTree(const int& val) {
    treeList[CURR_TREE_INDEX]->hide();
    treeList[CURR_TREE_INDEX]->setMaximumSize(0,0);
    treeList[val]->setMinimumSize(340,250);
    treeList[val]->show();
    CURR_TREE_INDEX = val;
}

/*
 check if the expression has alternated ones and zeros
*/
bool MainWindow::isWellFormed() const {
    for(int i = 0 , dim = expressionRegister.size() - 1; i < dim ; i++) {
        if(expressionRegister[i] == expressionRegister[i+1])
            return false;
    }
    return true;
}

/*
 * invoked for each operand's and operator's creation.
 * appends operation's symbol in registers and updates current expression.
*/
void MainWindow::updateExpressionRegisters(const bool& exprReg , const QString& exprTxtReg) {
    expressionRegister.append(exprReg);
    expressionTextRegister.append(exprTxtReg);
    textExpressionArea += exprTxtReg;
    ui->expressionArea->setText(textExpressionArea);
}

/*
    valuates expression's form.
    R =
    expressionRegister[last] = 1
    alternate 1 , 0 , 1 , 0 , 1
    valuates if operation order makes sense :
    (unary-operator) operand (binary-operator) operand
    if expressionTextRegister[0] == operator
    	malformed expression
*/
void MainWindow::evaluate() const throw(ExceptionHandler) {  
    int index = expressionRegister.size() - 1;
    if(index <= 1 || !expressionRegister[0] || (!isWellFormed()) ) {
        throw ExceptionHandler(0);
    }
}

// invoked when elements are remove from registers
// (except for "clear All" that sets everything to "")
void MainWindow::updateOnUndoExpressionArea() {
    textExpressionArea = "";
    for(int i = 0 , dim = expressionTextRegister.size(); i < dim ; i++) {
        textExpressionArea += expressionTextRegister[i];
    }
    ui->expressionArea->setText(textExpressionArea);
}

void MainWindow::on_createRBBinaryTree_clicked() {
    if(MAX_TREES_NUMBER > CURR_TREES_NUMBER) {
        CURR_TREES_NUMBER++;
        ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
        CreateTreeArea* tmp = new CreateRBTreeArea(validator , QString::number(CURR_TREES_NUMBER) + "-BinaryRBT" ,
                                                   ui->TreeHeightBox->value() ,
                                                   ui->scrollCreateTreeArea);
        treeList.push_back(tmp);
        updateOnTreeCreation();
        CreateRBTreeArea* rbt = dynamic_cast<CreateRBTreeArea*>(tmp);
        controller->addRedBlackTree(rbt->getComboBoxList() , ui->TreeHeightBox->value());
    }
    else
        ui->errorArea->setText("can't create new operands , max reached");
}

void MainWindow::on_createBinaryTree_clicked() {
    if(MAX_TREES_NUMBER > CURR_TREES_NUMBER) {
        CURR_TREES_NUMBER++;
        ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
        CreateTreeArea* tmp = new CreateBinaryTreeArea(validator , QString::number(CURR_TREES_NUMBER) + "-Binary" ,
                                                       ui->TreeHeightBox->value() ,
                                                       ui->scrollCreateTreeArea);
        treeList.push_back(tmp);
        updateOnTreeCreation();
        controller->addBinaryTree(ui->TreeHeightBox->value());
    }
    else
        ui->errorArea->setText("can't create new operands , max reached");
}

void MainWindow::on_createTernaryTree_clicked() {
    if(MAX_TREES_NUMBER > CURR_TREES_NUMBER) {
        CURR_TREES_NUMBER++;
        ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
        CreateTreeArea* tmp = new CreateTernaryTreeArea(validator , QString::number(CURR_TREES_NUMBER) + "-Ternary" ,
                                                        ui->TreeHeightBox->value() ,
                                                        ui->scrollCreateTreeArea);
        treeList.push_back(tmp);
        updateOnTreeCreation();
        controller->addTernaryTree(ui->TreeHeightBox->value());
    }
    else
        ui->errorArea->setText("can't create new operands , max reached");
}

/*
if scrollCreateTreeArea has already a tree => hides current tree and shrink it
updates registers and show the newly created tree
*/
void MainWindow::updateOnTreeCreation() {
    if(CURR_TREES_NUMBER > 1) {
        treeList[CURR_TREES_NUMBER - 2]->setMaximumSize(0,0);
        treeList[CURR_TREES_NUMBER - 2]->hide();
    }
    CURR_TREE_INDEX = CURR_TREES_NUMBER - 1;
    treeList[CURR_TREE_INDEX]->show();
    createTreeSelectorButton();
}

/*
   invoked when a button inside treeSelectorArea is clicked
*/
void MainWindow::keyPressed(int val) {
    hideTree(val);
}

/*
puts in expression register the right operand , updates tracking area
*/
void MainWindow::createOperand(int val) {
    addOperand(val+1);
}

/*
creates buttons in treeSelectorArea and map them to signalMapper
same for treeSelectOp
*/
void MainWindow::createTreeSelectorButton() {
    ui->treeSelectorArea->addWidget(createSignaledButton(*signalMapper , treeSelector));
    ui->treeSelectOp->addWidget(createSignaledButton(*signalMapperOperand , treeOperandSelector));
    connect(signalMapperOperand , SIGNAL(mapped(int)) , this , SLOT(createOperand(int)) , Qt::UniqueConnection);
    connect(signalMapper , SIGNAL(mapped(int)) , this , SLOT(keyPressed(int)) , Qt::UniqueConnection);
}

QPushButton* MainWindow::createSignaledButton(QSignalMapper& signalMap , QVector<QPushButton*>& list) {
    list.append(new QPushButton(this));
    int index = list.size() - 1;
    list[index]->setMaximumWidth(100);
    list[index]->setText(treeList[index]->getTreeHeaderLabel());
    connect(list[index] , SIGNAL(clicked()) , &signalMap , SLOT(map()));
    signalMap.setMapping(list[index] , index);
    return list[index];
}

/*
deletes all buttons in treeSelectorArea and treeSelectOp
*/
void MainWindow::clearAllTreeSelectorButtons() {
    int dim = treeSelector.size();
    for(int i = 0; i < dim ; i++) {
        delete treeSelector[i];
        delete treeOperandSelector[i];
    }
    treeSelector.clear();
    treeOperandSelector.clear();
}

/*
deletes button with max index in treeSelectorArea 
(does the same for treeOperandSelector)
*/
void MainWindow::clearTreeSelectorButton() {
    int index = treeSelector.size() - 1;
    if(index >= 0) {
        QPushButton* aux = treeSelector[index];
        treeSelector.remove(index);
        delete aux;
        aux = treeOperandSelector[index];
        treeOperandSelector.remove(index);
        delete aux;
    }
}

void MainWindow::on_UndoTreeButton_clicked() {
    int toDelete = ui->delTreeSpinBox->value() - 1;
    if(CURR_TREES_NUMBER >= 1 && toDelete >= 0) {
        CURR_TREES_NUMBER--;
        ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
        treeList.at(toDelete)->close();
        treeList.remove(toDelete);
        controller->removeTree(toDelete);
        clearTreeSelectorButton();
        CURR_TREE_INDEX = treeList.size() - 1;
        if(CURR_TREE_INDEX >= 0 && CURR_TREES_NUMBER >= 1) {
            treeList[CURR_TREE_INDEX]->setMaximumSize(340,250);
            treeList[CURR_TREE_INDEX]->setMinimumSize(340,250);
            treeList[CURR_TREE_INDEX]->show();
        }
        for(int i = 0 , dim = treeList.size(); i < dim ; i++) {
            QString tmp = treeList[i]->getTreeHeaderLabel();
            tmp.remove(tmp.at(0));
            tmp.prepend(QString::number(i+1));
            treeList[i]->setTreeHeaderLabel(tmp);
            treeSelector[i]->setText(tmp);
            treeOperandSelector[i]->setText(tmp);
        }
        clearAllRegisters();
    }
}

void MainWindow::on_clearAllTreesButton_clicked() {
    if(CURR_TREES_NUMBER >= 1){
    QMessageBox mess;
    mess.setText("Clear All trees.");
    mess.setInformativeText("Are you sure?");
    mess.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    mess.setDefaultButton(QMessageBox::Yes);
    int input = mess.exec();
    if (input == QMessageBox::Yes) {
        CURR_TREE_INDEX = 0;
        while(CURR_TREES_NUMBER) {
            CURR_TREES_NUMBER--;
            ui->delTreeSpinBox->setMaximum(CURR_TREES_NUMBER);
            treeList.at(CURR_TREES_NUMBER)->close();
            treeList.remove(CURR_TREES_NUMBER);
        }
        clearAllTreeSelectorButtons();
        clearAllRegisters();
        controller->removeAllTrees();
    }
    }
}

MainWindow::~MainWindow() {
    for(int i = 0 , size = treeList.size(); i < size; ++i) {
        delete treeList[i];
    	delete treeSelector[i];
        delete treeOperandSelector[i];
    }
    delete signalMapper;
    delete signalMapperOperand;
    delete validator;
    delete controller;
    delete ui;
}
