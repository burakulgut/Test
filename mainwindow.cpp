#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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

void MainWindow::Usermessage(const char* mystr){

    QFont myFont;
    myFont.setPointSize(16);
    ui->MessageLabel->setFont(myFont);
    ui->MessageLabel->setText(QString(mystr));
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
        TempInputs->SeparatorThickness = myitem->text().toFloat();
    }

    myitem = ui->InputTable->item(9,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->SeparatorWidth = 0;
    }
    else
    {
        TempInputs->SeparatorWidth = myitem->text().toFloat();
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
    myitem = ui->AdjustedInputTable->item(6,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->UsefulCellWidth = 0;
    }
    else
    {
        TempAdjustedInputs->UsefulCellWidth = myitem->text().toFloat();
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

bool MainWindow::PutAdjustedInputs(AdjustedInputs * TempAdjustedInputs)
{
    QTableWidgetItem *myItem;
    char mystr[10];

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%2.1f",TempAdjustedInputs->AdjustedPositivePlates);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(0,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%2.1f",TempAdjustedInputs->AdjustedNegativePlates);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(1,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.2f",TempAdjustedInputs->PositivePlateWeight);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(2,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempAdjustedInputs->PositivePlateThickness);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(3,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempAdjustedInputs->NegativePlateWeight);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(4,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.2f",TempAdjustedInputs->NegativePlateThickness);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(5,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempAdjustedInputs->UsefulCellWidth);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(6,0,myItem);

    return (bool)1;
}

bool MainWindow::PutOutputs(Outputs* TempOutputs)
{
    QTableWidgetItem *myItem;
    char mystr[10];

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->PAMNAMRatio);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(0,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->PositiveAhperg);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(1,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->NegativeAhperg);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(2,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->CellSetWidth);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(3,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->CompressionThickness);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(4,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempOutputs->AcidperActiveMass);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(5,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.1f",TempOutputs->ProdTreeAcidAmount);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(6,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.1f",TempOutputs->TotalLeadAmount);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(7,0,myItem);
    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.1f",TempOutputs->TotalSeparatorAmount);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(8,0,myItem);

    return (bool)1;
}

bool MainWindow::PutConstants(Constants* TempConstants)
{
    QTableWidgetItem *myItem;
    char mystr[10];

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempConstants->BaseAhperkg);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(0,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempConstants->CCAperPlate);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(1,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempConstants->Margin);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(2,0,myItem);

    return (bool)1;
}

bool MainWindow::PutInputs(Inputs* TempInputs)
{
    QTableWidgetItem *myItem;
    char mystr[10];

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3d",TempInputs->Capacity);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(0,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3d",TempInputs->CCA);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(1,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0d",TempInputs->NofPositivePlates);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(2,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0d",TempInputs->NofNegativePlates);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(3,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempInputs->PositivePaste);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(4,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempInputs->NegativePaste);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(5,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%ls",TempInputs->PositivePlateCode);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(6,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%ls",TempInputs->NegativePlateCode);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(7,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempInputs->SeparatorThickness);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(8,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3f",TempInputs->SeparatorWidth);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(9,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.3d",TempInputs->DrNAcidVolume);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(10,0,myItem);

    return(bool)1;
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

