#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>
#include "student.h"
#include "volunteer.h"
#include "event.h"
#include "media.h"

namespace Ui {
class AddEditDialog;
}
//Диалог добавления записи Студент
class AddEditDialog : public QDialog
{
    Q_OBJECT
    //Объект студент
    Student currentStudent;
public:
    explicit AddEditDialog(QWidget *parent = 0);
    ~AddEditDialog();

    Student getCurrentStudent() const;
    void setCurrentStudent(const Student &value);

private slots:

    void on_buttonBox_accepted();

    void on_mLine_currentTextChanged(const QString &arg1);

private:
    Ui::AddEditDialog *ui;
};

#endif // ADDEDITDIALOG_H
