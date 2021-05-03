#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QString& name, QWidget *parent = nullptr);
    ~Task();

    void setName(QString& name);
    QString name() const;
    bool isCompleted() const;

public slots:
    void editName();
    void Checked(bool checked);

signals:
    void remove(Task* task);
    void statusChanged();

private:
    Ui::Task *ui;
};

#endif // TASK_H
