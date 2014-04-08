#include "gbcwindow.h"
#include "ui_gbcwindow.h"

GBCWindow::GBCWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::GBCWindow)
{
	ui->setupUi(this);

	QValidator *ipVal;
	ipVal = new QRegExpValidator(QRegExp("[0-9A-Za-z]+$"));
	ui->NUM1->setValidator(ipVal);
	ui->NUM2->setValidator(ipVal);
	ui->BASE->setMinimum(2);
	ui->B1->setMaximum(36);
	ui->B2->setMaximum(36);
	ui->BASE->setMaximum(36);
	opBase = ui->BASE->text().toInt();
}

GBCWindow::~GBCWindow()
{
	delete ui;
}

void GBCWindow::toUpper()
{
	int pos1 = ui->NUM1->cursorPosition();
	int pos2 = ui->NUM2->cursorPosition();
	ui -> NUM1 -> setText (ui -> NUM1 -> text().toUpper());
	ui -> NUM2 -> setText (ui -> NUM2 -> text().toUpper());
	ui->NUM1->setCursorPosition(pos1);
	ui->NUM2->setCursorPosition(pos2);

	updateBase();
}

void GBCWindow::updateBase()
{
	QString text = ui->NUM1->text();
	QChar max = 0;
	int i;
	for(i = 0; i < text.length(); i++)
		if(max < text.at(i))
			max = text.at(i);
	if(max.isDigit())
	{
		i = max.toAscii() - 47;
		if(i < 2)
			i = 2;
		ui->B1->setMinimum(i);
		if(ui->B1->value()<(max.toAscii()-47))
			ui->B1->setValue(max.toAscii() - 47);
	}
	else
	{
		ui->B1->setMinimum(max.toAscii() - 54);
		if(ui->B1->value()<(max.toAscii() - 54))
			ui->B1->setValue(max.toAscii() - 54);
	}

	text = ui->NUM2->text();
	max = 0;
	for(int i = 0; i < text.length(); i++)
		if(max < text.at(i))
			max = text.at(i);
	if(max.isDigit())
	{
		i = max.toAscii() - 47;
		if(i < 2)
			i = 2;
		ui->B2->setMinimum(i);
		if(ui->B2->value()<(max.toAscii()-47))
			ui->B2->setValue(max.toAscii() - 47);
	}
	else
	{
		ui->B2->setMinimum(max.toAscii() - 54);
		if(ui->B2->value()<(max.toAscii() - 54))
			ui->B2->setValue(max.toAscii() - 54);
	}
}

void GBCWindow::buttonConvertBase()
{
	quint64 input = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	setRES(input);
}

void GBCWindow::buttonAdd()
{
	quint64 result;
	result = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt()) + ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	setRES(result);
}

void GBCWindow::buttonSubtract()
{
	quint64 result;
	result = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt()) - ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	setRES(result);
}

void GBCWindow::buttonMultiply()
{
	quint64 result;
	result = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt()) * ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	setRES(result);
}

void GBCWindow::buttonDivide()
{
	quint64 result;
	result = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt()) / ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	setRES(result);
}

void GBCWindow::buttonXor()
{
	quint64 result, a, ab, b, bb;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	/*
	ab = NOT(ui->NUM1->text(), ui->B1->text().toInt()).toULongLong(0, ui->B1->text().toInt());
	bb = NOT(ui->NUM2->text(), ui->B2->text().toInt()).toULongLong(0, ui->B2->text().toInt());
	*/
	ab = NOT(a);
	bb = NOT(b);
	result =  (a&bb) | (ab&b);
	setRES(result);
}

void GBCWindow::buttonOr()
{
	quint64 result, a, b;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	result =  a | b;
	setRES(result);
}

void GBCWindow::buttonAnd()
{
	quint64 result, a, b;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	result =  a & b;
	setRES(result);
}

void GBCWindow::buttonNot()
{
	quint64 result;
	result = NOT(ui->NUM1->text().toULongLong(0, ui->B1->text().toInt()));
	setRES(result);
}

void GBCWindow::buttonNand()
{
	quint64 result, a, b;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	/*
	QString temp;
	temp.setNum((a & b));
	result = NOT(temp, 10).toULongLong();
	*/
	result = NOT(a & b);
	setRES(result);
}

void GBCWindow::buttonNor()
{
	quint64 result, a, b;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	/*
	QString temp;
	temp.setNum((a | b));
	result = NOT(temp, 10).toULongLong();
	*/
	result = NOT(a | b);
	setRES(result);
}

void GBCWindow::buttonXnor()
{
	quint64 result, a, ab, b, bb;
	a = ui->NUM1->text().toULongLong(0, ui->B1->text().toInt());
	b = ui->NUM2->text().toULongLong(0, ui->B2->text().toInt());
	/*
	ab = NOT(ui->NUM1->text(), ui->B1->text().toInt()).toULongLong(0, ui->B1->text().toInt());
	bb = NOT(ui->NUM2->text(), ui->B2->text().toInt()).toULongLong(0, ui->B2->text().toInt());
	*/
	ab = NOT(a);
	bb = NOT(b);
	result =  NOT((a&bb) | (ab&b));
	setRES(result);
}

void GBCWindow::changeOpBase()
{
	quint64 input = ui->RES->text().toULongLong(0, opBase);
	setRES(input);
	opBase = ui->BASE->text().toInt();
}

void GBCWindow::setRES(quint64 result)
{
	QString res;
	res.setNum(result, ui->BASE->value());
	ui->RES->setText(res.toUpper());
}

QString GBCWindow::NOT(QString string, int base)
{
	quint64 input = string.toULongLong(0, base);
	QString ip;
	ip.setNum(input, 2);
	for(int i = 0; i < ip.length(); i++)
	{
		if(ip.at(i) == QChar('0'))
			ip.replace(i, 1, QChar('1'));
		else
			ip.replace(i, 1, QChar('0'));
	}
	input = ip.toULongLong(0, 2);
	ip.setNum(input, base);
	return ip;
}

qulonglong GBCWindow::NOT(qulonglong input)
{
	QString ip;
	ip.setNum(input, 2);
	for(int i = 0; i < ip.length(); i++)
	{
		if(ip.at(i) == QChar('0'))
			ip.replace(i, 1, QChar('1'));
		else
			ip.replace(i, 1, QChar('0'));
	}
	input = ip.toULongLong(0, 2);
	return input;
}
