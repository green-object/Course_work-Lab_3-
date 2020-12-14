#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "rating.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QList<QMap<Student, int> > ratings;
    int currentRow;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateData();

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnCalculate_clicked();

    void on_btnExit_clicked();

    void tableItemClicked(QTableWidgetItem* item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
