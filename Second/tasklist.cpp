#include "tasklist.h"

QListWidget *TaskList::getListWidget() const
{
    return listWidget;
}

void TaskList::setListWidget(QListWidget *value)
{
    listWidget = value;
}

string TaskList::getName() const
{
    return name;
}

void TaskList::setName(const string &value)
{
    name = value;
}

void TaskList::addElementId(int id)
{
    taskInListID[taskCount+1] = id;
    taskCount++;
}

int TaskList::getTaskCount() const
{
    return this->taskCount;
}

void TaskList::setTaskCount(int value)
{
    this->taskCount = value;
}


int TaskList::getListWidgetNumber() const
{
    return this->listWidgetNumber;
}

void TaskList::setListWidgetNumber(int value)
{
    this->listWidgetNumber = value;
}

TaskList::TaskList()
{

}
