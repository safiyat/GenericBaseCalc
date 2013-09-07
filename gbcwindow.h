#ifndef GBCWINDOW_H
#define GBCWINDOW_H

#include <QDialog>

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
    void ToUpper();
    void validate();
    
private:
    Ui::GBCWindow *ui;
};

#endif // GBCWINDOW_H
