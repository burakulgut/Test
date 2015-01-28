#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->InputTable->setColumnWidth(0,50);
    ui->InputTable->setColumnWidth(1,50);
    ui->InputTable->setGeometry(0,0,210,400);
    ui->AdjustedInputTable->setColumnWidth(0,50);
    ui->AdjustedInputTable->setColumnWidth(1,50);
    ui->AdjustedInputTable->setGeometry(ui->AdjustedInputTable->x(),ui->AdjustedInputTable->y(),220,400);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
InputTable              AdjustedInputTable      OutputTable
0 Kapasite              0 N+                    0 PAM/NAM
1 CCA                   1 N-                    1 +Ah/gr
2 # +                   2 + Izg. Ağırlığı       2 -Ah/gr
3 # -                   3 + Izg. Kalınlığı      3 Eleman Set Kalınlığı
4 + sıvama              4 - Izg. Ağırlığı       4 Sıkıştırma Miktarı
5 - sıvama              5 - Izg. Kalınlığı      5 Asit Mik./(PAM+NAM)
6 Pozitif Kod           6 Faydalı Hücre Gen.    6 Ü.A. Asit Miktarı
7 Negatif Kod                                   7 Toplam Kurşun Miktarı
8 Sep. Kalınlığı                                8 Separatör Miktarı
9 Sep. Genişliği
*/

void MainWindow::on_actionHesapla_triggered()
{
    double result;
    char resultstr[10];
    QTableWidgetItem *myitem1;
    QTableWidgetItem *myitem2;

    myitem1 = ui->InputTable->item(0,0);
    myitem2 = ui->InputTable->item(1,0);
    if(myitem1!=0 && myitem2!=0)
        result = myitem1->text().toDouble()+myitem2->text().toDouble();
    else
        result=0;
    sprintf(resultstr,"%f",result);
    myitem1 = new QTableWidgetItem;
    myitem1->setText(QString(resultstr));
    ui->OutputTable->setItem(0,0,myitem1);
}

void MainWindow::on_actionRaporla_triggered()
{
    FILE * rapor;
    char mystr[20];
    wchar_t mywstr[20];

    rapor = fopen("c:\\rapor.txt","w");
    ui->InputTable->verticalHeaderItem(0)->text().toWCharArray(mywstr);
//    sprintf(mystr,"Kapasite = %d \n",ui->InputTable->item(0,0)->text().toInt());
    fwrite(mywstr,20,20,rapor);
    fclose(rapor);

}
