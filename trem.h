#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex> 



class Trem: public QThread{
 Q_OBJECT
 
 static QMutex mutexesRC[7];

public:
    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread
    void setVelocidade(int velocidade);

//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
