/********************************************************************************
** Form generated from reading UI file 'createtask.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETASK_H
#define UI_CREATETASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateTask
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QLabel *label_5;
    QTextEdit *TaskName;
    QTextEdit *description;
    QLabel *label_6;
    QDateTimeEdit *Startingat;
    QLabel *label_7;
    QDateTimeEdit *Endsat;
    QLabel *label_8;
    QFrame *line_2;

    void setupUi(QDialog *CreateTask)
    {
        if (CreateTask->objectName().isEmpty())
            CreateTask->setObjectName(QString::fromUtf8("CreateTask"));
        CreateTask->resize(618, 278);
        buttonBox = new QDialogButtonBox(CreateTask);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame = new QFrame(CreateTask);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 591, 201));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 10, 71, 16));
        label_5->setAlignment(Qt::AlignCenter);
        TaskName = new QTextEdit(frame);
        TaskName->setObjectName(QString::fromUtf8("TaskName"));
        TaskName->setGeometry(QRect(10, 30, 251, 41));
        description = new QTextEdit(frame);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(10, 90, 251, 71));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 70, 61, 16));
        Startingat = new QDateTimeEdit(frame);
        Startingat->setObjectName(QString::fromUtf8("Startingat"));
        Startingat->setGeometry(QRect(340, 40, 194, 22));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Startingat->sizePolicy().hasHeightForWidth());
        Startingat->setSizePolicy(sizePolicy);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(410, 10, 61, 16));
        label_7->setAlignment(Qt::AlignCenter);
        Endsat = new QDateTimeEdit(frame);
        Endsat->setObjectName(QString::fromUtf8("Endsat"));
        Endsat->setGeometry(QRect(340, 110, 194, 22));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(410, 80, 61, 16));
        label_8->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 180, 591, 16));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);

        retranslateUi(CreateTask);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateTask, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateTask, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateTask);
    } // setupUi

    void retranslateUi(QDialog *CreateTask)
    {
        CreateTask->setWindowTitle(QCoreApplication::translate("CreateTask", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("CreateTask", "Task Name", nullptr));
        label_6->setText(QCoreApplication::translate("CreateTask", "Description", nullptr));
        label_7->setText(QCoreApplication::translate("CreateTask", "Starting at", nullptr));
        label_8->setText(QCoreApplication::translate("CreateTask", "Ends at", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTask: public Ui_CreateTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETASK_H
