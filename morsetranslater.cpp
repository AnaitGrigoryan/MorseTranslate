#include "morsetranslater.h"

/* Morse Translater class
 * Created by: Grigoryan A. S. date: 04.05.2018
 *
 * For barbatum
 */
MorseTranslater::MorseTranslater(QObject *parent) :
    QObject(parent)
{

    MorseToABC[".-"]    = "a";
    MorseToABC["-..."]  = "b";
    MorseToABC["-.-."]  = "c";
    MorseToABC["-.."]   = "d";
    MorseToABC["."]     = "e";

    MorseToABC["..-."]  = "f";
    MorseToABC["--."]   = "g";
    MorseToABC["...."]  = "h";
    MorseToABC[".."]    = "i";
    MorseToABC[".---"]  = "j";

    MorseToABC["-.-"]   = "k";
    MorseToABC[".-.."]  = "l";
    MorseToABC["--"]    = "m";
    MorseToABC["-."]    = "n";
    MorseToABC["---"]   = "o";

    MorseToABC[".--."]  = "p";
    MorseToABC["--.-"]  = "q";
    MorseToABC[".-."]   = "r";
    MorseToABC["..."]   = "s";
    MorseToABC["-"]     = "t";

    MorseToABC["..-"]   = "u";
    MorseToABC["...-"]  = "v";
    MorseToABC[".--"]   = "w";
    MorseToABC["-..-"]  = "x";
    MorseToABC["-.--"]  = "y";

    MorseToABC["--.."]  = "z";
    MorseToABC[".-.-.-"]= ".";
    MorseToABC["--..--"]= ",";

    QMap<QString, QString>::iterator it = MorseToABC.begin();
    for (;it != MorseToABC.end(); ++it)
    {
        QString cod = it.key();
        QString value = it.value();
        ABCtoMorse[value] = cod;
    }
}

MorseTranslater::~MorseTranslater()
{

}

/* Function that code the list of words into the Morse code
 * Return the text of joined words
 */
QString MorseTranslater::codeToMorse(QStringList wordLst)
{
    QStringList codeLst;
    if(wordLst.isEmpty())
        return "";

    codeLst.clear();
    for(int i=0; i<wordLst.size(); i++)
    {
        QString word = wordLst.at(i).toLower();
        QString codeWord;
        for(int j=0; j < word.size(); j++)
        {
            QString letter(word.at(j));

            QString temp;
            temp = ABCtoMorse[letter];
            if(temp != "")
                codeWord +=  temp + " ";
        }
        codeLst.append(codeWord);
    }

    return codeLst.join("  ");
}

/* Function that decode the list of words from the Morse code
 * Return the text of joined words
 */
QString MorseTranslater::decodeFromMorse(QStringList wordLst)
{
    QStringList codeLst;
    if(wordLst.isEmpty())
        return "";

    codeLst.clear();
    for(int i=0; i<wordLst.size(); i++)
    {
        QString word = wordLst.at(i);
        QString codeWord;
        QStringList letterLst = word.split(QRegExp(" "), QString::SkipEmptyParts);
        for(int j=0; j < letterLst.size(); j++)
        {
            QString temp;
            temp = MorseToABC[letterLst.at(j)];
            if(temp != "")
                codeWord +=  temp;
        }
        codeLst.append(codeWord);
    }

    return codeLst.join(" ");
}
