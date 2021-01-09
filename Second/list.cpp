#include "list.h"

int list::getTaskCount() const
{
    return taskCount;
}

void list::setTaskCount(int value)
{
    taskCount = value;
}

QListWidget list::getListWidget() const
{
    return listWidget;
}

void list::setListWidget(const QListWidget &value)
{
    listWidget = value;
}

int list::getListWidgetNumber() const
{
    return listWidgetNumber;
}

void list::setListWidgetNumber(int value)
{
    listWidgetNumber = value;
}

list::list()
{

}
