#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct Inputs
{
    short Capacity;
    short CCA;
    short NofPositivePlates;
    short NofNegativePlates;
    float NegativePaste;
    float PositivePaste;
    wchar_t PositivePlateCode[10];
    wchar_t NegativePlateCode[10];
    float SeparatorThickness;
    float SeparatorWidth;
    short DrNAcidVolume;
    short Plateheight;
    wchar_t BoxType[10];
};

struct AdjustedInputs
{
    float AdjustedPositivePlates;
    float AdjustedNegativePlates;
    float Positivegridweight;
    float Positivegridthickness;
    float Negativegridweight;
    float Negativegridthickness;
    float UsefulCellWidth;
};

struct Outputs
{
    float PAMNAMRatio;
    float PositiveAhperg;
    float NegativeAhperg;
    float CellSetWidth;
    float CompressionThickness;
    float AcidperActiveMass;
    float ProdTreeAcidAmount;
    float TotalLeadAmount;
    float TotalSeparatorAmount;

};

struct Constants
{
    float BaseAhperkg;
    float CCAperPlate;
    float Margin;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionRaporla_triggered();

    bool GetInputs(Inputs * TempInputs);
    bool GetAdjustedInputs(AdjustedInputs * TempAdjustedInputs);
    bool GetConstants(Constants * TempConstants);
    bool GetOutputs(Outputs * TempOutputs);
    bool PutAdjustedInputs(AdjustedInputs * TempAdjustedInputs);
    bool PutOutputs(Outputs* TempOutputs);
    bool PutConstants(Constants* TempConstants);
    bool PutInputs(Inputs* TempInputs);

    void Usermessage(const char * mystr);
    void Usermessage(const char* mystr,const QColor mycolor);

    void on_CalcAdjustedInputsButton_clicked();

    void on_InputTable_doubleClicked(const QModelIndex &index);

    void on_CalcOutputsButton_clicked();

    void on_actionKaydet_triggered();

    void on_actionOpen_triggered();

    void on_InputTable_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
