#ifndef MORSETRANSLATER_H
#define MORSETRANSLATER_H
/* Morse Translater class - header file
 * Created by: Grigoryan A. S. date: 04.05.2018
 *
 * For barbatum
 */

#include <QObject>
#include <QMap>
#include <QList>
#include <QStringList>
class MorseTranslater : public QObject
{
    Q_OBJECT
public:
    explicit MorseTranslater(QObject *parent = 0);
    ~MorseTranslater();

    QString codeToMorse(QStringList wordLst);   //translate to the Morse code
    QString decodeFromMorse(QStringList wordLst);//translate from the Morse code

signals:

public slots:

private:
    QMap <QString, QString> MorseToABC;
    QMap <QString, QString> ABCtoMorse;



};

#endif // MORSETRANSLATER_H
