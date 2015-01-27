#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->setColumnWidth(1,50);
    ui->tableWidget->setGeometry(0,0,210,400);
    ui->tableWidget_2->setColumnWidth(0,50);
    ui->tableWidget_2->setColumnWidth(1,50);
    ui->tableWidget_2->setGeometry(ui->tableWidget_2->x(),ui->tableWidget_2->y(),220,400);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionHesapla_triggered()
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
    myitem1 = new QTableWidgetItem;
    myitem1->setText(QString(resultstr));
    ui->tableWidget_3->setItem(0,0,myitem1);
}

void MainWindow::on_actionRaporla_triggered()
{
    FILE * rapor;
    char mystr[20];
    wchar_t mywstr[20];

    rapor = fopen("c:\\rapor.txt","w");
    ui->tableWidget->verticalHeaderItem(0)->text().toWCharArray(mywstr);
//    sprintf(mystr,"Kapasite = %d \n",ui->tableWidget->item(0,0)->text().toInt());
    fwrite(mywstr,20,20,rapor);
    fclose(rapor);

}
