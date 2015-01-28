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

    ui->OutputTable->setColumnWidth(0,50);
    ui->OutputTable->setColumnWidth(1,50);
    ui->OutputTable->setGeometry(ui->OutputTable->x(),ui->OutputTable->y(),250,400);
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
10 DrNAsitHacmi
*/
bool MainWindow::GetInputs(Inputs * TempInputs)
{
    QTableWidgetItem *myitem;
    bool result;

    result = 1;

    myitem = ui->InputTable->item(0,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->Capacity = 0;
    }
    else
    {
        TempInputs->Capacity = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(1,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->CCA = 0;
    }
    else
    {
        TempInputs->CCA = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(2,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->NofPositivePlates = 0;
    }
    else
    {
        TempInputs->NofPositivePlates = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(3,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->NofNegativePlates = 0;
    }
    else
    {
        TempInputs->NofNegativePlates = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(4,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->PositivePaste = 0;
    }
    else
    {
        TempInputs->PositivePaste = myitem->text().toFloat();
    }

    myitem = ui->InputTable->item(5,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->NegativePaste = 0;
    }
    else
    {
        TempInputs->NegativePaste = myitem->text().toFloat();
    }

    myitem = ui->InputTable->item(6,0);
    if (myitem == 0)
    {
        result=0;
 //       TempInputs->PositivePlateCode = 0;
    }
    else
    {
        myitem->text().toWCharArray(TempInputs->PositivePlateCode);
    }

    myitem = ui->InputTable->item(7,0);
    if (myitem == 0)
    {
        result=0;
 //       TempInputs->NegativePlateCode = 0;
    }
    else
    {
        myitem->text().toWCharArray(TempInputs->NegativePlateCode);
    }

    myitem = ui->InputTable->item(8,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->SeparatorThickness = 0;
    }
    else
    {
        TempInputs->SeparatorThickness = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(9,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->SeparatorWidth = 0;
    }
    else
    {
        TempInputs->SeparatorWidth = myitem->text().toShort();
    }

    myitem = ui->InputTable->item(10,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->DrNAcidVolume = 0;
    }
    else
    {
        TempInputs->DrNAcidVolume = myitem->text().toShort();
    }
    if(TempInputs->Capacity == 0 ||
            TempInputs->CCA==0 ||
            TempInputs->DrNAcidVolume==0 ||
            TempInputs->NegativePaste==0.0 ||
            TempInputs->NofNegativePlates==0 ||
            TempInputs->NofPositivePlates==0 ||
            TempInputs->PositivePaste==0.0 ||
            TempInputs->SeparatorThickness==0)
        result=0;

    return result;
}


void MainWindow::on_actionHesapla_triggered()
{
    bool getinputsresult;
    char resultstr[10];
    QTableWidgetItem * myitem1;
    Inputs * TempInputs;

    TempInputs= (Inputs*)malloc(sizeof(Inputs));

    getinputsresult=GetInputs(TempInputs);

    if (getinputsresult)
    {
        sprintf(resultstr,"%d",TempInputs->Capacity);
        myitem1 = new QTableWidgetItem;
        myitem1->setText(QString(resultstr));
        ui->OutputTable->setItem(0,0,myitem1);
    }
    else
    {
        myitem1 = new QTableWidgetItem;
        myitem1->setText("Invalid Input");
        ui->OutputTable->setItem(0,0,myitem1);
    }


    free(TempInputs);
}

void MainWindow::on_actionRaporla_triggered()
{
    FILE * rapor;
    wchar_t mywstr[20];

    rapor = fopen("c:\\rapor.txt","w");
    ui->InputTable->verticalHeaderItem(0)->text().toWCharArray(mywstr);
//    sprintf(mystr,"Kapasite = %d \n",ui->InputTable->item(0,0)->text().toInt());
    fwrite(mywstr,20,20,rapor);
    fclose(rapor);

}
