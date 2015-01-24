#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCalculate_triggered()
{
    double result;
    char resultstr[10];
    QTableWidgetItem *myitem1;
    QTableWidgetItem *myitem2;

    myitem1 = ui->tableWidget->item(0,0);
    myitem2 = ui->tableWidget->item(1,0);
    if(myitem1!=0 && myitem2!=0)
        result = myitem1->text().toDouble()+myitem2->text().toDouble();
    else
        result=0;
    sprintf(resultstr,"%f",result);
    ui->textEdit->setText(resultstr);
}
