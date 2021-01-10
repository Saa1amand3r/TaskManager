#include "task.h"

string Task::getStartTime() const
{
    return StartTime;
}

void Task::setStartTime(const string &value)
{
    StartTime = value;
}

string Task::getName() const
{
    return name;
}

void Task::setName(const string &value)
{
    name = value;
}

string Task::getDescription() const
{
    return description;
}

void Task::setDescription(const string &value)
{
    description = value;
}

string Task::getScheduledStartTime() const
{
    return ScheduledStartTime;
}

void Task::setScheduledStartTime(const string &value)
{
    ScheduledStartTime = value;
}

string Task::getScheduledEndTime() const
{
    return ScheduledEndTime;
}

void Task::setScheduledEndTime(const string &value)
{
    ScheduledEndTime = value;
}

string Task::getEndTime() const
{
    return EndTime;
}

void Task::setEndTime(const string &value)
{
    EndTime = value;
}

bool Task::getIn_action() const
{
    return in_action;
}

void Task::setIn_action(bool value)
{
    in_action = value;
}

//void Task::setTaskPosition(int value, int index)
//{
//    taskPosition[index] = value;
//}

//int Task::getTaskPosition(int index)
//{
//    return taskPosition[index];
//}

//int *Task::getTaskPosition()
//{
//    return taskPosition;
//}

//int Task::getTaskPositionCount() const
//{
//    return taskPositionCount;
//}

//void Task::setTaskPositionCount(int value)
//{
//    taskPositionCount = value;
//}

int Task::getTaskID() const
{
    return TaskID;
}

void Task::setTaskID(int value)
{
    TaskID = value;
}

Task::Task(){
    this->in_action = false;
}

Task::~Task()
{
    
}

