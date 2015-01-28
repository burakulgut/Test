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
    float PositivePlateWidth;
    float NegativePlateWeight;
    float NegativePlateWidth;
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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