void MainWindow::on_CalcAdjustedInputsButton_clicked()
{
    bool getinputsresult,putadjustedinputsresult;
    Inputs * TempInputs;
    AdjustedInputs * MyAdjustedInputs;

    TempInputs= (Inputs*)malloc(sizeof(Inputs));
    MyAdjustedInputs = (AdjustedInputs*)malloc(sizeof(AdjustedInputs));

    getinputsresult=GetInputs(TempInputs);
    putadjustedinputsresult = false;
    if(getinputsresult){
       if (TempInputs->NofPositivePlates == TempInputs->NofNegativePlates)
       {
           MyAdjustedInputs->AdjustedPositivePlates=TempInputs->NofPositivePlates-0.2;
           MyAdjustedInputs->AdjustedNegativePlates=TempInputs->NofNegativePlates-0.2;
       }
       else
       {
           if(TempInputs->NofPositivePlates>TempInputs->NofNegativePlates)
           {
               MyAdjustedInputs->AdjustedPositivePlates=TempInputs->NofPositivePlates-0.4;
               MyAdjustedInputs->AdjustedNegativePlates=TempInputs->NofNegativePlates;
           }
           else
           {
               MyAdjustedInputs->AdjustedPositivePlates=TempInputs->NofPositivePlates;
               MyAdjustedInputs->AdjustedNegativePlates=TempInputs->NofNegativePlates-0.4;
           }
       }
       MyAdjustedInputs->NegativePlateWeight = 0.0;
       MyAdjustedInputs->NegativePlateThickness=0.0;
       MyAdjustedInputs->PositivePlateWeight = 0.0;
       MyAdjustedInputs->PositivePlateThickness=0.0;
       MyAdjustedInputs->UsefulCellWidth=0.0;

       putadjustedinputsresult=PutAdjustedInputs(MyAdjustedInputs);
    }


    if(getinputsresult && putadjustedinputsresult)
        Usermessage("Ayarlanmış girdiler tablosu güncellendi!");
    else
        Usermessage("Eksik giriş. Lütfen kontrol edin!");
    free(TempInputs);
    free(MyAdjustedInputs);
    return;
}

void MainWindow::on_InputTable_doubleClicked(const QModelIndex &index)
{
    (void)index;
    // i.e suppress the unused variable warning
    Usermessage("");
}

void MainWindow::on_CalcOutputsButton_clicked()
{
     bool getinputsresult,getadjustedinputsresult,putoutputsresult,getconstantsresult;
     Inputs * MyInputs;
     AdjustedInputs * MyAdjustedInputs;
     Outputs * MyOutputs;
     Constants * MyConstants;

     MyInputs= (Inputs*)malloc(sizeof(Inputs));
     MyAdjustedInputs = (AdjustedInputs*)malloc(sizeof(AdjustedInputs));
     MyOutputs = (Outputs*)malloc(sizeof(Outputs));
     MyConstants = (Constants *)malloc(sizeof(Constants));

     getinputsresult=GetInputs(MyInputs);
     getadjustedinputsresult = GetAdjustedInputs(MyAdjustedInputs);
     getconstantsresult = GetConstants(MyConstants);


     MyOutputs->PAMNAMRatio= MyInputs->NofPositivePlates*MyInputs->PositivePaste /(MyInputs->NofNegativePlates*MyInputs->NegativePaste);
     MyOutputs->PositiveAhperg = (MyInputs->NofPositivePlates*MyInputs->PositivePaste)/MyInputs->Capacity;
     MyOutputs->NegativeAhperg = (MyInputs->NofNegativePlates*MyInputs->NegativePaste)/MyInputs->Capacity;
     MyOutputs->CellSetWidth = MyInputs->NofPositivePlates*MyAdjustedInputs->PositivePlateThickness+MyInputs->NofNegativePlates*MyAdjustedInputs->NegativePlateThickness+2*MyInputs->NofNegativePlates*MyInputs->SeparatorThickness;
     MyOutputs->CompressionThickness = MyAdjustedInputs->UsefulCellWidth - MyOutputs->CellSetWidth;
     MyOutputs->AcidperActiveMass = MyInputs->DrNAcidVolume/(MyInputs->NofPositivePlates*MyInputs->PositivePaste+MyInputs->NofNegativePlates*MyInputs->NegativePaste);
     MyOutputs->ProdTreeAcidAmount= MyInputs->DrNAcidVolume*0.3795*1.285*6;
     MyOutputs->TotalLeadAmount= 6*(MyInputs->NofPositivePlates*MyAdjustedInputs->PositivePlateWeight + MyInputs->NofNegativePlates*MyAdjustedInputs->NegativePlateWeight+0.9*MyInputs->PositivePaste*MyInputs->NofPositivePlates+0.9*MyInputs->NegativePaste*MyInputs->NofNegativePlates);
     MyOutputs->TotalSeparatorAmount = 0.0;

     putoutputsresult = PutOutputs(MyOutputs);

     if(getinputsresult&&getadjustedinputsresult&&putoutputsresult&&getconstantsresult)
         Usermessage("Çıktılar tablosu güncellendi");
     else
     {
         if(!getinputsresult)
             Usermessage("Girdiler tablosunda eksik giriş var!");
         else
             if(!getadjustedinputsresult)
                 Usermessage("Ayarlanmış girdiler tablosunda eksik giriş var!");
             else
                 if(!getconstantsresult)
                    Usermessage("Sabitler tablosunda eksik giriş var");
                 else
                    Usermessage("Bilinmeyen hata!");
     }
     free(MyInputs);
     free(MyAdjustedInputs);
     free(MyOutputs);
     free(MyConstants);
}

