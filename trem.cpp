#include "trem.h"
#include "mainwindow.h"
#include <QtCore>
#include <QSemaphore>
#include <QThread>

QMutex Trem::mutexesRC[7]; 



//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::setVelocidade(int velocidade) {
    if (velocidade >= 0 && velocidade <= 200){} // garante que a velocidade esteja dentro de um intervalo aceitável
        this->velocidade = velocidade;
}


//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (this->ID == 1) {
            if (x == 440 && y == 50) { // pouco antes da RC0
                MainWindow::getMutex(0)->lock(); // RC0 está associada ao mutex 0
            } else if (x == 330 && y == 170) { // pouco antes da RC1
                MainWindow::getMutex(1)->lock(); // RC1 está associada ao mutex 1
            } else if (x == 460 && y == 150) { // pouco antes da RC2
                MainWindow::getMutex(2)->lock(); // RC2 está associada ao mutex 2
            }
        }
        // Trem 2
        else if (this->ID == 2) {
            if (x == 480 && y == 170) { // pouco antes da RC0
                MainWindow::getMutex(0)->lock(); // RC0 está associada ao mutex 0
            } else if (x == 600 && y == 170) { // pouco antes da RC3
                MainWindow::getMutex(3)->lock(); // RC3 está associada ao mutex 3
            } else if (x == 730 && y == 150) { // pouco antes da RC4
                MainWindow::getMutex(4)->lock(); // RC4 está associada ao mutex 4
            }
        }

         // Trem 3
        else if (this->ID == 3) {
            if (x == 160 && y == 170) { // pouco antes da RC1
                MainWindow::getMutex(1)->lock(); // RC3 está associada ao mutex 3
            } else if (x == 290 && y == 170) { // pouco antes da RC5
                MainWindow::getMutex(5)->lock(); // RC5 está associada ao mutex 5
            }
        }

        switch(ID){
         case 1: 
                if (y == 50 && x < 460)
                    x+=10;
                else if (x == 460 && y < 170)
                    y+=10;
                else if (x > 190 && y == 170)
                    x-=10;
                else
                    y-=10;
                break;
            case 2:
                if (y == 50 && x < 730) 
                    x+=10;
                else if (x == 730 && y < 170)
                    y+=10;
                else if (x > 460 && y == 170)
                    x-=10;
                else
                    y-=10;
                break;
          case 3: //Trem 3
                if (x < 310 && y == 170) // Se y é 170 e x é menos que 310, move para a direita
                    x+=10;
                else if (x == 310 && y < 290) // Se x é 310 e y é menos que 290, move para baixo
                    y+=10;
                else if (x > 40 && y == 290) // Se y é 290 e x é mais que 40, move para a esquerda
                    x-=10;
                else if (x == 40 && y > 170) // Se x é 40 e y é mais que 170, move para cima
                    y-=10;
                break;
        case 4: //Trem 4
            if (x < 580 && y == 170) // Se y é 170 e x é menos que 580, move para a direita
                x+=10;
            else if (x == 580 && y < 290) // Se x é 580 e y é menos que 290, move para baixo
                y+=10;
            else if (x > 310 && y == 290) // Se y é 290 e x é mais que 310, move para a esquerda
                x-=10;
            else if (x == 310 && y > 170) // Se x é 310 e y é mais que 170, move para cima
                y-=10;
            emit updateGUI(ID, x, y);    // Emite um sinal
            break;
            case 5: //Trem 5
            if (x < 850 && y == 170) // Se y é 170 e x é menos que 850, move para a direita
                x+=10;
            else if (x == 850 && y < 290) // Se x é 850 e y é menos que 290, move para baixo
                y+=10;
            else if (x > 580 && y == 290) // Se y é 290 e x é mais que 580, move para a esquerda
                x-=10;
            else if (x == 580 && y > 170) // Se x é 580 e y é mais que 170, move para cima
                y-=10;
            emit updateGUI(ID, x, y);    // Emite um sinal
            break;
        default:
            break;
        }

         // Liberação do mutex após a região crítica
        // Trem 1
        if (this->ID == 1) {
            if (x == 440 && y == 170) { // logo após a RC0
                MainWindow::getMutex(0)->unlock();
            } else if (x == 190 && y == 150) { // logo após a RC1
                MainWindow::getMutex(1)->unlock();
            } else if (x == 310 && y == 170) { // logo após a RC2
                MainWindow::getMutex(2)->unlock();
            }
        }
        // Trem 2
        else if (this->ID == 2) {
            if (x == 480 && y == 50) { // logo após a RC0
                MainWindow::getMutex(0)->unlock();
            } else if (x == 460 && y == 150) { // logo após a RC3
                MainWindow::getMutex(3)->unlock();
            } else if (x == 580 && y == 170) { // logo após a RC4
                MainWindow::getMutex(4)->unlock();
            }
        } 

         // Trem 3
        else if (this->ID == 3) {
            if (x == 310 && y == 190) { // logo após a RC1
                MainWindow::getMutex(1)->unlock();
            } else if (x == 290 && y == 290) { // logo após a RC5
                MainWindow::getMutex(5)->unlock();
            }
        }

        emit updateGUI(ID, x, y); // Atualização da GUI
        //msleep(velocidade);
        if(velocidade == 0) {
            while(velocidade == 0) {
                msleep(100); // Se a velocidade for 0, o trem deve parar, então a thread dorme em um loop até que a velocidade mude
            }
        } else {
            int sleepTime = 200 - velocidade; // A pausa é inversamente proporcional à velocidade, com 200 sendo a menor pausa
            msleep(sleepTime > 0 ? sleepTime : 1); // Garante que o tempo de sono não seja zero ou negativo
        }
    }
}


