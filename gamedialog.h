#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>

namespace Ui {
class GameDialog;
}

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDialog(QWidget *parent = nullptr);
    ~GameDialog();

public slots:
    void finished();

private:
    Ui::GameDialog *ui;
};

#endif // GAMEDIALOG_H
