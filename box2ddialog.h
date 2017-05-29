#ifndef BOX2DDIALOG_H
#define BOX2DDIALOG_H

#include <QDialog>

namespace Ui {
class Box2dDialog;
}

class Box2dDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Box2dDialog(QWidget *parent = 0);
    ~Box2dDialog();

private:
    Ui::Box2dDialog *ui;
};

#endif // BOX2DDIALOG_H
