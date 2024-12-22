# Projeto: Controle de Trens com Regiões Críticas (colision_mutex_SO)

Este projeto é uma simulação de controle de trens utilizando threads e sincronização por meio de mutexes e semáforos. Foi desenvolvido com **Qt** e implementa regiões críticas para gerenciar acessos simultâneos de forma segura.

## Estrutura do Repositório

```
├── ATVD2.pro
├── ATVD2.pro.user
├── README.md
├── globals.h
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── trem.cpp
└── trem.h
```

## Funcionalidades

1. **Simulação de Trens**
   - Cada trem é representado por uma thread (`Trem`) e se move continuamente pela interface gráfica.
   - Controles individuais de velocidade para cada trem.

2. **Gerenciamento de Regiões Críticas**
   - Regiões críticas compartilhadas são protegidas por **QMutex**.
   - A sincronização garante exclusão mútua, prevenindo colisões.

3. **Interface Gráfica (GUI)**
   - Desenvolvida com **Qt Widgets**.
   - Visualização em tempo real da movimentação dos trens.
   - Controle de velocidade por meio de sliders.

## Como Executar

### Pré-requisitos
- **Qt Creator** (versão 6.6.0 ou superior).
- **Qt Framework** com suporte ao módulo Widgets.

### Passos
1. Clone o repositório:
   ```
   git clone <URL_DO_REPOSITORIO>
   cd <DIRETORIO_DO_REPOSITORIO>
   ```

2. Abra o arquivo `ATVD2.pro` no **Qt Creator**.

3. Compile e execute o projeto.

### Controles na Interface
- Use os sliders disponíveis para ajustar a velocidade de cada trem individualmente.

## Descrição dos Arquivos Principais

### `globals.h`
Declaração de variáveis globais:
```
extern QSemaphore semaforosRC[7]; // Semáforos usados nas regiões críticas.
```

### `main.cpp`
Arquivo de entrada principal da aplicação:
```
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
```

### `mainwindow.cpp` e `mainwindow.h`
Controlam a interface gráfica e gerenciam eventos:
- Conexão de sinais entre trens e interface.
- Atualização dinâmica das posições dos trens na GUI.

### `trem.cpp` e `trem.h`
Implementação das threads para cada trem:
- Lógica de movimentação contínua baseada em coordenadas.
- Bloqueio e desbloqueio de regiões críticas utilizando `QMutex`.

### `mainwindow.ui`
Definição da interface gráfica:
- Layout dos componentes da interface, como sliders e labels para visualização.

## Notas de Implementação

1. **Sincronização:**
   - Uso de mutexes para proteger regiões críticas compartilhadas por mais de um trem.
   - Acesso sequencial garantido para evitar condições de corrida e colisões.

2. **Ajuste de Velocidade:**
   - Velocidade ajustável dinamicamente pelos sliders da interface.
   - A pausa das threads é inversamente proporcional ao valor da velocidade configurada.

3. **Extensibilidade:**
   - O código pode ser adaptado para adicionar novos trens ou regiões críticas, desde que adequadamente configurados.

## Contribuição

1. Faça um fork do projeto.
2. Crie uma nova branch para a sua contribuição:
   ```
   git checkout -b minha-feature
   ```
3. Realize suas alterações e faça commit:
   ```
   git commit -m "Descrição das alterações realizadas"
   ```
4. Envie a branch para o repositório remoto:
   ```
   git push origin minha-feature
   ```
5. Abra um Pull Request no repositório principal.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
