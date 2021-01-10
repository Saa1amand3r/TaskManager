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
    string name;
    int taskInListID[10000];
public:
    void addElementId(int id);
    int getElementID(string name);
    int getTaskCount() const;
    void setTaskCount(int value);
    int getListWidgetNumber() const;
    void setListWidgetNumber(int value);
    TaskList();
    QListWidget *getListWidget() const;
    void setListWidget(QListWidget *value);
    string getName() const;
    void setName(const string &value);
};

#endif // TASKLIST_H
