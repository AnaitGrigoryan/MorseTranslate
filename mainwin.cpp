#include "mainwin.h"
#include "ui_mainwin.h"
/* Morse Translater application
 * Created by: Grigoryan A. S. date: 04.05.2018
 *
 * For barbatum
 *
 *
 */
MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);

    //Initially the result window and the save button are disabled
    ui->CodeText->setDisabled(true);
    ui->buttonSaveFile->setDisabled(true);
}

MainWin::~MainWin()
{
    delete ui;
}

//Download the text from the file
void MainWin::on_buttonOpenFile_clicked()
{
    QString FilePath = "./";
    QDir dir;
    FilePath = dir.currentPath();

    QString open_file = QFileDialog::getOpenFileName(this,"Select file",FilePath,"*.txt");

    if(open_file != 0)
    {
        QFile file(open_file);

        if(!(file.exists()))
            return;

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        QStringList readText;
        while (!in.atEnd())
        {
            readText.append(in.readLine());
        }

        file.close();
        ui->textEdit->setPlainText(readText.join(""));
    }
}

//Save the text to the file
void MainWin::on_buttonSaveFile_clicked()
{
    QString FilePath = "./";
    QDir dir;
    FilePath = dir.currentPath();

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                              FilePath, "*.txt");

    if(fileName != "")
    {
        QFile file;
        fileName += ".txt";
        file.setFileName(fileName);
        file.open(QIODevice::ReadWrite);
        QTextStream out(&file);

        QString textForFile =  ui->CodeText->toPlainText();
        out << textForFile;

        file.close();
    }
}

//Processing of the text changing
void MainWin::on_textEdit_textChanged()
{
    QString text =  ui->textEdit->toPlainText();

    if(text.contains(QRegExp("[A-Z]", Qt::CaseInsensitive)))
    {
        ui->rbEnglish->setChecked(true);
        ui->rbMorse_Out->setChecked(true);
        codeDecodeText();
    }
    else
    {
        ui->rbMorse->setChecked(true);
        ui->rbEnglish_Out->setChecked(true);
        codeDecodeText();
    }
    if(text == "")
    {
        ui->CodeText->clear();
        ui->CodeText->setDisabled(true);
        ui->buttonSaveFile->setDisabled(true);
    }
    else
    {
        ui->buttonSaveFile->setEnabled(true);
    }

}

void MainWin::on_CodeDecodebutton_clicked()
{
    codeDecodeText();
}

//Function of automatic coding/decoding to/from Morse code
void MainWin::codeDecodeText()
{
    QString text = ui->textEdit->toPlainText();
    QStringList wordLst;
    QString result;
    if(ui->rbEnglish->isChecked())
    {//Code to
        wordLst      = text.split(QRegExp(" "), QString::SkipEmptyParts);
        if(wordLst.isEmpty())
            return;

        result = morseTranslater.codeToMorse(wordLst);
    }
    else
    {//Decode
        wordLst      = text.split(QRegExp("  "), QString::SkipEmptyParts);
        if(wordLst.isEmpty())
            return;

        result = morseTranslater.decodeFromMorse(wordLst);
    }
    ui->CodeText->setPlainText(result);
    bool state = (result != "") ? true:false;
    ui->CodeText->setEnabled(state);
}

void MainWin::on_rbMorse_clicked()
{
    ui->rbEnglish_Out->setChecked(true);
}

void MainWin::on_rbEnglish_clicked()
{
    ui->rbMorse_Out->setChecked(true);
}

void MainWin::on_rbMorse_Out_clicked()
{
    ui->rbEnglish->setChecked(true);
}

void MainWin::on_rbEnglish_Out_clicked()
{
   ui->rbMorse->setChecked(true);
}

