#include "gbcwindow.h"
#include "ui_gbcwindow.h"

GBCWindow::GBCWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GBCWindow)
{
    ui->setupUi(this);
}

GBCWindow::~GBCWindow()
{
    delete ui;
}

void GBCWindow::ToUpper()
{
    ui -> NUM1 -> setText (ui -> NUM1 -> text().toUpper());
    ui -> NUM2 -> setText (ui -> NUM2 -> text().toUpper());
}


void GBCWindow::validate()
{
//    ui->NUM1->setInputMask("-;>n");
//    ui->NUM1->setCursorPosition(-1);

}
