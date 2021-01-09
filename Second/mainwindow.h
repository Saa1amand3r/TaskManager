#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <task.h>
#include <tasksaver.h>
#include <QListWidget>
#include <qdrag.h>
#include <qmimedata.h>
#include <tasklist.h>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Task *taskArchive = new Task[10000];
    int taskCount = 0;
    TaskList *taskListArchive = new TaskList[1000];
    int taskListCount = 0;
    bool firstTime = true;
//    void checkForChanges();
    void addListOnScreen();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sync_clicked();

    void on_AddTask_clicked();
    void on_addListBtn_clicked();

//    void on_listWidget_itemPressed(QListWidgetItem *item);

protected:
    Ui::MainWindow *ui;



    /**
     * @brief addTaskOnUI
     * @param t
     * @details Метод отвечающий за создание задачи на экране, а также за сохранение данных о задачах в массив taskArchive, которые при завершении программы записывается в файл.
     */
    void addTaskOnUI(Task* t);


};
#endif // MAINWINDOW_H
