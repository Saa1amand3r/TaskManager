#include "tasksaver.h"

TaskSaver::TaskSaver()
{}

void TaskSaver::SaveCurrentLists(TaskList listArchive[], int listCount)
{
    std::ofstream fListCount (saveListCountFile, ios::out);
    fListCount << listCount;
    fListCount.close();
    std::ofstream fTempFirstTime("firstTimeTemp.logFile", ios::out);
    fTempFirstTime << 0;
    fTempFirstTime.close();
}

int TaskSaver::LoadTaskLists(TaskList listArchive[], bool *firstTime)
{
    int listCount = findTaskListCount();
    std::ifstream fTempFirtsTime("firstTimeTemp.logFile", ios::in);
    if (!fTempFirtsTime.is_open()) { // если файл не открыт
            cout << "It is first time" << endl;
            *firstTime = true;
    }
    else {
        *firstTime= false;
        cout << "It is not first time" << endl;
    }
    fTempFirtsTime.close();
    return listCount;
}

int TaskSaver::findTaskListCount()
{
    std::ifstream fin (saveListCountFile, ios_base::in);
    char buf[50];
    fin.getline(buf,50);
    return atoi(buf);
}

void TaskSaver::SaveCurrentTasks(Task t[], int taskCount) {
    std::ofstream fout (saveFileForTasks, ios_base::out);
    for (int i = 0; i < taskCount; ++i) {
        fout << t[i].getName() << endl; //0
        fout << t[i].getDescription() << endl; //1
        fout << t[i].getScheduledStartTime() << endl; //2
        fout << t[i].getScheduledEndTime() << endl; //3
        fout << t[i].getIn_action() << endl; //4
//        fout << t[i].getTaskPositionCount() << endl; //5
//        for (int i = 0; i+1 <= t[i].getTaskPositionCount(); ++i) {
//            fout << t[i].getTaskPosition(i);
//        }
        fout << endl << endl;
        //6
        //7
        // Реальное время начала и конца будут указываться в другом файле - логе.
    }
    fout.close();
    std::ofstream taskfout (taskCountFile, ios_base::out);
    taskfout << taskCount;
    taskfout.close();
}

bool checkBool(string buf_s) {
    if (atoi(buf_s.c_str()) == 1) {
        return true;
    } else {
        return false;
    }
}

int TaskSaver::LoadTasks(Task t[])
{
    int taskCount = findTaskCount();
    std::ifstream fin(saveFileForTasks, ios_base::in);
    if (!fin.is_open()) { // если файл не открыт
            cout << "FileNotFoundException" << endl;
    } else {
        for (int i = 0, j = 0; i <= taskCount-1;) {
            char buf[50];
            fin.getline(buf,50);
            string buf_s = string(buf);
            if (buf_s.empty() || j > 5) {
                cout << "end of task" << endl;
                j=0;
                i++;
                fin.getline(buf,50);
            } else {
                switch (j) {
                    case 0: t[i].setName(buf_s); j++; break;
                    case 1: t[i].setDescription(buf_s);j++; break;
                    case 2: t[i].setScheduledStartTime(buf_s); j++; break;
                    case 3: t[i].setScheduledEndTime(buf_s); j++; break;
                    case 4: t[i].setIn_action(checkBool(buf_s)); j++; break;
//                    case 5: t[i].setTaskPositionCount(atoi(buf));
//                            for (int k = 0; k < t[k].getTaskPositionCount();k++) {
//                                fin.getline(buf,50);
//                                t[i].setTaskPosition(atoi(buf),k);
//                            }
//                            j++;
//                            break;
                }
            }
        }
    }
    fin.close();
    return taskCount;
}

int TaskSaver::findTaskCount()
{
    std::ifstream fin (taskCountFile, ios_base::in);
    char buf[50];
    fin.getline(buf,50);
    fin.close();
    return atoi(buf);
}