void MainWindow::on_actionKaydet_triggered()
{
    QString myfile;
    QByteArray myba;
    FILE * savefile;
    Inputs * MyInputs;
    AdjustedInputs * MyAdjustedInputs;
    Constants * MyConstants;
    Outputs * MyOutputs;

    MyInputs = (Inputs*)malloc(sizeof(Inputs));
    MyAdjustedInputs= (AdjustedInputs*)malloc(sizeof(AdjustedInputs));
    MyConstants = (Constants*)malloc(sizeof(Constants));
    MyOutputs = (Outputs*)malloc(sizeof(Outputs));

    myfile=QFileDialog::getSaveFileName(this,"Dosya Adı","C:\\","*.aku");
    myba=myfile.toLocal8Bit();
    savefile=fopen(myba.data(),"wb");

    GetInputs(MyInputs);
    GetAdjustedInputs(MyAdjustedInputs);
    GetConstants(MyConstants);
    GetOutputs(MyOutputs);

    fwrite(MyInputs,sizeof(Inputs),1,savefile);
    fwrite(MyAdjustedInputs,sizeof(AdjustedInputs),1,savefile);
    fwrite(MyConstants,sizeof(Constants),1,savefile);
    fwrite(MyOutputs,sizeof(Outputs),1,savefile);

    fclose(savefile);

    free(MyInputs);
    free(MyAdjustedInputs);
    free(MyConstants);
    free(MyOutputs);
}

void MainWindow::on_actionOpen_triggered()
{
    QString myfile;
    QByteArray myba;
    FILE * loadfile;
    Inputs * MyInputs;
    AdjustedInputs * MyAdjustedInputs;
    Constants * MyConstants;
    Outputs * MyOutputs;

    MyInputs = (Inputs*)malloc(sizeof(Inputs));
    MyAdjustedInputs= (AdjustedInputs*)malloc(sizeof(AdjustedInputs));
    MyConstants = (Constants*)malloc(sizeof(Constants));
    MyOutputs = (Outputs*)malloc(sizeof(Outputs));
    myfile = QFileDialog::getOpenFileName(this,"Dosya Adı","C:\\","*.aku");
    myba = myfile.toLocal8Bit();

    loadfile = fopen(myba.data(),"rb");

    fread(MyInputs,sizeof(Inputs),1,loadfile);
    fread(MyAdjustedInputs,sizeof(AdjustedInputs),1,loadfile);
    fread(MyConstants,sizeof(Constants),1,loadfile);
    fread(MyOutputs,sizeof(Outputs),1,loadfile);

    PutInputs(MyInputs);
    PutAdjustedInputs(MyAdjustedInputs);
    PutConstants(MyConstants);
    PutOutputs(MyOutputs);

    fclose(loadfile);

    free(MyInputs);
    free(MyAdjustedInputs);
    free(MyConstants);
    free(MyOutputs);
}
