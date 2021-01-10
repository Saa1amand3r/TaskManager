#ifndef TASK_H
#define TASK_H
#include <string>
using namespace std;
class Task
{
private:
    string name; // Название задания
    string description; // Описание задачи
    string ScheduledStartTime; // Запланированное время начала
    string ScheduledEndTime; // Запланированное время окончания
    string StartTime; // Время, в которое задание начали выполнять
    string EndTime; // Время, когда задание закончили выполнять.
    bool in_action; // Показывает выполняется ли в данный момент это задание
//    int taskPositionCount; // Сохраняется в скольки списках сохранено. начинается с 1
//    int *taskPosition = new int[10000]; // Номера списков начинаются с 1
    int TaskID;
public:
    Task();
    ~Task();
    string getStartTime() const;
    void setStartTime(const string &value);
    string getName() const;
    void setName(const string &value);
    string getDescription() const;
    void setDescription(const string &value);
    string getScheduledStartTime() const;
    void setScheduledStartTime(const string &value);
    string getScheduledEndTime() const;
    void setScheduledEndTime(const string &value);
    string getEndTime() const;
    void setEndTime(const string &value);
    bool getIn_action() const;
    void setIn_action(bool value);

//    void setTaskPosition(int value, int index);
//    int getTaskPosition(int index);
//    int* getTaskPosition();
//    int getTaskPositionCount() const;
//    void setTaskPositionCount(int value);
    int getTaskID() const;
    void setTaskID(int value);
};

#endif // TASK_H
