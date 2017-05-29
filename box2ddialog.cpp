#include "box2ddialog.h"
#include "ui_box2ddialog.h"

Box2dDialog::Box2dDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Box2dDialog)
{
    ui->setupUi(this);
}

Box2dDialog::~Box2dDialog()
{
    delete ui;
}
