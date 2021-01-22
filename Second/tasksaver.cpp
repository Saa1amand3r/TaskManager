#include "tasksaver.h"

// существует баг с загрузкой тасков, когда не все данные введены или сохранены.

TaskSaver::TaskSaver()
{}

void TaskSaver::SaveCurrentLists(TaskList listArchive[], int listCount)
{
    std::ofstream fListCount (saveListCountFile, ios::out);
    fListCount << listCount;
    fListCount.close();

    std::ofstream saveFile (saveFileForLists, ios::out);
    for (int i = 0; i < listCount; i++) {
        saveFile << listArchive[i].getListWidgetNumber() << endl; // 0
        saveFile << listArchive[i].getTaskCount() << endl; // 1
        for (int j = 0; j < listArchive[i].getTaskCount(); j++) {
            saveFile << listArchive->getElementId(j) << endl; // 2...10000
        }
        saveFile << endl;
    }
    saveFile.close();
}

int TaskSaver::LoadTaskLists(TaskList *listArchive)
{
    int listCount = findTaskListCount(); // переменная отвечающая за количество списков, которое надо загрузить
    std::ifstream loadFile(saveFileForLists, ios::in); // открываем файл с сейвом
    if (!loadFile.is_open()) { // проверка на первый запуск программы
        cout << "It is first time" << endl;
        return 0;
    }
    for (int i = 0, j =0; i < listCount;) {
        char buf[50];
        loadFile.getline(buf,50);
        string buf_s = string(buf);
        if (buf_s.empty() || j > 2) {
            cout << "end of list" << endl;
            j=0;
            i++;
            loadFile.getline(buf,50);
        }
        else {
            switch (j) {
                case 0: listArchive[i].setListWidgetNumber(atoi(buf)); break;
                case 1: listArchive[i].setTaskCount(atoi(buf)); break;
                case 2: {
                    for (int k=0; k < listArchive[i].getTaskCount(); k++) {
                        if (k == 0) {
                            listArchive[k].addElementId(atoi(buf));
                        } else{
                            loadFile.getline(buf,50);
                            listArchive[k].addElementId(atoi(buf));
                        }
                        j = 10;
                        break;
                    }
                }
            }
        }
    }

    return listCount;
}

int TaskSaver::findTaskListCount()
{
    std::ifstream fin (saveListCountFile, ios_base::in);
    char buf[50];
    fin.getline(buf,50);
    string buf_s (buf);
    if (buf_s.empty() || !fin.is_open()) {
        return 0;
    }
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

