#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trem.h"
#include <QSemaphore>
#include <QThread>
#include <stdexcept>

QMutex MainWindow::mutexesRC[7];  // Inicializando o array de mutexes

QMutex* MainWindow::getMutex(int index) {
    if (index >= 0 && index < 7) {
        return &mutexesRC[index];
    }
    return nullptr; // ou gerencie de outra forma o erro
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   
    // Cria os trens com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,190,50);
    trem2 = new Trem(2,460,50);
    trem3 = new Trem(3,40,170);
    trem4 = new Trem(4,310,170);
    trem5 = new Trem(5,580,170);

    // Conecta os sinais
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    //Conecta os sliders
    connect(ui->SpeedT1, SIGNAL(valueChanged(int)), this, SLOT(on_SpeedT1_valueChanged(int)));
    connect(ui->SpeedT2, SIGNAL(valueChanged(int)), this, SLOT(on_SpeedT2_valueChanged(int)));
    connect(ui->SpeedT3, SIGNAL(valueChanged(int)), this, SLOT(on_SpeedT3_valueChanged(int)));
    connect(ui->SpeedT4, SIGNAL(valueChanged(int)), this, SLOT(on_SpeedT4_valueChanged(int)));
    connect(ui->SpeedT5, SIGNAL(valueChanged(int)), this, SLOT(on_SpeedT5_valueChanged(int)));

    // Iniciar trens
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui; //limpa a UI
}

void MainWindow::on_SpeedT1_valueChanged(int value)
{
    trem1->setVelocidade(value); // O valor agora é diretamente proporcional à velocidade
}

void MainWindow::on_SpeedT2_valueChanged(int value)
{
    trem2->setVelocidade(value); // O valor agora é diretamente proporcional à velocidade
}

void MainWindow::on_SpeedT3_valueChanged(int value)
{
    trem3->setVelocidade(value); // O valor agora é diretamente proporcional à velocidade
}

void MainWindow::on_SpeedT4_valueChanged(int value)
{
    trem4->setVelocidade(value); // O valor agora é diretamente proporcional à velocidade
}

void MainWindow::on_SpeedT5_valueChanged(int value)
{
    trem5->setVelocidade(value); // O valor agora é diretamente proporcional à velocidade
}
