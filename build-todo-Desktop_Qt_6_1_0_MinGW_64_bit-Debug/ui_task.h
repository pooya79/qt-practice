/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *removeButton;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QString::fromUtf8("Task"));
        Task->resize(505, 104);
        horizontalLayout = new QHBoxLayout(Task);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox = new QCheckBox(Task);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editButton = new QPushButton(Task);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        horizontalLayout->addWidget(editButton);

        removeButton = new QPushButton(Task);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("Task", "Buy Milk", nullptr));
        editButton->setText(QCoreApplication::translate("Task", "Edit", nullptr));
        removeButton->setText(QCoreApplication::translate("Task", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
