#include"ExceptionHandler.h"
QMap<int , QString> ExceptionHandler::errorTable = Init();

        QMap<int , QString> ExceptionHandler::Init() {
			QMap<int , QString> tmp;
            tmp.insert(0 , "Malformed expression" );
            tmp.insert(1 , "Can't perform rotation on this tree" );
            tmp.insert(2 , "SumRedNodes works only on RedBlack trees" );
            tmp.insert(3 ,"SumBlackNodes works only on RedBlack trees" );
            tmp.insert(4 , "Can't Sum incompatible trees" );
            tmp.insert(5 , "Can't Intersect incompatible trees" );
            tmp.insert(6 , "SumMiddle works only on Ternary trees" );
            tmp.insert(7 , "BlackHeight works only on RedBlack trees" );
            tmp.insert(8 , "Empty Intersection" );
			return tmp;
		}

QString ExceptionHandler::what() const { return errorTable.value(signal , "Malformed Expression"); }

ExceptionHandler::ExceptionHandler(int val) : signal(val) {}

ExceptionHandler::~ExceptionHandler() {}

