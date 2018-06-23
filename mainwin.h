#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QMap>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>

#include "morsetranslater.h"

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private slots:
    void on_buttonOpenFile_clicked();
    void on_buttonSaveFile_clicked();

    void on_textEdit_textChanged();

    void on_CodeDecodebutton_clicked();

    void on_rbMorse_clicked();

    void on_rbEnglish_clicked();

    void on_rbMorse_Out_clicked();

    void on_rbEnglish_Out_clicked();

   // void on_buttonClear_clicked();

private:
    Ui::MainWin *ui;
    MorseTranslater morseTranslater;


    void codeDecodeText();
};

#endif // MAINWIN_H
