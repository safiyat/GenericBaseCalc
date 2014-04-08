#ifndef GBCWINDOW_H
#define GBCWINDOW_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class GBCWindow;
}

class GBCWindow : public QDialog
{
	Q_OBJECT

public:
	explicit GBCWindow(QWidget *parent = 0);
	~GBCWindow();

private slots:
	void toUpper();
	void buttonConvertBase();
	void buttonAdd();
	void buttonSubtract();
	void buttonMultiply();
	void buttonDivide();
	void buttonXor();
	void buttonOr();
	void buttonAnd();
	void buttonNot();
	void buttonNand();
	void buttonNor();
	void buttonXnor();
	void changeOpBase();

private:
	Ui::GBCWindow *ui;
	int opBase;
	void updateBase();
	void setRES(quint64 result);
	QString NOT(QString string, int base);
	qulonglong NOT(qulonglong input);
};

#endif // GBCWINDOW_H
