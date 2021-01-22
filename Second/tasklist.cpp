#include "tasklist.h"

QListWidget *TaskList::getListWidget() const
{
    return listWidget;
}

void TaskList::setListWidget(QListWidget *value)
{
    listWidget = value;
}


void TaskList::addElementId(int id)
{
    taskInListID[taskCount] = id;
    taskCount++;
}

int TaskList::getElementId(int number)
{
    return taskInListID[number];
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
