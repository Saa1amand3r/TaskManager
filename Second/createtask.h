#ifndef CREATETASK_H
#define CREATETASK_H

#include <QDialog>
#include <task.h>

namespace Ui {
class CreateTask;
}

class CreateTask : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTask(QWidget *parent = nullptr);
    ~CreateTask();
    Task* returnTask();
    bool check_access();
    bool rejected();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Task* t = new Task();
    bool accepted;
    bool rejected_v;
    Ui::CreateTask *ui;
};

#endif // CREATETASK_H
