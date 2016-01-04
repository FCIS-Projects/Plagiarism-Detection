#ifndef SEARCH_USING_REGEX_H
#define SEARCH_USING_REGEX_H

#include <QString>
#include <QFile>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QChar>

class Search_Using_RegEx
{
private:
    QVector<QString>* comments;
    QVector<QString>* reset;

    QString *regular_expression;
    QFile *file;
    QString *_string;
    // take a file has c++ code
    // build the regular expressions machine
    //
public:
    // TODO: RegEx for ( for, while, functions, ... )
    Search_Using_RegEx();
    Search_Using_RegEx( QString *regular_expression, QString *str );
    Search_Using_RegEx( QString *regular_expression, QFile *file );
    void search( QString *regular_expression, QString *str );
    void search( QString *regular_expression, QFile *file );

private:
    void prepare();
};

#endif // SEARCH_USING_REGEX_H
