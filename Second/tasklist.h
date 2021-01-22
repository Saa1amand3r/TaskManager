#ifndef TASKLIST_H
#define TASKLIST_H
#include <QListWidget>
#include <task.h>

class TaskList
{
private:
    int taskCount;
    QListWidget* listWidget = new QListWidget;
    int listWidgetNumber;
    int taskInListID[10000];
public:
    void addElementId(int id);
    int getElementId(int number);
    int getTaskCount() const;
    void setTaskCount(int value);
    int getListWidgetNumber() const;
    void setListWidgetNumber(int value);
    TaskList();
    QListWidget *getListWidget() const;
    void setListWidget(QListWidget *value);
};

#endif // TASKLIST_H
