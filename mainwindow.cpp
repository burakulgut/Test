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
    ui->AdjustedInputTable->setGeometry(ui->AdjustedInputTable->x(),ui->AdjustedInputTable->y(),220,ui->AdjustedInputTable->height());

    ui->OutputTable->setColumnWidth(0,50);
    ui->OutputTable->setColumnWidth(1,50);
    ui->OutputTable->setGeometry(ui->OutputTable->x(),ui->OutputTable->y(),250,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Usermessage(char* mystr){

    QFont myFont;
    myFont.setPointSize(16);
    ui->MessageLabel->setFont(myFont);
    ui->MessageLabel->setText(mystr);
}
/*
InputTable              AdjustedInputTable      OutputTable                 ConstantsTable
0 Kapasite              0 N+                    0 PAM/NAM                   0 Taban Ah/kg
1 CCA                   1 N-                    1 +Ah/gr                    1 CCA / Plaka
2 # +                   2 + Izg. Ağırlığı       2 -Ah/gr                    2 Marj
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

bool MainWindow::GetAdjustedInputs(AdjustedInputs * TempAdjustedInputs)
{
    bool result;
    QTableWidgetItem * myitem;
    result = 1;

    myitem = ui->AdjustedInputTable->item(0,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->AdjustedPositivePlates = 0;
    }
    else
    {
        TempAdjustedInputs->AdjustedPositivePlates = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(1,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->AdjustedNegativePlates = 0;
    }
    else
    {
        TempAdjustedInputs->AdjustedNegativePlates = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(2,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->PositivePlateWeight = 0;
    }
    else
    {
        TempAdjustedInputs->PositivePlateWeight = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(3,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->PositivePlateThickness = 0;
    }
    else
    {
        TempAdjustedInputs->PositivePlateThickness = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(4,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->NegativePlateWeight = 0;
    }
    else
    {
        TempAdjustedInputs->NegativePlateWeight = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(5,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->NegativePlateThickness = 0;
    }
    else
    {
        TempAdjustedInputs->NegativePlateThickness = myitem->text().toFloat();
    }
    return result;

}

bool MainWindow::GetOutputs(Outputs * TempOutputs)
{
    bool result;
    QTableWidgetItem * myitem;
    result = 1;

    myitem = ui->OutputTable->item(0,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->PAMNAMRatio = 0;
    }
    else
    {
        TempOutputs->PAMNAMRatio = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(1,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->PositiveAhperg = 0;
    }
    else
    {
        TempOutputs->PositiveAhperg = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(2,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->NegativeAhperg = 0;
    }
    else
    {
        TempOutputs->NegativeAhperg = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(3,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->CellSetWidth = 0;
    }
    else
    {
        TempOutputs->CellSetWidth = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(4,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->CompressionThickness = 0;
    }
    else
    {
        TempOutputs->CompressionThickness = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(5,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->AcidperActiveMass = 0;
    }
    else
    {
        TempOutputs->AcidperActiveMass = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(6,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->ProdTreeAcidAmount = 0;
    }
    else
    {
        TempOutputs->ProdTreeAcidAmount = myitem->text().toFloat();
    }

    myitem = ui->OutputTable->item(7,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->TotalLeadAmount = 0;
    }
    else
    {
        TempOutputs->TotalLeadAmount = myitem->text().toFloat();
    }
    myitem = ui->OutputTable->item(8,0);
    if (myitem == 0)
    {
        result=0;
        TempOutputs->TotalSeparatorAmount = 0;
    }
    else
    {
        TempOutputs->TotalSeparatorAmount = myitem->text().toFloat();
    }
    return result;
}

bool MainWindow::GetConstants(Constants * TempConstants)
{
    bool result;
    QTableWidgetItem * myitem;
    result = 1;

    myitem = ui->ConstantsTable->item(0,0);
    if (myitem == 0)
    {
        result=0;
        TempConstants->BaseAhperkg = 0;
    }
    else
    {
        TempConstants->BaseAhperkg = myitem->text().toFloat();
    }

    myitem = ui->ConstantsTable->item(1,0);
    if (myitem == 0)
    {
        result=0;
        TempConstants->CCAperPlate = 0;
    }
    else
    {
        TempConstants->CCAperPlate = myitem->text().toFloat();
    }
    myitem = ui->ConstantsTable->item(2,0);
    if (myitem == 0)
    {
        result=0;
        TempConstants->Margin = 0;
    }
    else
    {
        TempConstants->Margin = myitem->text().toFloat();
    }
    return result;
}

bool MainWindow::PutAdjustedInputs(Inputs * TempAdjustedInputs){
    // To be implemented
}

bool MainWindow::PutOutputs(Outputs* TempOutputs){
    // To be implemented
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
        Usermessage("Invalid Input");
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
