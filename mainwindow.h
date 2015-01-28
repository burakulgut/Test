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
    short SeparatorThickness;
    short SeparatorWidth;
    short DrNAcidVolume;
};

struct AdjustedInputs
{
    float AdjustedPositivePlates;
    float AdjustedNegativePlates;
    float PositivePlateWeight;
    float PositivePlateThickness;
    float NegativePlateWeight;
    float NegativePlateThickness;
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
    void on_actionHesapla_triggered();

    void on_actionRaporla_triggered();

    bool GetInputs(Inputs * TempInputs);
    bool GetAdjustedInputs(AdjustedInputs * TempAdjustedInputs);
    bool GetConstants(Constants * TempConstants);
    bool GetOutputs(Outputs * TempOutputs);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
