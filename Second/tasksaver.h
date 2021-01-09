#ifndef TASKSAVER_H
#define TASKSAVER_H
#include <fstream>
#include<task.h>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <tasklist.h>
class TaskSaver
{
private:
    const string saveFileForTasks = "tasks.save.logFile";
    const string taskCountFile = "TaskCount.logFile";
    const string saveFileForLists = "list.save.logFile";
    const string saveListCountFile = "listCount.save.logFile";

    int findTaskCount();
    int findTaskListCount();
public:
    TaskSaver();
    void SaveCurrentLists(TaskList listArchive[], int listCount);
    int LoadTaskLists(TaskList listArchive[]);
    void SaveCurrentTasks(Task t[], int taskCount);
    int LoadTasks(Task t[]);
    void DeleteTask(Task t, int TaskNumber);
};

#endif // TASKSAVER_H
