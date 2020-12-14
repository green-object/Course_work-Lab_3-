#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addeditdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentRow = -1;
    //настройка объекта Таблица
    ui->m_tableWidget->setDragEnabled(false);
    ui->m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_tableWidget->setColumnCount(5);
    ui->m_tableWidget->setColumnWidth(0,ui->m_tableWidget->width()*1/10-5);
    ui->m_tableWidget->setColumnWidth(1,ui->m_tableWidget->width()*4/10-5);
    ui->m_tableWidget->setColumnWidth(2,ui->m_tableWidget->width()*1/10-5);
    ui->m_tableWidget->setColumnWidth(3,ui->m_tableWidget->width()*2/10-5);
    ui->m_tableWidget->setColumnWidth(4,ui->m_tableWidget->width()*2/10-5);
    //установка заголовков таблицы
    QTableWidgetItem *hdr1 = new QTableWidgetItem(tr("N/N"));
    QTableWidgetItem *hdr2 = new QTableWidgetItem(tr("ФИО"));
    QTableWidgetItem *hdr3 = new QTableWidgetItem(tr("Курс"));
    QTableWidgetItem *hdr4 = new QTableWidgetItem(tr("Баллы"));
    QTableWidgetItem *hdr5 = new QTableWidgetItem(tr("Рейтинг"));
    ui->m_tableWidget->setHorizontalHeaderItem(0, hdr1);
    ui->m_tableWidget->setHorizontalHeaderItem(1, hdr2);
    ui->m_tableWidget->setHorizontalHeaderItem(2, hdr3);
    ui->m_tableWidget->setHorizontalHeaderItem(3, hdr4);
    ui->m_tableWidget->setHorizontalHeaderItem(4, hdr5);
    ui->m_tableWidget->setRowCount(0);
    connect(ui->m_tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(tableItemClicked(QTableWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//обработчик кнопки добавления студента
void MainWindow::on_btnAdd_clicked()
{
    //диалог добавления студента
    AddEditDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted)
    {
        //получение объекта студента
        Student currentStudent = dlg.getCurrentStudent();
        QMap<Student, int> map;
        map.insert(currentStudent, 0);
        //добавление студента в список
        ratings<<map;
        //обновление таблицы
        updateData();
    }
}
//обработчик кнопки удаления студента
void MainWindow::on_btnDelete_clicked()
{
    if (currentRow >=0 )
    {
        //удаление студента из списка
        ratings.removeAt(currentRow);
        //обновление таблицы
        updateData();
        //диалоговое окно пользователю
        QMessageBox msg(this);
        msg.setText("Удалено!");
        msg.exec();
    }
}
//обработчик кнопки "Расчитать"
void MainWindow::on_btnCalculate_clicked()
{
    Rating rating;
    //установка исходного списка
    rating.setRatings(ratings);
    //расчет
    rating.calculate();
    //получение итогового списка
    ratings = rating.getRatings();
    //обновление таблицы
    updateData();
}

//Выход из программы
void MainWindow::on_btnExit_clicked()
{
    qApp->exit();
}
//обновление таблицы
void MainWindow::updateData()
{
    //очистка таблицы
    ui->m_tableWidget->clear();
    //настройка объекта Таблица
    ui->m_tableWidget->setDragEnabled(false);
    ui->m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->m_tableWidget->setColumnCount(5);
    ui->m_tableWidget->setColumnWidth(0,ui->m_tableWidget->width()*1/10-5);
    ui->m_tableWidget->setColumnWidth(1,ui->m_tableWidget->width()*4/10-5);
    ui->m_tableWidget->setColumnWidth(2,ui->m_tableWidget->width()*1/10-5);
    ui->m_tableWidget->setColumnWidth(3,ui->m_tableWidget->width()*2/10-5);
    ui->m_tableWidget->setColumnWidth(4,ui->m_tableWidget->width()*2/10-5);
    //установка заголовков таблицы
    QTableWidgetItem *hdr1 = new QTableWidgetItem(tr("N/N"));
    QTableWidgetItem *hdr2 = new QTableWidgetItem(tr("ФИО"));
    QTableWidgetItem *hdr3 = new QTableWidgetItem(tr("Курс"));
    QTableWidgetItem *hdr4 = new QTableWidgetItem(tr("Баллы"));
    QTableWidgetItem *hdr5 = new QTableWidgetItem(tr("Рейтинг"));
    ui->m_tableWidget->setHorizontalHeaderItem(0, hdr1);
    ui->m_tableWidget->setHorizontalHeaderItem(1, hdr2);
    ui->m_tableWidget->setHorizontalHeaderItem(2, hdr3);
    ui->m_tableWidget->setHorizontalHeaderItem(3, hdr4);
    ui->m_tableWidget->setHorizontalHeaderItem(4, hdr5);
    ui->m_tableWidget->setRowCount(ratings.size());
    //заполнение таблицы данными из списка
    for (int i = 0; i < ratings.size(); i++)
    {
        QMap<Student, int> map = ratings.at(i);
        Student item = map.firstKey();
        QTableWidgetItem *value1 = new QTableWidgetItem(QString::number(i+1));
        ui->m_tableWidget->setItem(i, 0, value1);
        QTableWidgetItem *value2 = new QTableWidgetItem(item.getFio());
        ui->m_tableWidget->setItem(i, 1, value2);
        QTableWidgetItem *value3 = new QTableWidgetItem(QString::number(item.getCourse()));
        ui->m_tableWidget->setItem(i, 2, value3);
        QTableWidgetItem *value4 = new QTableWidgetItem(QString::number(item.getRating()));
        ui->m_tableWidget->setItem(i, 3, value4);
        QTableWidgetItem *value5 = new QTableWidgetItem(QString::number(map.value(item)));
        ui->m_tableWidget->setItem(i, 4, value5);
    }
}

//щелчок на поле таблицы
void MainWindow::tableItemClicked(QTableWidgetItem* item)
{
    currentRow = item->row();
}
