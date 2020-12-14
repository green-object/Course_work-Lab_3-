#include "addeditdialog.h"
#include "ui_addeditdialog.h"
#include <QMessageBox>

//селектор объекта студент
Student AddEditDialog::getCurrentStudent() const
{
    return currentStudent;
}
//модификатор объекта студент
void AddEditDialog::setCurrentStudent(const Student &value)
{
    currentStudent = value;
}

AddEditDialog::AddEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDialog)
{
    ui->setupUi(this);
    //валидатор на тектовое поле (можно ставить значение поля от 0 до 1000000)
    ui->mNumView->setValidator( new QIntValidator(0, 1000000, this) );
    ui->mLine->addItem(tr("Волонтерство"));
    ui->mLine->addItem(tr("Руководство проектом"));
    ui->mLine->addItem(tr("Студенческие медиа"));
    setWindowTitle(tr("Добавить"));
    //дизаблим ненужные секции
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
}

AddEditDialog::~AddEditDialog()
{
    delete ui;
}

//обработчик нажатия на кнопку ОК
void AddEditDialog::on_buttonBox_accepted()
{
    currentStudent.setFio(ui->mFio->text());
    currentStudent.setCourse(ui->mCourse->value());
    if (ui->mLine->currentText()==tr("Волонтерство"))
    {
        Volunteer *activity = new Volunteer();
        activity->setName(ui->mNameActivity->text());
        activity->setNHours(ui->mNHour->value());
        currentStudent.addActivity(activity);
    }
    if (ui->mLine->currentText()==tr("Руководство проектом"))
    {
        Event *activity = new Event();
        activity->setName(ui->mNameActivity->text());
        activity->setExpertMark(ui->mMark->value());
        currentStudent.addActivity(activity);
    }
    if (ui->mLine->currentText()==tr("Студенческие медиа"))
    {
        Media *activity = new Media();
        activity->setName(ui->mNameActivity->text());
        activity->setNCountViewVideo(ui->mNumView->text().toInt());
        currentStudent.addActivity(activity);
    }
    QMessageBox msg(this);
    msg.setText("Добавлено!");
    msg.exec();
}

//отбор выбранных секций по выбору пункта из списка направления
void AddEditDialog::on_mLine_currentTextChanged(const QString &arg1)
{
    if (arg1==tr("Волонтерство"))
    {
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
    }
    if (arg1==tr("Руководство проектом"))
    {
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(false);
    }
    if (arg1==tr("Студенческие медиа"))
    {
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(true);
    }
}
