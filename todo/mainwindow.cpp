#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QinputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTasks()
{
    ui->setupUi(this);
    connect(ui->addtaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add Task"),
                                         tr("Task Name:"), QLineEdit::Normal,
                                         tr("Untitled Text"), &ok);
    if (ok && !name.isEmpty())
    {
        qDebug() << "new task has added";
        Task* task {new Task (name)};
        ui->taskLayout->addWidget(task);
        mTasks.append(task);
        connect(task, &Task::remove,
                this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged,
                this, &MainWindow::taskStatusChanged);
        updateStatus();
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->taskLayout->removeWidget(task);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged()
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    size_t CompletedCount {};
    for (auto task : mTasks)
    {
        if (task->isCompleted())
            CompletedCount++;
    }
    size_t todoCount {mTasks.size() - CompletedCount};
    ui->statusLabel->setText(
                QString("Status: %1 Completed / %2 todo").arg(CompletedCount).arg(todoCount));
}



