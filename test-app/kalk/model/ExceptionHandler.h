#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H
#include<QMap>
#include<QString>

class ExceptionHandler {
	private:
		int signal;
		static QMap<int , QString> errorTable;
		static QMap<int , QString> Init();
	public:
		QString what() const;
        explicit ExceptionHandler(int);
		~ExceptionHandler();
};

#endif
