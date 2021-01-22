#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverclient.h"
#include <QTextBrowser>
#include "createtask.h"
#include <cstring>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) // главный метод
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TaskSaver *ts = new TaskSaver();
    taskListCount = ts->LoadTaskLists(taskListArchive);
    //int taskListCountTemp = ts->LoadTaskLists(taskListArchive);
    if (taskListCount > 0) {
        for (int i = 0; i < taskListCount;i++) {
            loadListOnScreen(&taskListArchive[i], i);
        }
        //taskListCount = taskListCountTemp;
    } else {
        cout << "it is first time" << endl;
    }

    int taskCountTemp= ts->LoadTasks(taskArchive);
    for (int i = 0; i < taskCountTemp; i++) {
        addTaskOnUI(&taskArchive[i]);
    }
    taskCount = taskCountTemp;

    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDropIndicatorShown(true);

    QScrollBar *sb = new QScrollBar(ui->centralwidget);
}

MainWindow::~MainWindow() // деструктор (при запуске деструктора сохраняются в файл сделанные задачи)
{
    TaskSaver *saver = new TaskSaver();
    if (taskListCount > 0) {
        saveTasksInLists();
        saver->SaveCurrentLists(taskListArchive, taskListCount);
    } else {
        cout << "No lists was created" << endl;
    }
    saver->SaveCurrentTasks(taskArchive, taskCount);
    delete saver;
    delete[] taskArchive;
    delete[] taskListArchive;
    delete ui;
}



void MainWindow::addTaskOnUI(Task *t) {
    ui->listWidget->addItem(t->getName().c_str());
    // Добавляем в массив-архив новую задачу
    ++taskCount;
    taskArchive[taskCount-1].setName(t->getName());
    taskArchive[taskCount-1].setDescription(t->getDescription());
    taskArchive[taskCount-1].setScheduledEndTime(t->getScheduledEndTime());
    taskArchive[taskCount-1].setScheduledStartTime(t->getScheduledStartTime());
    taskArchive[taskCount-1].setIn_action(t->getIn_action());
    taskArchive[taskCount-1].setTaskID(taskCount-1);
}



void MainWindow::on_sync_clicked() // Запуск сетевого модуля
{
    ServerClient server; // создаем объект сервера
    server.StartServer(); // запускаем batсh файл.
}

void MainWindow::on_AddTask_clicked() // срабатывает при нажатии на кнопку "Дрбавить задачу"
{
    CreateTask *ct = new CreateTask(); // создаем объект диалогового окна
    ct->show(); // отображаем диалоговое окно (не уверен, что это необхожимо
    if (ct->exec() == QDialog::Accepted) { // запускаем, если
        Task* t = ct->returnTask();
        addTaskOnUI(t);
        delete t;
    }
}

void MainWindow::on_addListBtn_clicked()
{
    addListOnScreen();
}

void MainWindow::loadListOnScreen(TaskList* tl, int i) // LOAD LIST FUNCTION
{
    QListWidget *NewlistWidget = new QListWidget(this);
    NewlistWidget->setAcceptDrops(true);
    NewlistWidget->setDropIndicatorShown(true);
    char buf[40] = {}; // буферная переменная для перевода числовой переменной в переменную типа String
    sprintf(buf,"%d",i); // Превращаем число в символ
    string number(buf); // заканчиваем преобразование числа в строку.
    string name = "ListNumber" + number; // Создаем имя для конкретного списка, чтобы была возможность удобно с ними взаимодействовать.
    NewlistWidget->setObjectName(name.c_str());
    if (i >0){
        int temp = taskListArchive[i-1].getListWidget()->geometry().x() + 300;
        NewlistWidget->setGeometry(temp,131,256,501);
    } else {
        int temp = ui->listWidget->geometry().x() + 350;
        NewlistWidget->setGeometry(temp,131,256,501);
    }
    tl->setListWidget(NewlistWidget);
    NewlistWidget->show();
}

void MainWindow::addListOnScreen() // ADD LIST FUNCTION
{
    QListWidget *NewlistWidget = new QListWidget(this); // Создаем новый виджет списка для демонстрации его в окне программы
    TaskList *tl = new TaskList(); // Создаем объект для удобной работы и хранения списков
    char buf[40] = {}; // буферная переменная для перевода числовой переменной в переменную типа String
    sprintf(buf,"%d",taskListCount); // Превращаем число в символ
    string number(buf); // заканчиваем преобразование числа в строку.
    string name = "ListNumber" + number; // Создаем имя для конкретного списка, чтобы была возможность удобно с ними взаимодействовать.
    tl->setListWidget(NewlistWidget); // Привязываем виджет списка к объекту
    tl->setListWidgetNumber(taskListCount); // Устанавливаем номер для списка
    tl->setTaskCount(0); // На будущее переменная, которая показывает какое кол-во задач находится в списке.
    NewlistWidget->setAcceptDrops(true);
    NewlistWidget->setDropIndicatorShown(true);
    NewlistWidget->setDefaultDropAction(Qt::MoveAction);
    NewlistWidget->setObjectName(name.c_str());
    if (taskListCount >0)
        NewlistWidget->setGeometry(taskListArchive[taskListCount-1].getListWidget()->geometry().x() + 400,131,256,501);
    else
        NewlistWidget->setGeometry(ui->listWidget->geometry().x() + 400,131,256,501);
    NewlistWidget->show();
    taskListArchive[taskListCount].setListWidget(tl->getListWidget());
    taskListArchive[taskListCount].setListWidgetNumber(tl->getListWidgetNumber());
    taskListArchive[taskListCount].setTaskCount(0);
    taskListCount++; // Увеличиваем на единицу количество списков, так как мы только что создали объект для хранения списков задач.
}

void MainWindow::checkChangesInTasksInList(TaskList tl)
{
    for (int i = 0; i < tl.getListWidget()->count(); i++) {
        string name = tl.getListWidget()->item(i)->text().toStdString();
        Task tempTask = findTaskByName(name);
        tl.addElementId(tempTask.getTaskID());
    }
}

void MainWindow::saveTasksInLists()
{
    for (int i = 0; i <taskListCount; i++) {
        checkChangesInTasksInList(taskListArchive[i]);
    }
}

Task MainWindow::findTaskByName(string name)
{
    for (int i = 0; i < taskCount; i++) {
        if (taskArchive[i].getName() == name) {
            return taskArchive[i];
        }
    }
}

Task MainWindow::findTaskByID(int id)
{
    for (int i = 0; i < taskCount; i++) {
        if (taskArchive[i].getTaskID() == id) {
            return taskArchive[i];
        }
    }
}

