#ifndef HOWTOPLAYDIALOG_H
#define HOWTOPLAYDIALOG_H

#include <QDialog>

namespace Ui {
class HowToPlayDialog;
}

class HowToPlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HowToPlayDialog(QWidget *parent = nullptr);
    ~HowToPlayDialog();

private:
    Ui::HowToPlayDialog *ui;
};

#endif // HOWTOPLAYDIALOG_H
