#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->InputTable->setColumnWidth(0,60);
    ui->InputTable->setColumnWidth(1,60);
    ui->InputTable->setGeometry(0,0,225,425);

    ui->AdjustedInputTable->setColumnWidth(0,60);
    ui->AdjustedInputTable->setColumnWidth(1,60);
    ui->AdjustedInputTable->setGeometry(ui->AdjustedInputTable->x(),ui->AdjustedInputTable->y(),240,ui->AdjustedInputTable->height());

    ui->OutputTable->setColumnWidth(0,60);
    ui->OutputTable->setColumnWidth(1,60);
    ui->OutputTable->setGeometry(ui->OutputTable->x(),ui->OutputTable->y(),260,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Usermessage(const char* mystr){

    QFont myFont;
    myFont.setPointSize(16);
    QPalette pal;
    pal.setColor(QPalette::Foreground,Qt::blue);
    ui->MessageLabel->setFont(myFont);
    ui->MessageLabel->setPalette(pal);
    ui->MessageLabel->setText(QString(mystr));

}

void MainWindow::Usermessage(const char* mystr,const QColor mycolor){

    QFont myFont;
    myFont.setPointSize(16);
    QPalette pal;
    pal.setColor(QPalette::Foreground,mycolor);
    ui->MessageLabel->setFont(myFont);
    ui->MessageLabel->setPalette(pal);
    ui->MessageLabel->setText(QString(mystr));

}

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
    myitem = ui->InputTable->item(11,0);
    if (myitem == 0)
    {
        result=0;
        TempInputs->Plateheight = 0;
    }
    else
    {
        TempInputs->Plateheight = myitem->text().toShort();
    }
    myitem = ui->InputTable->item(12,0);
    if (myitem == 0)
    {
        result=0;
    }
    else
    {
        myitem->text().toWCharArray(TempInputs->BoxType);
    }
    if(TempInputs->Capacity == 0 ||
            TempInputs->CCA==0 ||
            TempInputs->DrNAcidVolume==0 ||
            TempInputs->NegativePaste==0.0 ||
            TempInputs->NofNegativePlates==0 ||
            TempInputs->NofPositivePlates==0 ||
            TempInputs->PositivePaste==0.0 ||
            TempInputs->SeparatorThickness==0||
            TempInputs->Plateheight==0 ||
            TempInputs->BoxType == 0)
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
        TempAdjustedInputs->Positivegridweight = 0;
    }
    else
    {
        TempAdjustedInputs->Positivegridweight = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(3,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->Positivegridthickness = 0;
    }
    else
    {
        TempAdjustedInputs->Positivegridthickness = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(4,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->Negativegridweight = 0;
    }
    else
    {
        TempAdjustedInputs->Negativegridweight = myitem->text().toFloat();
    }

    myitem = ui->AdjustedInputTable->item(5,0);
    if (myitem == 0)
    {
        result=0;
        TempAdjustedInputs->Negativegridthickness = 0;
    }
    else
    {
        TempAdjustedInputs->Negativegridthickness = myitem->text().toFloat();
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
    sprintf(mystr,"%2.2f",TempAdjustedInputs->Positivegridweight);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(2,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%1.2f",TempAdjustedInputs->Positivegridthickness);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(3,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%2.2f",TempAdjustedInputs->Negativegridweight);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(4,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%1.2f",TempAdjustedInputs->Negativegridthickness);
    myItem->setText(QString(mystr));
    ui->AdjustedInputTable->setItem(5,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%2.1f",TempAdjustedInputs->UsefulCellWidth);
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
    sprintf(mystr,"%3.0f",TempOutputs->ProdTreeAcidAmount);
    myItem->setText(QString(mystr));
    ui->OutputTable->setItem(6,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0f",TempOutputs->TotalLeadAmount);
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
    sprintf(mystr,"%3.0f",TempConstants->BaseAhperkg);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(0,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0f",TempConstants->CCAperPlate);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(1,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0f",TempConstants->Margin);
    myItem->setText(QString(mystr));
    ui->ConstantsTable->setItem(2,0,myItem);

    return (bool)1;
}

bool MainWindow::PutInputs(Inputs* TempInputs)
{
    QTableWidgetItem *myItem;
    char mystr[10];

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%d",TempInputs->Capacity);
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

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%3.0d",TempInputs->Plateheight);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(11,0,myItem);

    myItem = new QTableWidgetItem;
    sprintf(mystr,"%ls",TempInputs->BoxType);
    myItem->setText(QString(mystr));
    ui->InputTable->setItem(12,0,myItem);
    return(bool)1;
}

void MainWindow::on_actionRaporla_triggered()
{
    FILE * rapor;
    QByteArray myba;
    int i;
    QString csvstring1,csvstring2,myfile;
    csvstring1="";
    csvstring2="";

    myfile=QFileDialog::getSaveFileName(this,"Rapor Adı","C:\\","*.csv");
    myba=myfile.toLocal8Bit();


    rapor=fopen(myba.constData(),"w");
    for(i=0;i<ui->InputTable->rowCount();i++)
    {
        csvstring1+= "\""+ui->InputTable->verticalHeaderItem(i)->text()+"\";";
        csvstring2+= ui->InputTable->item(i,0)->text()+";";
    }
    for(i=0;i<ui->AdjustedInputTable->rowCount();i++)
    {
        csvstring1+= "\""+ui->AdjustedInputTable->verticalHeaderItem(i)->text()+"\";";
        csvstring2+= ui->AdjustedInputTable->item(i,0)->text()+";";
    }
    for(i=0;i<ui->ConstantsTable->rowCount();i++)
    {
        csvstring1+= "\""+ui->ConstantsTable->verticalHeaderItem(i)->text()+"\";";
        csvstring2+= ui->ConstantsTable->item(i,0)->text()+";";
    }
    for(i=0;i<ui->OutputTable->rowCount();i++)
    {
        csvstring1+= "\""+ui->OutputTable->verticalHeaderItem(i)->text()+"\";";
        csvstring2+= ui->OutputTable->item(i,0)->text()+";";
    }
    csvstring1+="\n";
    csvstring2+="\n";
    csvstring1.replace(".",",");
    csvstring2.replace(".",",");
    myba=csvstring1.toLocal8Bit();
    fwrite(myba.constData(),csvstring1.length(),1,rapor);
    myba=csvstring2.toLocal8Bit();
    fwrite(myba.constData(),csvstring2.length(),1,rapor);

    fclose(rapor);
    Usermessage("Rapor kaydedildi.");
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
       MyAdjustedInputs->Negativegridweight = 0.0;
       MyAdjustedInputs->Negativegridthickness=0.0;
       MyAdjustedInputs->Positivegridweight = 0.0;
       MyAdjustedInputs->Positivegridthickness=0.0;
       MyAdjustedInputs->UsefulCellWidth=0.0;

       putadjustedinputsresult=PutAdjustedInputs(MyAdjustedInputs);
    }


    if(getinputsresult && putadjustedinputsresult)
        Usermessage("Ayarlanmış girdiler tablosu güncellendi!");
    else
        Usermessage("Eksik giriş. Lütfen kontrol edin!",Qt::red);
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
     MyOutputs->CellSetWidth = MyInputs->NofPositivePlates*MyAdjustedInputs->Positivegridthickness+MyInputs->NofNegativePlates*MyAdjustedInputs->Negativegridthickness+2*MyInputs->NofNegativePlates*MyInputs->SeparatorThickness;
     MyOutputs->CompressionThickness = MyAdjustedInputs->UsefulCellWidth - MyOutputs->CellSetWidth;
     MyOutputs->AcidperActiveMass = MyInputs->DrNAcidVolume/(MyInputs->NofPositivePlates*MyInputs->PositivePaste+MyInputs->NofNegativePlates*MyInputs->NegativePaste);
     MyOutputs->ProdTreeAcidAmount= MyInputs->DrNAcidVolume*0.3795*1.285*6;
     MyOutputs->TotalLeadAmount= 6*(MyInputs->NofPositivePlates*MyAdjustedInputs->Positivegridweight + MyInputs->NofNegativePlates*MyAdjustedInputs->Negativegridweight+0.9*MyInputs->PositivePaste*MyInputs->NofPositivePlates+0.9*MyInputs->NegativePaste*MyInputs->NofNegativePlates);
     MyOutputs->TotalSeparatorAmount = (MyInputs->Plateheight+8)*MyInputs->SeparatorThickness*MyInputs->NofPositivePlates*12;

     putoutputsresult = PutOutputs(MyOutputs);

     if(getinputsresult&&getadjustedinputsresult&&putoutputsresult&&getconstantsresult)
         Usermessage("Çıktılar tablosu güncellendi");
     else
     {
         if(!getinputsresult)
             Usermessage("Girdiler tablosunda eksik giriş var!",Qt::red);
         else
             if(!getadjustedinputsresult)
                 Usermessage("Ayarlanmış girdiler tablosunda eksik giriş var!",Qt::red);
             else
                 if(!getconstantsresult)
                    Usermessage("Sabitler tablosunda eksik giriş var",Qt::red);
                 else
                    Usermessage("Bilinmeyen hata!",Qt::green);
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
    Usermessage("Dosya kaydedildi.");
}

void MainWindow::on_actionOpen_triggered()
{
    QString myfile;
    FILE * loadfile;
    Inputs * MyInputs;
    char mystr[250];

    AdjustedInputs * MyAdjustedInputs;
    Constants * MyConstants;
    Outputs * MyOutputs;

    MyInputs = (Inputs*)malloc(sizeof(Inputs));
    MyAdjustedInputs= (AdjustedInputs*)malloc(sizeof(AdjustedInputs));
    MyConstants = (Constants*)malloc(sizeof(Constants));
    MyOutputs = (Outputs*)malloc(sizeof(Outputs));
    myfile = QFileDialog::getOpenFileName(this,"Dosya Adı","C:\\","*.aku");
    QByteArray myba = myfile.toLocal8Bit();
    const char *filename=myba.constData();
    loadfile = fopen(filename,"rb");

    fread(MyInputs,sizeof(Inputs),1,loadfile);
    fread(MyAdjustedInputs,sizeof(AdjustedInputs),1,loadfile);
    fread(MyConstants,sizeof(Constants),1,loadfile);
    fread(MyOutputs,sizeof(Outputs),1,loadfile);

    PutInputs(MyInputs);
    PutAdjustedInputs(MyAdjustedInputs);
    PutConstants(MyConstants);
    PutOutputs(MyOutputs);
    this->setWindowTitle("Akü Tasarım -- "+myfile);
    fclose(loadfile);

    free(MyInputs);
    free(MyAdjustedInputs);
    free(MyConstants);
    free(MyOutputs);
    sprintf(mystr,"%s dosyası yüklendi.",filename);
    Usermessage(mystr);
}

void MainWindow::on_InputTable_cellChanged(int row, int column)
{
    FILE * ProgInputFile;
    char PlateString[200];
    char PlateRef[50];
    float gridthickness=0.0;
    float gridweight=0.0;
    float gridheight=0.0;
    float plateweight=0.0;
    QString InputQString;
    QByteArray InputByteArray;
    QTableWidgetItem *tableitem;
    float Npositive,Nnegative;
    char BoxString[100];
    char BoxName[100];
    float Usefulwidth = 0;

    // plate codes
    if(column==0 && (row ==6 || row ==7))
    {
        ProgInputFile=fopen("C:\\Users\\bulgut\\Desktop\\Inci\\Projeler\\Software\\Test\\Test\\Plaka_ProgramInput.txt","r");
        if (ProgInputFile == NULL)
        {
            Usermessage("Plaka bilgileri dosyasına ulaşılamıyor.",Qt::darkRed);
            return;
        }
        while(!feof(ProgInputFile)){
            fgets(PlateString,45,ProgInputFile);
            sscanf(PlateString,"%s\t%f\t%f\t%f\t%f",PlateRef,&gridthickness,&gridweight,&gridheight,&plateweight);
            InputQString= ui->InputTable->item(row,column)->text();
            InputByteArray=InputQString.toLocal8Bit();

            if(strstr(PlateRef,InputByteArray.constData())!=NULL)
            {
                tableitem = new QTableWidgetItem;
                tableitem->setText(QString::number(gridheight));
                ui->InputTable->setItem(11,0,tableitem);
                if(row==6)
                {
                    tableitem = new QTableWidgetItem;
                    tableitem->setText(QString::number(gridweight));
                    ui->AdjustedInputTable->setItem(2,0,tableitem);
                    tableitem = new QTableWidgetItem;
                    tableitem->setText(QString::number(gridthickness));
                    ui->AdjustedInputTable->setItem(3,0,tableitem);
                    break;
                }
                else
                {
                    tableitem = new QTableWidgetItem;
                    tableitem->setText(QString::number(gridweight));
                    ui->AdjustedInputTable->setItem(4,0,tableitem);
                    tableitem = new QTableWidgetItem;
                    tableitem->setText(QString::number(gridthickness));
                    ui->AdjustedInputTable->setItem(5,0,tableitem);
                    break;
                }
            }
        }
        if(feof(ProgInputFile))
        {
            if(row==6)
            {
                tableitem = new QTableWidgetItem;
                tableitem->setText("");
                ui->AdjustedInputTable->setItem(2,0,tableitem);
                tableitem = new QTableWidgetItem;
                tableitem->setText("");
                ui->AdjustedInputTable->setItem(3,0,tableitem);
                Usermessage("Bilinmeyen pozitif plaka kodu",Qt::red);
            }
            else
            {
                tableitem = new QTableWidgetItem;
                tableitem->setText("");
                ui->AdjustedInputTable->setItem(4,0,tableitem);
                tableitem = new QTableWidgetItem;
                tableitem->setText("");
                ui->AdjustedInputTable->setItem(5,0,tableitem);
                Usermessage("Bilinmeyen negatif plaka kodu",Qt::red);
            }
        }
        fclose(ProgInputFile);
    }
    // # of plates
    if(column == 0 && (row ==2 || row ==3))
    {
         if (!(ui->InputTable->item(2,0)== NULL ||ui->InputTable->item(3,0)== NULL))
         {
             Npositive=ui->InputTable->item(2,0)->text().toInt();
             Nnegative=ui->InputTable->item(3,0)->text().toInt();
             if (Npositive==Nnegative)
                 Npositive=Nnegative=Npositive-0.2;
             else
                 (Npositive>Nnegative)? Npositive-=0.4 : Nnegative=-0.4;
             tableitem = new QTableWidgetItem;
             tableitem->setText(QString::number(Npositive));
             ui->AdjustedInputTable->setItem(0,0,tableitem);
             tableitem = new QTableWidgetItem;
             tableitem->setText(QString::number(Nnegative));
             ui->AdjustedInputTable->setItem(1,0,tableitem);
         }
    }
    if(column == 0 && row ==12)
    {
        ProgInputFile = fopen("C:\\Users\\bulgut\\Desktop\\Inci\\Projeler\\Software\\Test\\Test\\Kutu_ProgramInput.txt","r");
        if (ProgInputFile == NULL)
        {
            Usermessage("Kutu bilgileri dosyasına ulaşılamıyor.",Qt::darkRed);
            return;
        }
        InputQString= ui->InputTable->item(12,0)->text();
        InputByteArray=InputQString.toLocal8Bit();

        while(!feof(ProgInputFile))
        {
            fgets(BoxString,45,ProgInputFile);
            sscanf(BoxString,"%s\t%f",BoxName,&Usefulwidth);

            if(strstr(BoxString,InputByteArray.constData())!=NULL)
            {
                tableitem = new QTableWidgetItem;
                tableitem->setText(QString::number(Usefulwidth));
                ui->AdjustedInputTable->setItem(6,0,tableitem);
                break;
            }

        }
        if(feof(ProgInputFile))
        {
            Usermessage("Bilinmeyen kutu kodu.",Qt::red);
        }
        fclose(ProgInputFile);
    }

}

void MainWindow::on_BoxTypeCombo_currentIndexChanged(int index)
{
    FILE * ProgInputFile;
    char BoxString[100];
    char BoxName[100];
    float Usefulwidth = 0;
    QString InputQString;
    QByteArray InputByteArray;
    QTableWidgetItem *tableitem;

    ProgInputFile = fopen("C:\\Users\\bulgut\\Desktop\\Inci\\Projeler\\Software\\Test\\Test\\Kutu_ProgramInput.txt","r");
    if (ProgInputFile == NULL)
    {
        Usermessage("Kutu bilgileri dosyasına ulaşılamıyor.",Qt::darkRed);
        return;
    }
    InputQString= ui->BoxTypeCombo->itemText(index);
    InputByteArray=InputQString.toLocal8Bit();

    while(!feof(ProgInputFile))
    {
        fgets(BoxString,45,ProgInputFile);
        sscanf(BoxString,"%s\t%f",BoxName,&Usefulwidth);

        if(strstr(BoxString,InputByteArray.constData())!=NULL)
        {
            tableitem = new QTableWidgetItem;
            tableitem->setText(QString::number(Usefulwidth));
            ui->AdjustedInputTable->setItem(6,0,tableitem);
            break;
        }

    }
    if(feof(ProgInputFile))
    {
        Usermessage("Bilinmeyen kutu kodu.",Qt::red);
    }
    fclose(ProgInputFile);
}
