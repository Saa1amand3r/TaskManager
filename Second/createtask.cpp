#include "createtask.h"
#include "ui_createtask.h"

CreateTask::CreateTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTask)
{
    ui->setupUi(this);
    accepted = false;
    rejected_v = false;
}

CreateTask::~CreateTask()
{
    delete this->t;
    delete ui;
}

void CreateTask::on_buttonBox_accepted()
{
    string name = ui->TaskName->toPlainText().toStdString();
    string description = ui->description->toPlainText().toStdString();
    string startingAt = ui->Startingat->text().toStdString();
    string endsAt = ui->Endsat->text().toStdString();
    this->t->setName(name);
    this->t->setDescription(description);
    this->t->setScheduledStartTime(startingAt);
    this->t->setScheduledEndTime(endsAt);
    accepted = true;
}

Task* CreateTask::returnTask() {
    return this->t;
}

bool CreateTask::check_access() {
    return accepted;
}

bool CreateTask::rejected()
{
    return rejected_v;
}



void CreateTask::on_buttonBox_rejected()
{
    rejected_v = true;
}
