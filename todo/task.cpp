#include "task.h"
#include "ui_task.h"

#include <QInputDialog>

Task::Task(QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::editName);
    connect(ui->removeButton, &QPushButton::clicked,
            [this] { emit remove(this);});
    connect(ui->checkBox, &QCheckBox::toggled,
            this, &Task::Checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(QString &name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Task::editName()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Edit Task"),
                                         tr("task name"), QLineEdit::Normal,
                                         this->name(), &ok);
    if (ok && !name.isEmpty())
        this->setName(name);
}

void Task::Checked(bool checked)
{
    QFont font {ui->checkBox->font()};
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged();
}
