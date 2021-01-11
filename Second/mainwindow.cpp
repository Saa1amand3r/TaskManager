#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverclient.h"
#include <QTextBrowser>
#include "createtask.h"
#include <cstring>

/*
 * Сделать сохранение для firstTime переменной, чтобы избежать багов со списками.
*/

MainWindow::MainWindow(QWidget *parent) // главный метод
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TaskSaver *ts = new TaskSaver();

    int taskListCountTemp = ts->LoadTaskLists(taskListArchive, &firstTime);
    for (int i = 0; i < taskListCountTemp;i++) {
        addListOnScreen(i);
    }
    taskListCount = taskListCountTemp;

    int taskCountTemp= ts->LoadTasks(taskArchive);
    for (int i = 0; i < taskCountTemp; i++) {
        addTaskOnUI(&taskArchive[i]);
    }
    taskCount = taskCountTemp;

    ui->listWidget->setDragEnabled(true);
    ui->listWidget->setAcceptDrops(true);
    ui->listWidget->setDropIndicatorShown(true);
    //ui->listWidget->setDefaultDropAction(Qt::MoveAction);

//    ui->listWidget_2->setDragEnabled(false);
//    ui->listWidget_2->setAcceptDrops(true);
//    ui->listWidget_2->setDropIndicatorShown(true);
//    ui->listWidget_2->setDefaultDropAction(Qt::MoveAction);

//    taskListArchive[taskListCount].setListWidget(ui->listWidget_2);
//    taskListArchive[taskListCount].setListWidgetNumber(1);
//    taskListArchive[taskListCount].setName(ui->listWidget_2->objectName().toStdString());
//    taskListArchive[taskListCount].setTaskCount(0);
//    taskListArchive[1].setListWidget(ui->listWidget_2);
//    taskListArchive[1].setListWidgetNumber(1);
//    taskListArchive[1].setName(ui->listWidget_2->objectName().toStdString());
//    taskListArchive[1].setTaskCount(0);
}

MainWindow::~MainWindow() // деструктор (при запуске деструктора сохраняются в файл сделанные задачи)
{
    TaskSaver *saver = new TaskSaver();
    saver->SaveCurrentTasks(taskArchive, taskCount);
    saver->SaveCurrentLists(taskListArchive, taskListCount);
    delete saver;
    delete[] taskArchive;
    delete[] taskListArchive;
    delete ui;
}



void MainWindow::addTaskOnUI(Task *t) {
    /*QTextBrowser *qtb = new QTextBrowser(this); // создается объект QTextBrowser, в котором будет написано название задачи.
    char name[255];
    strcpy(name, t->getName().c_str()); //конвертируем имя задачи в переменную типа char для дальнейшей удобной работы.
    qtb->setObjectName(name); // устанавливаем имя для объекта
    qtb->setMaximumHeight(31); // устанавливаем размеры
    qtb->setText(name); // устанавливаем текст для объекта.
    qtb->setMinimumHeight(30); // устанавливаем размеры
    ui->verticalLayout->addWidget(qtb); // добавляем наш объект на verticallayout*/

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

void MainWindow::addListOnScreen(int i) // LOAD LIST FUNCTION
{
    QListWidget *NewlistWidget = new QListWidget(this); // Создаем новый виджет списка для демонстрации его в окне программы
    TaskList *tl = new TaskList(); // Создаем объект для удобной работы и хранения списков
    char buf[40] = {}; // буферная переменная для перевода числовой переменной в переменную типа String
    sprintf(buf,"%d",taskListCount); // Превращаем число в символ
    string number(buf); // заканчиваем преобразование числа в строку.
    string name = "ListNumber" + number; // Создаем имя для конкретного списка, чтобы была возможность удобно с ними взаимодействовать.
    tl->setListWidget(NewlistWidget); // Привязываем виджет списка к объекту
    tl->setName(name); // Привязываем имя для удобного различия и вызова списков
    tl->setListWidgetNumber(taskListCount); // Устанавливаем номер для списка
    tl->setTaskCount(0); // На будущее переменная, которая показывает какое кол-во задач находится в списке.
    NewlistWidget->setAcceptDrops(true);
    NewlistWidget->setDropIndicatorShown(true);
    NewlistWidget->setDefaultDropAction(Qt::MoveAction);
    NewlistWidget->setObjectName(name.c_str());
    if (firstTime || i==0) {
        NewlistWidget->setGeometry(/*620*/ ui->listWidget->geometry().x() + 350,131,256,501);
        firstTime = false;
    } else {
        NewlistWidget->setGeometry(/*620*/ taskListArchive[taskListCount-1].getListWidget()->geometry().x() + 300,131,256,501);
    }
    NewlistWidget->show();
    taskListArchive[taskListCount].setListWidget(tl->getListWidget());
    taskListArchive[taskListCount].setListWidgetNumber(tl->getListWidgetNumber());
    taskListArchive[taskListCount].setName(name);
    taskListArchive[taskListCount].setTaskCount(0);
    taskListCount++; // Увеличиваем на единицу количество списков, так как мы только что создали объект для хранения списков задач.
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
    tl->setName(name); // Привязываем имя для удобного различия и вызова списков
    tl->setListWidgetNumber(taskListCount); // Устанавливаем номер для списка
    tl->setTaskCount(0); // На будущее переменная, которая показывает какое кол-во задач находится в списке.
    NewlistWidget->setAcceptDrops(true);
    NewlistWidget->setDropIndicatorShown(true);
    NewlistWidget->setDefaultDropAction(Qt::MoveAction);
    NewlistWidget->setObjectName(name.c_str());
    if (firstTime) {
        NewlistWidget->setGeometry(/*620*/ ui->listWidget->geometry().x() + 350,131,256,501);
        firstTime = false;
    } else {
        NewlistWidget->setGeometry(/*620*/ taskListArchive[taskListCount-1].getListWidget()->geometry().x() + 300,131,256,501);
    }
    NewlistWidget->show();
    taskListArchive[taskListCount].setListWidget(tl->getListWidget());
    taskListArchive[taskListCount].setListWidgetNumber(tl->getListWidgetNumber());
    taskListArchive[taskListCount].setName(name);
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

