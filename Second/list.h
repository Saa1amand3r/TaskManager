#ifndef LIST_H
#define LIST_H
#include <QListWidget>
#include <task.h>
class list
{
private:
    int taskCount;
    QListWidget listWidget;
    Task tasksInList[1000];
    int listWidgetNumber;
public:
    list();
    int getTaskCount() const;
    void setTaskCount(int value);
    QListWidget getListWidget() const;
    void setListWidget(const QListWidget &value);
    int getListWidgetNumber() const;
    void setListWidgetNumber(int value);
    Task getTaskInListElement(int index) {return tasksInList[index];}
    void addTaskInListElement(Task element);
};

#endif // LIST_H
