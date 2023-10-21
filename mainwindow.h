#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Use nullptr em vez de 0 para ponteiros
    ~MainWindow(); 

    static QMutex* getMutex(int index); // Método estático para acessar um mutex específico

public slots:
    void updateInterface(int,int,int); // Este slot é chamado quando o sinal é emitido
    //void handleEnteringRC(QString rcID, int trainID); // Slot para lidar com trens entrando em regiões críticas
    //void handleExitingRC(QString rcID, int trainID); // Slot para lidar com trens saindo de regiões críticas

private slots:   
    void on_SpeedT1_valueChanged(int value); 
    void on_SpeedT2_valueChanged(int value);
    void on_SpeedT3_valueChanged(int value);
    void on_SpeedT4_valueChanged(int value);
    void on_SpeedT5_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    // Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

    static QMutex mutexesRC[7]; // Array de mutexes para as regiões críticas
};

#endif // MAINWINDOW_H
